#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <getopt.h>

/*
 * Written by Kerem Ayöz in 30.11.19
 */

// Structs needed
static struct option long_options[] = {
        {"fasta",      	required_argument, 0,  'f' },
        {"aln",     	required_argument, 0,  'a' },
        {"out",   		required_argument, 0,  'o' },
        {"gap",    		required_argument, 0,  'g' },
        {"match",    	required_argument, 0,  'm' },
        {"mismatch",    required_argument, 0,  's' },
        {0,           0,                 0,   0  }
};

static char alignments[10][500];
static char * sequence = "";
static double frequencies[500][5];
static int alignmentCount = 0;
static int lengthAlignment = 0;

static char resultAlignments[10][500];
static char* resultSequence = "";

// Character to string
char* ctos(char c) {
	char *merge = malloc(8 * sizeof(char));// this is just temporary array to merge with      
	merge[0] = c;
	merge[1] = '\0';
	return merge;
}

char* concat(const char *s1, const char *s2) {
    char *resun = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(resun, s1);
    strcat(resun, s2);
    return resun;
}

void readFastaString(char *fileName) {
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
		if (line[0] != '>') {
			if (line[read - 1] == '\n')
				line[read - 1] = 0;
    		sequence = concat(sequence, line);
		}
	}
	fclose(fp);
	if (line)
		free(line);
}

void readAlignments(char *fileName) {
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
  			ch = strtok(NULL, " ");
    		strcpy(alignments[i++], ch);
		}
	}
	fclose(fp);
	if (line)
		free(line);
}

void generateFrequencies() {
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < alignmentCount; j++) {
			frequencies[i][((alignments[j][i]*2)/3)%5] += 1.0/alignmentCount;
		}
	}
}

// Traverses direction array and produces alignment result
void traverseDirection(char *s1, double *scoring, double *direction) {
	int row = strlen(s1)+1;
	int column = lengthAlignment+1;
    int r = row-1, c = column-1;

	// Traverse the direction array and construct the alignments
	for(int i = r, j = c; i >= 0 && j >= 0;) {
		int dir = direction[i*column+j];
		if (dir==0) {
			resultSequence = concat(ctos(s1[i-1]), resultSequence);
			for (int k = 0; k < alignmentCount; k++)
				resultAlignments[k][j-1] = alignments[k][j-1];
			i--;
			j--;
		}
		else if (dir==1) {
			resultSequence = concat("-", resultSequence);
			for (int k = 0; k < alignmentCount; k++)
				resultAlignments[k][j-1] = alignments[k][j-1];
			j--;
		}
		else {
			resultSequence = concat(ctos(s1[i-1]), resultSequence);
			for (int k = 0; k < alignmentCount; k++)
				resultAlignments[k][j-1] = '-';
			i--;
		}
	}
}

double score(char  x, int col, int match, int mismatch) {
	double freq = frequencies[col][((x*2)/3)%5];
	return freq*match + (1-freq)*mismatch;
}

// Naive gap scoring
void naive(char *s1, int gapPenalty, int matchScore, int mismatchScore) {
	int row = strlen(s1)+1;
	int column = lengthAlignment+1;

	double scoring[row][column];
	double direction[row][column]; // 0 diagonal 1 left 2 up

	memset(scoring, 0, sizeof(scoring[0][0]) * row * column);
	memset(direction, 0, sizeof(direction[0][0]) * row * column);

	// Initialize first row and column with gap penalty values 
	for (int i = 1; i < row; i++) {
		scoring[i][0] = gapPenalty * i;
		direction[i][0] = 2;
	}
	for (int j = 1; j < column; j++) {
		for (int k = 0; k <= j; k++)
			scoring[0][j] += score('-', k, matchScore, mismatchScore);
		direction[0][j] = 1;
	}

	// Fill the table
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < column; j++) {
			// Calculate the scoring
			double diagonal = scoring[i-1][j-1]+score(s1[i-1], j-1, matchScore, mismatchScore);
			double alignGap = score('-', j-1, matchScore, mismatchScore);
			int whoIsBigger = scoring[i-1][j]+gapPenalty >= scoring[i][j-1]+alignGap;

			double upLeftValue = (whoIsBigger) ? scoring[i-1][j]+gapPenalty : scoring[i][j-1]+alignGap;
			int choice = (diagonal > upLeftValue);
			scoring[i][j] = choice ? diagonal : upLeftValue;
			direction[i][j] = choice ? 0 : whoIsBigger+1;
		}
	}
	traverseDirection(s1, &(scoring[0][0]), &(direction[0][0]));
}

// Writes result to a file
void writeToFile(char *fileName) {
	FILE *file;
	file = fopen(fileName, "w");
	int length = strlen(resultSequence);
	for (int r = 0; r < alignmentCount; r++) {
		fprintf(file, "sequence%d\t%s\n", r, resultAlignments[r]);
	}
	fprintf(file, "sequence\t%s\n", resultSequence);
	fclose(file);
}


// Main
void main(int argc, char **argv) {
    int opt= 0;
	int long_index =0;

	char *fastaName = "";
	char *alnName = "";
	char *outName = "";
	int gapScore = 0;
	int matchScore = 0;
	int mismatchScore = 0;

    while ((opt = getopt_long(argc, argv,"apl:b:", long_options, &long_index )) != -1) {
        switch (opt) {
			case 'f' :
				fastaName = concat(fastaName, optarg);
				break;
			case 'a' : 
				alnName = concat(alnName, optarg);
				break;
			case 'o' : 
				outName = concat(outName, optarg);
				break;
			case 'g' :
				gapScore = atoi(optarg);
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
	
	// Read alignments
	readAlignments(alnName);
	for (int i = 0; i < 10; i++)
		if (strlen(alignments[i]) != 0) {
			alignmentCount++;
		}
	lengthAlignment = strlen(alignments[0]);
	// Read text
	readFastaString(fastaName);

	// Algorithm
	generateFrequencies();
	naive(sequence, gapScore, matchScore, mismatchScore);
	writeToFile(outName);
}