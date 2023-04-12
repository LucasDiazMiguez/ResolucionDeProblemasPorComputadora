#include "matrixOperations.h"



void matrix_mul(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            RES[i][j] = A[i][j]* B[i][j];
}
void matrix_scalar_mul(int A[SIZE][SIZE],int scalar)
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            A[i][j] = A[i][j]* scalar;
}
void matrix_substract(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            RES[i][j] = A[i][j]- B[i][j];
}
void matrix_sum(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE])
{    
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            RES[i][j] = A[i][j]+ B[i][j];
}
void matrix_div(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            RES[i][j] = A[i][j]/B[i][j];
}
void show_matrix(int B[SIZE][SIZE]){
    printf("\n ");
    for (int i = 0; i < SIZE; i++)
       {
           for (int j = 0; j < SIZE; j++)
               printf(" %d  ",B[i][j]);
        printf(" \n ");
       }
    printf("------------------------");
}

void init_matrix(int B[SIZE][SIZE]){
 for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            B[i][j] = rand() % 10 + 1; 
}