#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <getopt.h>
#include <wchar.h>

#define max3(x, y, z) ( z > (((x) > (y)) ? (x) : (y)) ? z : (((x) > (y)) ? (x) : (y)) )

// Structs needed
static struct option long_options[] = {
        {"fasta",     required_argument, 0,  'i' },
        {"gapopen",   required_argument, 0,  'g' },
        {"gapext",    required_argument, 0,  'e' },
        {"out",   	  required_argument, 0,  'o' },
        {"match",     required_argument, 0,  'm' },
        {"mismatch",  required_argument, 0,  's' },
        {0,           0,                 0,   0  }
};

// Global variables
static char sequences[25][500];
static char names[25][50];
static int count = 0;
static char *fileName = "";
static char *outName = "";
static int gapPenalty = 0;
static int gapExtention = 0;
static int matchScore = 0;
static int mismatchScore = 0;
static char *output = "";
static FILE *outFile;

// Tree functions
struct node  { 
	char* name;
    double data; 
    struct node *left; 
    struct node *right; 
}; 
  
struct node* newNode(double data, char* name) { 
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  node->data = data; 
  node->name = name; 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 

struct node* findNode(struct node* all[625], int nodeCount, char* label) {
	for (int i = 0; i < nodeCount; i++) {
		if (strcmp(all[i]->name,label) == 0)
			return all[i];
	}
}	

double findTotal(struct node *root ) {
    if (root->left != NULL) {
        return root->left->data + findTotal(root->left);
    }
    else {
    	return 0;
    }
}

// Prints out the Newick tree format in post order traversal
void postOrder(struct node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        if (strlen(root->name) == 1) {
        	fprintf(outFile, "(%s:%.2f", root->name, root->data);
        }
        else {
        	fprintf(outFile, "):%.2f) ", root->data);
        }
    }
}

// Concats two given array
char* concat(const char *s1, const char *s2) {
    char *resun = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(resun, s1);
    strcat(resun, s2);
    return resun;
}

// Read sequences
void readFastaSequences() {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(fileName, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int state = 0;
	int i = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] != '>') {
			if (line[read - 1] == '\n')
				line[read - 1] = 0;
			char *ch = strtok(line, " ");
    		strcpy(sequences[i++], ch);
    		count++;
		}
		else {
			char *ch = strtok(line, ">");
			ch = strtok(ch, "\n");
			strcpy(names[i], ch);
		}
	}
	fclose(fp);
	if (line)
		free(line);
}

// Traverses direction array and produces alignment result
int traverseDirection(char *s1, char *s2, int *scoring, int *direction) {
	int row = strlen(s1)+1;
	int column = strlen(s2)+1;
    int r = row-1, c = column-1;
    int editDistance = 0;

	for(int i = r, j = c; i >= 0 && j >= 0;) {
		int dir = direction[i*column+j];
		if (dir==0) {
			if (s1[i-1] != s2[j-1])
				editDistance++;
			i--;
			j--;
		}
		else if (dir==1) {
			editDistance++;
			j--;
		}
		else {
			i--;
			editDistance++;
		}
	}
	return editDistance;
}

// Affine gap scoring
int affine(char *s1, char *s2) {
	int row = strlen(s1)+1;
	int column = strlen(s2)+1;

	int E[row][column];
	int F[row][column];
	int G[row][column];
	int V[row][column];
	int direction[row][column]; // 0 diagonal 1 left 2 up

	memset(E, 0, sizeof(E[0][0]) * row * column);
	memset(F, 0, sizeof(F[0][0]) * row * column);
	memset(G, 0, sizeof(G[0][0]) * row * column);
	memset(V, 0, sizeof(V[0][0]) * row * column);
	memset(direction, 0, sizeof(direction[0][0]) * row * column);


	// Initialize first row and column with gap penalty and extention values 
	for (int i = 1; i < row; i++) {
		V[i][0] = gapPenalty + i*gapExtention;
		E[i][0] = V[i][0];
		F[i][0] = INT_MIN/2;
		G[i][0] = INT_MIN/2;
		direction[i][0] = 2;
	}
	for (int j = 1; j < column; j++) {
		V[0][j] = gapPenalty + j*gapExtention;
		F[0][j] = V[0][j];
		E[0][j] = INT_MIN/2;
		G[0][j] = INT_MIN/2;
		direction[0][j] = 1;
	}
	G[0][0] = INT_MIN/2;
	E[0][0] = INT_MIN/2;
	F[0][0] = INT_MIN/2;

	// Fill the table
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < column; j++) {

			E[i][j] = max3(E[i][j-1]+gapExtention, G[i][j-1]+gapPenalty+gapExtention, F[i][j-1]+gapPenalty+gapExtention); // left
			F[i][j] = max3(F[i-1][j]+gapExtention, G[i-1][j]+gapPenalty+gapExtention, E[i-1][j]+gapPenalty+gapExtention); // up
			G[i][j] = V[i-1][j-1] + (s1[i-1]==s2[j-1] ? matchScore : mismatchScore); // diagonal
			V[i][j] = max3(G[i][j], E[i][j], F[i][j]); // scoring

			int diagonal = G[i][j];
			int whoIsBigger = F[i][j] >= E[i][j];
			int upLeftValue = (whoIsBigger) ? F[i][j] : E[i][j];
			int choice = (diagonal > upLeftValue);
			direction[i][j] = choice ? 0 : whoIsBigger+1;
		}
	}

	return traverseDirection(s1, s2, &(V[0][0]), &(direction[0][0]));
}

// Finds minimum element and its index in double array
double findMin(int *r, int *c, int n, double b[n][n]) {
    double min = INT_MAX;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (fabs(b[x][y]) >= 0.000001 && min > b[x][y]) {
            	*r = x;
            	*c = y;
            	min = b[x][y];
            }
        }
    }
    return min;
}

// The Algorithm
void upgma() {
	double current[count][count];
	memset(current, 0, sizeof(current[0][0]) * count * count);

	int currentCardinal[count];
	wmemset(currentCardinal, 1, count);
	char* currentNames[count];


	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			int result = affine(sequences[i], sequences[j]);
			current[i][j] = result;
		}
		currentNames[i] = names[i];
	}
    
	struct node* all[625];
	int nodeCount = count;
	for (int i = 0; i < count; i++) {
		all[i] = newNode(0, currentNames[i]);
	}

	for (int s = count; s > 1; s--) {
		int r = -1;
		int c = -1;
		double minValue = findMin(&r, &c, s, current) / 2;

		all[nodeCount] = newNode(0, concat(currentNames[c], currentNames[r]));
		all[nodeCount]->left = findNode(all, nodeCount, currentNames[c]);
		all[nodeCount]->left->data = minValue - findTotal(all[nodeCount]->left);
		all[nodeCount]->right = findNode(all,nodeCount, currentNames[r]);
		all[nodeCount]->right->data = minValue - findTotal(all[nodeCount]->right);
		nodeCount++;

		double next[s-1][s-1];
		memset(next, 0, sizeof(next[0][0]) * s-1 * s-1);
		int nextCardinal[s-1];
		char* nextNames[s-1];

		for (int i = 0, m = 0; i < s && m < s-1; i++, m++) {
			if (i == r || i == c) {
				m--;
				continue;
			}
			for (int j = 0, n = 0; j < s && n < s-1; j++, n++) {
				if (j == r || j == c) {
					n--;
					continue;
				}
				next[m][n] = current[i][j];
				nextNames[m] = currentNames[i];
				nextCardinal[m] = currentCardinal[i];
			}
		}
		nextCardinal[s-2] = currentCardinal[r] + currentCardinal[c];
		nextNames[s-2] = concat(currentNames[c], currentNames[r]);
		
		for (int i = 0, m = 0; i < s && m < s-1; i++, m++) {
			if (i == r || i == c) {
				m--;
				continue;
			}
			double sum = current[r][i]*currentCardinal[r] + current[c][i]*currentCardinal[c];
			next[s-2][m] = sum / (currentCardinal[r] + currentCardinal[c]);
			next[m][s-2] = sum / (currentCardinal[r] + currentCardinal[c]);
		}
		next[s-2][s-2] = 0;

		for (int i = 0; i < s-1; i++) {
			memcpy(current[i], next[i], sizeof (double) * s-1);
		}
		memcpy(currentCardinal, nextCardinal, sizeof (int) * s-1);
		memcpy(currentNames, nextNames, sizeof (char*) * s-1);
	}

	postOrder(all[nodeCount-1]);
	printf("\n");
}

// Main
void main(int argc, char **argv) {
    int opt= 0;
	int long_index = 0;

    while ((opt = getopt_long(argc, argv,"apl:b:", long_options, &long_index )) != -1) {
        switch (opt) {
            case 'i' : 
             	fileName = optarg;
                break;
            case 'g' :
             	gapPenalty = atoi(optarg);
                break;
            case 'e' : 
             	gapExtention = atoi(optarg);
                break;
            case 'o' : 
             	outName = optarg;
           		outFile = fopen(outName, "w");
                break;
            case 'm' : 
				matchScore = atoi(optarg);
				break;
			case 's' :
				mismatchScore = atoi(optarg);
				break;
             default: 
                exit(EXIT_FAILURE);
        }
    }
	readFastaSequences();
	upgma();
}