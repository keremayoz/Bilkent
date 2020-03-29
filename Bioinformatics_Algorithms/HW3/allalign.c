#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <getopt.h>

/*
 * Written by Kerem Ayöz in 15.11.19
 * Implements the Needleman-Wunsch and Smith-Waterman alignment algorithms.
 * Mode = 0 is NW whereas Mode = 1 is SW
 */

// Structs needed
static struct option long_options[] = {
        {"mode",      required_argument, 0,  'm' },
        {"input",     required_argument, 0,  'i' },
        {"gapopen",   required_argument, 0,  'o' },
        {"gapext",    required_argument, 0,  'e' },
        {0,           0,                 0,   0  }
};

typedef struct alignment {
    char *sequence1;
    char *name1;
    char *sequence2;
    char *name2;
    int score;
}alignment;

// Helpers
#define min2(x, y) (((x) < (y)) ? (x) : (y))
#define max2(x, y) (((x) > (y)) ? (x) : (y))
#define max3(x, y, z) ( z > (((x) > (y)) ? (x) : (y)) ? z : (((x) > (y)) ? (x) : (y)) )

char* concat(const char *s1, const char *s2) {
    char *resun = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(resun, s1);
    strcat(resun, s2);
    return resun;
}

// Character to string
char* ctos(char c) {
	char *merge = malloc(8 * sizeof(char));// this is just temporary array to merge with      
	merge[0] = c;
	merge[1] = '\0';
	return merge;
}

alignment* readFastaString(char *fileName) {
    char * string = "";
    alignment *al = malloc(4 * sizeof(alignment));
    al->name1 = "";
    al->name2 = "";
    al->sequence1 = "";
    al->sequence2 = "";

	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	fp = fopen(fileName, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int state = 0;
	int sequenceCount = 1;
	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] == '>') {
			if (sequenceCount) {
    			al->name1 = concat(al->name1, line+1);
				sequenceCount--;
			}
			else {
    			al->sequence1 = concat(al->sequence1, string);
				string = "";
    			al->name2 = concat(al->name2, line+1);
			}
		}
		else {
			if (line[read - 1] == '\n')
				line[read - 1] = 0;
    		string = concat(string, line);
		}
	}
	al->sequence2 = concat(al->sequence2, string);
	fclose(fp);
	if (line)
		free(line);

	return al;
}

// Traverses direction array and produces alignment result
alignment* traverseDirection(char *s1, char *s2, int *scoring, int *direction, int mode) {
	int row = strlen(s1)+1;
	int column = strlen(s2)+1;
    int r = row-1, c = column-1;

    // Smith-Waterman setup: find max element in scoring matrix
    if (mode) {
    	int m = scoring[r*column+c];
		for(int i = r ; i >= 0 ; i--)
			for(int j = c ; j >= 0 ; j--)
				if (scoring[i*column+j] > m) {
					m = scoring[i*column+j];
					r = i;
					c = j;
				}
    }

    alignment *al = malloc(4 * sizeof(alignment));
    al->name1 = "";
    al->name2 = "";
    al->sequence1 = "";
    al->sequence2 = "";
    al->score = scoring[(r)*column+(c)];

	// Traverse the direction array and construct the alignments
	for(int i = r, j = c; i >= 0 && j >= 0;) {
		int dir = direction[i*column+j];
		if (dir==0) {
			al->sequence1 = concat(ctos(s1[i-1]), al->sequence1);
			al->sequence2 = concat(ctos(s2[j-1]), al->sequence2);
			i--;
			j--;
		}
		else if (dir==1) {
			al->sequence1 = concat("-", al->sequence1);
			al->sequence2 = concat(ctos(s2[j-1]), al->sequence2);
			j--;
		}
		else {
			al->sequence1 = concat(ctos(s1[i-1]),al->sequence1);
			al->sequence2 = concat("-", al->sequence2);
			i--;
		}

		if (mode && scoring[i*column+j] == 0) {
			break;
		}
	}
	return al;
}

// Naive gap scoring
alignment* naive(char *s1, char *s2, int gapPenalty, int matchScore, int mismatchScore, int mode) {
	int row = strlen(s1)+1;
	int column = strlen(s2)+1;

	int scoring[row][column];
	int direction[row][column]; // 0 diagonal 1 left 2 up

	memset(scoring, 0, sizeof(scoring[0][0]) * row * column);
	memset(direction, 0, sizeof(direction[0][0]) * row * column);

	// Initialize first row and column with gap penalty values 
	for (int i = 1; i < row; i++) {
		scoring[i][0] = gapPenalty * i;
		direction[i][0] = 2;
	}
	for (int j = 1; j < column; j++) {
		scoring[0][j] = gapPenalty * j;
		direction[0][j] = 1;
	}
	// Fill the table
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < column; j++) {
			int diagonal = (s1[i-1] == s2[j-1]) ? scoring[i-1][j-1]+matchScore : scoring[i-1][j-1]+mismatchScore;
			int whoIsBigger = scoring[i-1][j] >= scoring[i][j-1];
			int upLeftValue = (whoIsBigger) ? scoring[i-1][j]+gapPenalty : scoring[i][j-1]+gapPenalty;
			int choice = (diagonal > upLeftValue);
			scoring[i][j] = choice ? diagonal : upLeftValue;
			direction[i][j] = choice ? 0 : whoIsBigger+1;

			if (mode && scoring[i][j] < 0) {
				scoring[i][j] = 0;
				direction[i][j] = 0;
			}
		}
	}
	alignment *result = traverseDirection(s1, s2, &(scoring[0][0]), &(direction[0][0]), mode);
	return result;
}

// Affine gap scoring
alignment* affine(char *s1, char *s2, int gapPenalty, int gapExtention, int matchScore, int mismatchScore, int mode) {
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

			if (mode && V[i][j] < 0) {
				V[i][j] = 0;
				direction[i][j] = 0;
			}
		}
	}

	alignment *result = traverseDirection(s1, s2, &(V[0][0]), &(direction[0][0]), mode);
	return result;
}

// Writes result to a file
void writeToFile(alignment *result, char *fileName) {
	FILE *file;
	file = fopen(fileName, "w");

	int length = strlen(result->sequence1);
	int repeatTime = length / 60;

	fprintf(file,"%s = %d\n\n", "Score", result->score);

	for (int r = 0; r <= repeatTime; r++) {
		fprintf(file,"%s", result->name1);
		for (int i = 0; i < min2(60, length); i++) {
			char w = (result->sequence1)[i+60*r];
			fputc (w, file);
		}
		
		fprintf(file,"%s", "\n");

		fprintf(file,"%s", result->name2);
		for (int i = 0; i < min2(60, length); i++) {
			char w = (result->sequence2)[i+60*r];
			fputc (w, file);
		}
		length-=60;
		fprintf(file,"%s", "\n\n");
	}
	fclose(file);
}

// Main
void main(int argc, char **argv) {
    int opt= 0;
	char *mode = "";
	char *fileName = "";
	int gapOpen = 0;
	int gapExtention = 0;
	int matchScore = 2;
	int mismatchScore = -3;
	int long_index =0;

    while ((opt = getopt_long(argc, argv,"apl:b:", long_options, &long_index )) != -1) {
        switch (opt) {
             case 'm' :
    			mode = concat(mode, optarg);
                break;
             case 'i' : 
             	fileName = concat(fileName, optarg);
                break;
             case 'o' :
             	gapOpen = atoi(optarg);
                break;
             case 'e' : 
             	gapExtention = atoi(optarg);
                break;
             default: 
                exit(EXIT_FAILURE);
        }
    }
	
	// Read text
	alignment *al = readFastaString(fileName);
	alignment *result;
	
	if (!strcmp(mode, "global")) {
		result = naive(al->sequence1, al->sequence2, gapOpen, matchScore, mismatchScore, 0);
		result->name1 = al->name1;
		result->name2 = al->name2;
		writeToFile(result, "global-naiveGap.aln");
	}
	else if (!strcmp(mode, "local")) {
		result = naive(al->sequence1, al->sequence2, gapOpen, matchScore, mismatchScore, 1);
		result->name1 = al->name1;
		result->name2 = al->name2;
		writeToFile(result, "local-naiveGap.aln");
	}
	else if (!strcmp(mode, "aglobal")) {
		result = affine(al->sequence1, al->sequence2, gapOpen, gapExtention, matchScore, mismatchScore, 0);
		result->name1 = al->name1;
		result->name2 = al->name2;
		writeToFile(result, "global-affineGap.aln");
	}
	else if (!strcmp(mode, "alocal")) {
		result = affine(al->sequence1, al->sequence2, gapOpen, gapExtention, matchScore, mismatchScore, 1);
		result->name1 = al->name1;
		result->name2 = al->name2;
		writeToFile(result, "local-affineGap.aln");
	}
	else {
		printf("Invalid mode is given !\n");
	}
}