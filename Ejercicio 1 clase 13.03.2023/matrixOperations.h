#include <stdio.h>
#include <stdlib.h> 
#define SIZE 5


void matrix_mul(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void matrix_substract(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void matrix_sum(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void matrix_div(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void show_matrix(int B[SIZE][SIZE]);
void init_matrix(int B[SIZE][SIZE]);
void matrix_scalar_mul(int A[SIZE][SIZE],int scalar);
