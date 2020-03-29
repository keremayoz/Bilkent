#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <getopt.h>
#include <stdint.h>

// Structs needed
static struct option long_options[] = {
        {"ref",       required_argument, 0,  'r' },
        {"query",     required_argument, 0,  'q' },
        {"kmer",      required_argument, 0,  'k' },
        {"bloomsize", required_argument, 0,  'b' },
        {0,           0,                 0,   0  }
};

// Concats two given array
char* concat(const char *s1, const char *s2) {
    char *resun = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(resun, s1);
    strcat(resun, s2);
    return resun;
}

// Count the number of sequences with k-length threshold
int countSequences(char *fileName, int k) {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
    int count = 0;

	fp = fopen(fileName, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int state = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] != '>') {
			char *ch = strtok(line, " ");
			if (strlen(ch) >= k)
				count++;
		}
	}
	fclose(fp);
	if (line)
		free(line);
	return count;
}

// Read a sequence file with k-length threshold
char** readSequences(char *fileName, int k, int* sequenceCount) {
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;

	// Count the sequences
	*sequenceCount = countSequences(fileName, k);
	char ** sequences = malloc(*sequenceCount * sizeof(char*));
	
	fp = fopen(fileName, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	int state = 0;
	int i = 0;
	while ((read = getline(&line, &len, fp)) != -1 && i < *sequenceCount) {
		if (line[0] != '>') {
			if (line[read - 1] == '\n')
				line[read - 1] = 0;
			char *ch = strtok(line, " ");
			if (strlen(ch) >= k) {
				sequences[i] = malloc(strlen(ch) * sizeof(char));
    			strcpy(sequences[i++], ch);
			}	
		}
	}
	fclose(fp);
	if (line)
		free(line);
	return sequences;
}

// Prevent memory leak
void cleanupStrings ( char ** strArray, int numberOfStrings ) {
    int i;
    for ( i = 0; i < numberOfStrings; i ++ )
    {
        free ( strArray [ i ] );
    }
    free ( strArray );
}

// Access to bit
char getBit(char *bloomFilter, int index) {
	int row = index / 8;
	int column = index % 8;
	return (bloomFilter[row] >> (7-column)) & 0x01;
}

// Change the bit
void setBit(char *bloomFilter, int index, int newBit) {
	int row = index / 8;
	int column = index % 8;
	bloomFilter[row] ^= (-newBit ^ bloomFilter[row]) & (1UL << (7-column));
}

// djb2 - Dan Bernstein
uint32_t hashFunction1(char *str, int size) {
    uint32_t hashval;
    for (hashval = 0; *str != '\0'; str++)
        hashval = *str + 31*hashval;
    return hashval % size;
}

// Jenkins One At A Time
uint32_t hashFunction2(char *str, int size) {
    uint32_t hash, i;
    for(hash = i = 0; i < strlen(str); ++i)
    {
        hash += str[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash % size;
}

// MurmurOAAT32
uint32_t  hashFunction3 (char * str, int size) {
  uint32_t h = 3323198485ul;
  for (;*str;++str) {
    h ^= *str;
    h *= 0x5bd1e995;
    h ^= h >> 15;
  }
  return h%size;
}

char* reverseComplement(char *str) {
	char *reverse = malloc((strlen(str)+1) * sizeof(char));
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'A')
			reverse[i] = 'T';
		else if (str[i] == 'C')
			reverse[i] = 'G';
		else if (str[i] == 'G')
			reverse[i] = 'C'; 
		else if (str[i] == 'T')
			reverse[i] = 'A';
	}
	reverse[strlen(str)] = '\0';
	return reverse;
}

// Main
void main(int argc, char **argv) {
    int opt= 0;
	int long_index = 0;
	char *referenceName = "";
	char *queryName = "";
	int kmerLength = 0;
	int bloomSize = 0;
	char **reference ;
	char **query ;

    while ((opt = getopt_long(argc, argv,"apl:b:", long_options, &long_index )) != -1) {
        switch (opt) {
            case 'r' : 
             	referenceName = optarg;
                break;
            case 'q' :
             	queryName = optarg;
                break;
            case 'k' : 
             	kmerLength = atoi(optarg);
                break;
            case 'b' : 
				bloomSize = atoi(optarg);
				break;
             default: 
                exit(EXIT_FAILURE);
        }
    }

    // Read Files
    int referenceSize, querySize;
	reference = readSequences(referenceName, kmerLength, &referenceSize);
	query = readSequences(queryName, kmerLength, &querySize);
	
	// Keep the counts of kmers and occurences
	int referenceKmerCount = 0;
	int queryKmerCount = 0;
	int occurenceCount = 0;

	// Initialize Bloom Filter with char array
	char *bloomFilter = malloc(bloomSize * sizeof(char));
	memset( bloomFilter, 0, sizeof(char)*bloomSize );

	// Hash the k-mers in reference sequences
	for (int i = 0; i < referenceSize; i++) {
		for (int j = 0; j <= strlen(reference[i])-kmerLength; j++) {

			// Find next k-mer
			char kmer[kmerLength];
			memcpy( kmer, &reference[i][j], kmerLength);
			kmer[kmerLength-1] = '\0';

			char *reverseKmer = reverseComplement(kmer);
			if (strcmp(kmer, reverseKmer) > 0) {
				strcpy(kmer, reverseKmer);
			}
			// Fill the Bloom Filter
			setBit(bloomFilter, hashFunction1(kmer, bloomSize), 1);
			setBit(bloomFilter, hashFunction2(kmer, bloomSize), 1);
			setBit(bloomFilter, hashFunction3(kmer, bloomSize), 1);
			referenceKmerCount++;
		}

	}

	// Query the Bloom Filter
	for (int i = 0; i < querySize; i++) {
		for (int j = 0; j <= strlen(query[i])-kmerLength; j++) {

			// Find next k-mer
			char kmer[kmerLength];
			memcpy( kmer, &query[i][j], kmerLength);
			kmer[kmerLength-1] = '\0';
			
			// Obtain bits in hash positions
			int first = getBit(bloomFilter, hashFunction1(kmer, bloomSize));
			int second = getBit(bloomFilter, hashFunction2(kmer, bloomSize));
			int third = getBit(bloomFilter, hashFunction3(kmer, bloomSize));

			// Check the existence
			if (first && second && third) {
				occurenceCount++;
			}
			queryKmerCount++;
		}
	}

	printf("\n");
	printf("Number of k-mers indexed in reference = %d\n", referenceKmerCount);
	printf("Number of k-mers indexed in query = %d\n", queryKmerCount);
	printf("Number of kmers in query found in reference = %d\n", occurenceCount);

	// Finale
	cleanupStrings(reference, sizeof(reference) / sizeof(reference[0]));
	cleanupStrings(query, sizeof(query) / sizeof(query[0]));	
}