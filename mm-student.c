#include <stdio.h>
#include <stdlib.h>
#include "mm-header.h"
#include <time.h>
#include <omp.h>
#include <math.h>

#define cbrt(X) _Generic((X), \
        long double: cbrtl, \
        default: cbrt, \
        float:cbrtf)(X)    
#define BensType double

//Benjamin Creem
//May 24 2018
//Programming Assignment 1
//Multiplies two n by n matricies that are assigned
//values by the program
int main(int argc, char *argv[]){
	int n = 1000; //matrixes are n x n
	
	//Allocating Memory and Assigning Values
	BensType **mat1 = allocMat(mat1, n);
    BensType **mat2 = allocMat(mat2, n);
	assignMat(mat1, n);
    assignMat(mat2, n);

	//Finding Matrix Product  and Printing
    double start = omp_get_wtime();
	BensType **result = matMultiply(mat1, mat2, n);

    //printResult(mat1, mat2, result, n);

    double end  = omp_get_wtime();
    printf("Time: %.2f\n", end - start);

	//Free Memory
	freeMat(mat1, n);
    freeMat(mat2, n);
    freeMat(result, n);
	return 0;
}


//Free memory used by first matrix
void freeMat(BensType** mat, int n)
{
	for(int i=0; i<n; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

//Allocate memory for first matrix
double** allocMat(BensType** mat, int n)
{
	mat= (BensType**)malloc(n*sizeof(*mat));
	for(int i=0; i<n; i++)
	{
		mat[i]=(BensType*)malloc(n*sizeof(*mat[i]));
	}
    return mat;
}

//Assign values to matrix
void assignMat(BensType** mat, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
		{
            if(i == j)
            {
                mat[i][j] = 2;
            }
            else if(i - j == 1 || i - j == -1)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }    
}

//Print singular matrix
void printMat(BensType** mat, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}

//Print mat1 * mat2
void printResult(BensType** mat1, BensType** mat2, BensType** r, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%.2f ", mat1[i][j]);
		}

        printf("\t*\t");

        for(int j=0; j<n; j++)
        {
            printf("%.2f ", mat2[i][j]);
        }

        printf("\t=\t");
        
        for(int j=0; j<n; j++)
        {
            printf("%.2f\t", r[i][j]);
        }
        printf("\n");
	}
}

//Calculate matrix product 
double** matMultiply(BensType **mat1, BensType** mat2, int n)
{
	//Return matrix
	double **result = allocMat(result, n);
    #pragma omp parallel for shared(mat1, mat2, n, result)
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

 
