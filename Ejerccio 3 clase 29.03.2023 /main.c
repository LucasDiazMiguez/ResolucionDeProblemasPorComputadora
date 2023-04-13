#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <time.h>
#include "main.h"


int main (void) {

    Matrix M1,M2;
    srand(time(NULL));
    M1 = create_matrix(10,10);
    M2 = create_matrix(10,10);
    Coordinate m,n,o;
    m.col = 3;
    m.row = 3;
    o.col = 4;
    o.row = 5;
    n.col = 6;
    n.row = 6;
    
    show_matrix(M1);
    printf(" \nProcedo  a meter un par de datos\n");
    setElem(&M1,m,300);
    setElem(&M1,n,300);
    setElem(&M1,o,300);
    setElem(&M1,o,300);
    show_matrix(M1);
    erase(&M1,o);
    show_matrix(M1);
    erase(&M1,n);
    show_matrix(M1);
    order_matrix(&M1);
    printf("\nordered\n");
    show_matrix(M1);
    // M2 = create_matrix( 10,10);

    setElem(&M1,o,20120);
    show_matrix(M1);
    printf("ASKJD");
    printf("M1.filled_size %d ",M1.filled_size);
    printf("ubicaci[on ]%d",binary_search(M1,20120));
    // ResMul= matrix_multiplication(&M1, &M2);
    // ResDiv= matrix_division(&M1, &M2);
    // ResSub= matrix_substract(&M1, &M2);
    // ResSum= matrix_sum(&M1, &M2);
    // ResSca= matrix_scalar_mul(&M1, 2);
    // printf("M1 \n");
    // show_matrix(M1);
    // printf("M2 \n");
    // show_matrix(M2);
    // printf("Multiplication\n");
    // show_matrix(ResMul);
    // printf("Division\n");
    // show_matrix(ResDiv);
    // printf("Substraction\n");
    // show_matrix(ResSub);
    // printf("Sum\n");
    // show_matrix(ResSum);
    // printf("Scalar Product\n");
    
    
    free_matrix(M1);
    // free_tmatrix(&M2);
    // free_tmatrix(&ResMul);
    // free_tmatrix(&ResDiv);
    // free_tmatrix(&ResSub);
    // free_tmatrix(&ResSum);
    // free_tmatrix(&ResSca);
    return 0;
}