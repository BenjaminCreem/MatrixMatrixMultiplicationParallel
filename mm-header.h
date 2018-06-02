#include<stdio.h>
#include<stdlib.h>
#define BensType int

BensType** matMultiply(BensType** mat1, BensType** mat2, int n);
void freeMat(BensType** mat, int n);
BensType** allocMat(BensType** mat, int n);
void assignMat(BensType** mat, int n);
void printResult(double** mat1, double** mat2, double** r, int n);
void printMat(double** mat, int n);
