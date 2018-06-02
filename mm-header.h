#include<stdio.h>
#include<stdlib.h>
#define BensType int

BensType** matMultiply(BensType** mat1, BensType** mat2, int n);
void freeMat(BensType** mat, int n);
double **allocMat(BensType** mat, int n);
void assignMat(BensType** mat, int n);
void printResult(BensType** mat1, BensType** mat2, BensType** r, int n);
void printMat(BensType** mat, int n);
