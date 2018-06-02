#include<stdio.h>
#include<stdlib.h>
#define BensType double

BensType** matMultiply(BensType** mat1, BensType** mat2, int n);
int** matMultiplyInt(int **mat1, int **mat2, int n);
void freeMat(BensType** mat, int n);
void freeMatInt(int** mat, int n);
double **allocMat(BensType** mat, int n);
int **allocMatInt(int **mat, int n);
void assignMat(BensType** mat, int n);
void assignMatInt(int**mat, int n);
void printResult(BensType** mat1, BensType** mat2, BensType** r, int n);
void printMat(BensType** mat, int n);
