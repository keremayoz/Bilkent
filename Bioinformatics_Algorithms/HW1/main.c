#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

// Variables
char * T;
char * P;
int n;
int m;
int comparisons[4];
int runTime[4];

char* concat(const char *s1, const char *s2) {
    char *resun = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(resun, s1);
    strcat(resun, s2);
    return resun;
}

char * readFastaString(char *fileName) {
    char * string = "";

	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
 
	fp = fopen(fileName, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
 
	int state = 0;
	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[read - 1] == '\n')
			line[read - 1] = 0;
        	string = concat(string, line);
	}
	fclose(fp);
	if (line)
		free(line);
	return string;
}

int isPrime(int num) {
    int sq_root = sqrt(num);
    for(int i = 2; i <= sq_root; i++) 
        if (num % i == 0)
            return 0;
    return 1;
}

int findPrime(int num) {
    do {
        num++;     
    } while (!isPrime(num));   
    return num;
}

long long powerMod(long long x, long long y, long long p)  { 
    long long res = 1; // Initialize result 
    x = x % p;  // Update x if it is more than or equal to p 
    x = x < 0 ? x + p : x;
    while (y > 0) { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
        // y must be even now 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}

int isSuffix(char * small, char * large, int ls, int ll) {
	// Is suffix
	int flag = 1;
	for (int i = 0; i < ls; i++) {
		if (small[i] != large[ll-ls+i]) {
			flag = 0;
			break;
		}
	}

	return flag;
}

int * failureFunction() {
	int *F = malloc(m * sizeof(int));
	F[0] = 0;
	int i = 1;
	int j = 0;
	while (i < m) {
		if (P[i] == P[j])
			F[i++] = ++j;
		else if (j > 0)
			j = F[j-1];
		else 
			F[i++] = 0;
	}
	return F;
}

int ** badCharacter() {
	int** bc;

	bc = malloc(m * sizeof(int*));
	
	// Initialize first row
	bc[0] = malloc(4 * sizeof(int));
	for (int j = 0; j < 4; j++) {
		bc[0][j] = 0;
	}

	// Fill other values
	for (int i = 1; i < m; i++) {
		bc[i] = malloc(4 * sizeof(int));
		memcpy(bc[i], bc[i-1], 4 * sizeof(int));
		bc[i][(P[i]/2)%4] = i;
	}
	return bc;
}

int * goodSuffix1() {
	int * gs1 = malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)
		gs1[i] = 0;

	gs1[m-1] = 0;
	int i, j, k;
	for (j = m-2; j >= 0; j--) {
		for (k = max(m-1, m-j-1); k > min(m-j-1,m-1); k--) {
			if (isSuffix(P+(j+1),P, m-j-1, k) && P[k-m+j] != P[j]) {
					gs1[j] = k;
			}
		}
	}
	return gs1;
}

int * goodSuffix2() {
	int * gs2 = malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)
		gs2[i] = 0;

	int i, j, k;
	for (j = 0; j <= m-2; j++) {
		for (k = m-j-1; k > 0; k--) {
			if (isSuffix(P,P+(j+1), k, m-j-1)) {
					gs2[j] = k;
					break;
			}
		}
	}
	return gs2;
}

/*   A   L   G   O   R   I   T   H   M   S   */

void BruteForce() {
	clock_t begin = clock();

	int i, j;
	for (i = 0; i < n-m+1; i++) {
		int occured = 1;
		for (j = 0; j < m; j++) {
			comparisons[0]++;
			if (T[i+j] != P[j]) {
				occured = 0;
				break;
			}
		}
		if (occured)
			printf("P occurs in T at position: %d\n", i);		
	}

	clock_t end = clock();
	runTime[0] = end - begin;	
}

void RabinKarp() {
	clock_t begin = clock();
	int q = findPrime(m);
	int c = powerMod(100,m-1,q); 

	int i, j, s;
	long long hashP, hashT;

	hashP = 0;
	hashT = 0;
	for (i = 0; i < m; i++) {
		hashP = (100 * hashP + (int)P[i]) % q;
		hashT = (100 * hashT + (int)T[i]) % q;
	}

	for(s = 0; s < n-m+1; s++) {
		if (hashT == hashP) {
			int occured = 1;
			for (i = 0; i < m; i++) {
				comparisons[1]++;
				if (T[s+i] != P[i]) {
					occured = 0;
					break;
				}
			}
			if (occured)
				printf("P occurs in T at position: %d\n", s);
		}	
		hashT = powerMod(((hashT-T[s]*c)*100 + T[s+m]),1,q);
	}
	clock_t end = clock();
	runTime[1] = end - begin;	
}

void KnuthMorrisPratt() {
	clock_t begin = clock();
	
	int *F = failureFunction();

	int i = 0, j = 0;
	while (i < n) {
		comparisons[2]++;
		if (T[i] == P[j]) {
			if (j == m-1) {
				printf("P occurs in T at position: %d\n", i-j);
				j = F[j-1];
			}
			else {
				i++;
				j++;
			}
		}
		else {
			if (j > 0)
				j = F[j-1];
			else
				i++;
		}
	}
	clock_t end = clock();
	runTime[2] = end - begin;	
}

void BoyerMoore() {
	clock_t begin = clock();

	int **bc = badCharacter();
	int *gs1 = goodSuffix1();
	int *gs2 = goodSuffix2();

	int occured = 1;
	int i, j, shift;
	for (i = 0; i < n-m+1; i++) {
		int occured = 1;
		for (j = m-1; j >= 0; --j) {
			comparisons[3]++;
			if (T[i+j] != P[j]) {
				int bc_shift = j-bc[j][(T[i+j]/2)%4];
				int gs_shift = j == m-1 ? 1 : m-max(gs1[j], gs2[j]);
				int shift_amount = max(bc_shift, gs_shift);
				i += shift_amount-1;
				occured = 0;
				break;
			}
		}
		if (occured)
			printf("P occurs in T at position: %d\n", i);
	}
	clock_t end = clock();
	runTime[3] = end - begin;	
}

void main() {
	// Read strings
	T = readFastaString("test.fa");
	P = readFastaString("pattern.fa");
	n = strlen(T);
	m = strlen(P);

	printf("Brute Force Algorithm\n");
	printf("-------------------------\n");
	BruteForce();
	printf("-------------------------\n");
	printf("#Comparisons = %d - Run Time(s) = %d\n", comparisons[0], runTime[0]);
	printf("\n");

	printf("Rabin-Karp Algorithm\n");
	printf("-------------------------\n");
	RabinKarp();
	printf("-------------------------\n");
	printf("#Comparisons = %d - Run Time(s) = %d\n", comparisons[1], runTime[1]);
	printf("\n");

	printf("Knuth-Morris-Prat Algorithm\n");
	printf("-------------------------\n");
	KnuthMorrisPratt();
	printf("-------------------------\n");
	printf("#Comparisons = %d - Run Time(s) = %d\n", comparisons[2], runTime[2]);
	printf("\n");

	printf("Boyer-Moore Algorithm\n");
	printf("-------------------------\n");
	BoyerMoore();
	printf("-------------------------\n");
	printf("#Comparisons = %d - Run Time(s) = %d\n", comparisons[3], runTime[3]);
	printf("\n");
}