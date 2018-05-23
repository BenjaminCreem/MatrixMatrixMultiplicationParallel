#include <stdio.h>
#include <stdlib.h>
#include "mm-header.h"

//Benjamin Creem
int main(int argc, char *argv[]){
	int n = 5; //matrix is n x n
	
	//Allocating Memory and Assigning Values
	double **matrix = allocMat(matrix, n);
	double *vector = allocVec(vector, n);
	assignMat(matrix, n);
	assignVec(vector, n);

	//Finding Dot Product and Printing
	double* result = mvp(matrix, vector, n);
	printMatVec(matrix, vector, result, n);

	//Free Memory
	freeMat(matrix, n);
    free(vector);
    free(result);
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
void assignMat(double** mat, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
		{
            if(i==j)
            {
                mat[i][j]=2;
            }
            else if(j-i==1 || i-j==1)
            {
                mat[i][j]=1;
            }
            else
            {
                mat[i][j]=0;
            }
        }
    }    
}

//Allocate memory for vector
double* allocVec(double* vec, int n)
{
	vec=(double*)malloc(n*sizeof(double));
	return vec;
}

//Assign values to vector
void assignVec(double* vec, int n)
{
	for(int i=0; i<n; i++)
	{
		vec[i]=1;
	}
}

//Print matrix dot vector
void printMatVec(double** mat, double* vec, double* mvp, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%.2f ", mat[i][j]);
		}
		printf("* %.2f ", vec[i]);
		printf("= %.2f \n", mvp[i]);
	}
}

//Calculate matrix dot vector
double* mvp(double **mat, double* vec, int n)
{
	//Return matrix
	double* mvp = (double*)malloc(n * sizeof(double));

	//Find dot product
	for(int i=0; i<n; i++)
	{
        mvp[i] = 0;
		for(int j=0; j<n; j++)
		{
			mvp[i] += mat[j][i] * vec[i];
		}
	}
    return mvp;
}

 
