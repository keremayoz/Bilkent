CS-481 Bioinformatic Algorithms
_______________________________

NOTES
*****

-To compile just run the command;

>> make

-Then run it as 

>> ./main

-pattern.fa and text.fa should be in the same directory with the code.

SAMPLE EXECUTION
****************

Brute Force Algorithm
-------------------------
P occurs in T at position: 179
-------------------------
#Comparisons = 549 - Run Time(s) = 8

Rabin-Karp Algorithm
-------------------------
P occurs in T at position: 179
-------------------------
#Comparisons = 49 - Run Time(s) = 45

Knuth-Morris-Prat Algorithm
-------------------------
P occurs in T at position: 179
-------------------------
#Comparisons = 521 - Run Time(s) = 8

Boyer-Moore Algorithm
-------------------------
P occurs in T at position: 179
-------------------------
#Comparisons = 91 - Run Time(s) = 18

RESULT
******

Best performing algorithm is Boyer-Moore, especially in the large inputs.

____________________________

Kerem Ayöz
21501569 - Computer Science