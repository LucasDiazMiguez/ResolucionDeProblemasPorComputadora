#include <stdio.h>
#include <stdlib.h> 
#include "matrixOperations.h"


void matrix_mul(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void matrix_substract(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void matrix_sum(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void matrix_div(int A[SIZE][SIZE],int B[SIZE][SIZE],int RES[SIZE][SIZE]);
void show_matrix(int B[SIZE][SIZE]);
void init_matrix(int B[SIZE][SIZE]);
void matrix_escalar_mul(int A[SIZE][SIZE]);


int main(int argc, char const *argv[])
{
    int matrix_1[SIZE][SIZE],matrix_2[SIZE][SIZE],result[SIZE][SIZE];
    printf("alojaaa \n \n ");
    init_matrix(matrix_1);
    init_matrix(matrix_2);
    printf("\n Matrix 1 \n");
    show_matrix(matrix_1);
    printf("\n Matrix 2 \n");
    show_matrix(matrix_2);
    printf("\n MUL \n");
    matrix_mul(matrix_1,matrix_2,result);
    show_matrix(result);
    printf("\n SUM \n");
    matrix_sum(matrix_1,matrix_2,result);
    show_matrix(result);
    printf("\n SUBSTRACT \n");
    matrix_substract(matrix_1,matrix_2,result);
    show_matrix(result);
    printf("\n DIV \n");
    matrix_div(matrix_1,matrix_2,result);
    show_matrix(result);
    return 0;
}
