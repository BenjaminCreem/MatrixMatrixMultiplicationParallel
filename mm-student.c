#include <stdio.h>
#include <stdlib.h>
#include "mm-header.h"
#include <time.h>
#include <omp.h>

//Benjamin Creem
//May 23 2018
int main(int argc, char *argv[]){
	int n = 5; //matrixes are n x n
	
	//Allocating Memory and Assigning Values
	double **mat1 = allocMat(mat1, n);
    double **mat2 = allocMat(mat2, n);
	assignMat(mat1, n);
    assignMat(mat2, n);
	
    printf("First Matrix\n");
    printMat(mat1, n);
    printf("\nSecond Matrix\n");
    printMat(mat2, n);

	//Finding Matrix Product  and Printing
	double **result = matMultiply(mat1, mat2, n);
	//printResult(mat1, mat2, result, n);
    printf("\nResult Matrix\n");
    printMat(result, n);

	//Free Memory
	freeMat(mat1, n);
    freeMat(mat2, n);
    freeMat(result, n);
	return 0;
}


//Free memory used by first matrix
void freeMat(double** mat, int n)
{
	for(int i=0; i<n; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

//Allocate memory for first matrix
double** allocMat(double** mat, int n)
{
	mat= (double**)malloc(n*sizeof(*mat));
	for(int i=0; i<n; i++)
	{
		mat[i]=(double*)malloc(n*sizeof(*mat[i]));
	}
    return mat;
}

//Assign values to first matrix
//Picks a random number between 1 and 5 for the values
void assignMat(double** mat, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
		{
            mat[i][j] = i + j;
        }
    }    
}

//Print singular matrix
void printMat(double** mat, int n)
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
void printResult(double** mat1, double** mat2, double** r, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%.2f ", mat1[i][j]);
		}

        for(int j = 0; j<n; j++)
        {
            printf(" * %.2f ", mat2[i][j]);
        }
	
        for(int j = 0; j < n; j++)
        {
            printf(" = %.2f \n", r[i][j]);
        }
	}
}

//Calculate matrix product 
double** matMultiply(double **mat1, double** mat2, int n)
{
	//Return matrix
	double **result = allocMat(result, n);
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

 
