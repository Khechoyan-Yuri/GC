/*This program will generate a program that reads in DNA sequences
from a file and determines the content of A, T, C, and G in the sequence.

Created: 11-26-2015

Yuri Khechoyan
*/

#include <stdio.h>
#include <string.h>

int read_DNA (char sequence[]), MAX_IN_LENGTH, i, n;
double compare_DNA (char seq1[], char seq2[], char seq3[]);
void print_DNA (char seq1[], char seq2[], char seq3[], int n);


//http://www.chegg.com/homework-help/questions-and-answers/assignment-task-write-c-program-called-dnac-reads-three-dna-sequences-file-called-dna-inpu-q2234225
