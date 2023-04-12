#include <stdio.h>
#include <stdlib.h> 
#include "main.h"


int main (void) {

    Matrix M1,M2,ResMul,ResDiv,ResSum,ResSub,ResSca;
    char file1[]="datosM1.txt";
    char file2[]="datosM2.txt";
    M1 = initialize_matrix(file1);
    M2 = initialize_matrix(file2);
    ResMul= matrix_multiplication(&M1, &M2);
    ResDiv= matrix_division(&M1, &M2);
    ResSub= matrix_substract(&M1, &M2);
    ResSum= matrix_sum(&M1, &M2);
    ResSca= matrix_scalar_mul(&M1, 2);
    
    printf("M1 \n");
    show_matrix(M1);
    printf("M2 \n");
    show_matrix(M2);
    printf("Multiplication\n");
    show_matrix(ResMul);
    printf("Division\n");
    show_matrix(ResDiv);
    printf("Substraction\n");
    show_matrix(ResSub);
    printf("Sum\n");
    show_matrix(ResSum);
    printf("Scalar Product\n");
    show_matrix(ResSca);
    
    
    free_tmatrix(&M1);
    free_tmatrix(&M2);
    free_tmatrix(&ResMul);
    free_tmatrix(&ResDiv);
    free_tmatrix(&ResSub);
    free_tmatrix(&ResSum);
    free_tmatrix(&ResSca);
    return 0;
}