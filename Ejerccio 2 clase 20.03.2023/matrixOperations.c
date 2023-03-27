#include <stdio.h>
#include <stdlib.h> 
#include "matrixOperations.h"


Matrix create_matrix(int rows,int cols){
    
    Matrix M; 
    M.cols = cols;
    M.rows = rows;
    M.matrix = (int **) calloc(rows,sizeof(int*));
    if (!M.matrix)
    {
        printf("memory alocation error");
        exit(-1);
    }
    
    for (int i = 0; i <rows; i++)
        {
        M.matrix[i]= (int *) calloc(cols,sizeof(int));
            if (!M.matrix)
            {
                printf("memory alocation error");
                exit(-1);
            }
        }  
    return M;
}
void free_tmatrix(Matrix *M){
    
    for (int i = 0; i <M->rows; i++)
            free(M->matrix[i]);
    free(M->matrix);
}
Matrix initialize_matrix(char a[])
    {
        Matrix M; 
        int cols,rows;
        FILE *fptr1;
        if ((fptr1 = fopen(a,"r")) == NULL){
            fprintf(stderr, "Error! opening file");
            exit(1);
        }
        fscanf(fptr1,"%d",&rows);
        fscanf(fptr1,"%d",&cols);
        fflush( stdin );
        M = create_matrix(rows,cols);
        for (int i = 0; i <M.rows; i++)
         {
             for (int j = 0; j < M.cols; j++)
                if (fptr1)
                 fscanf(fptr1,"%d",&(M.matrix[i][j]));
             printf("\n");
         }
        fclose(fptr1);
        return M; 
}

Matrix matrix_multiplication(Matrix *A,Matrix *B)
{
    Matrix M;
    M = create_matrix(A->rows,A->cols);
    for (int i = 0; i < A->cols; i++)
        for (int j = 0; j < A->cols; j++)
            M.matrix[i][j] = A->matrix[i][j]* B->matrix[i][j];
    
    return M;
}
Matrix matrix_scalar_mul(Matrix *A,int scalar)
{
    Matrix M;
    M = create_matrix(A->rows,A->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            M.matrix[i][j] = A->matrix[i][j]*scalar ;
    
    return M;
}
Matrix matrix_substract(Matrix *A,Matrix *B)
{
    Matrix M;
    M = create_matrix(A->rows,A->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            M.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    
    return M;
}
Matrix matrix_sum(Matrix *A,Matrix *B)
{
    Matrix M;
    M = create_matrix(A->rows,A->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            M.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    
    return M;
}
Matrix matrix_division(Matrix *A,Matrix *B)
{
    Matrix M;
    M = create_matrix(A->rows,A->cols);
    for (int i = 0; i < A->rows; i++)
        for (int j = 0; j < A->cols; j++)
            M.matrix[i][j] = A->matrix[i][j] / B->matrix[i][j];
    
    return M;
}
void show_matrix(Matrix A){
   
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < A.cols; j++)
               {
               printf("%d  ",A.matrix[i][j]);
               }
    printf("\n");
    }
    printf("\n");
}