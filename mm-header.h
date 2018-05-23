#include<stdio.h>
#include<stdlib.h>

double** matMultiply(double** mat1, double** mat2, int n);
void freeMat(double** mat, int n);
double** allocMat(double** mat, int n);
void assignMat(double** mat, int n);
void printResult(double** mat1, double** mat2, double** r, int n);
void printMat(double** mat, int n);
