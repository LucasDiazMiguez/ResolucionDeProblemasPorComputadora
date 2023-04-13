#include <stdbool.h>

typedef struct coord{
    int row,col;
}Coordinate;

typedef struct matrixelement{
    Coordinate coordinates;
    int value;
}MatrixElement;

typedef struct Matrix {
    int rows,cols;
    MatrixElement *matrix;
    int filled_size;
    int total_size;
} Matrix;





int order_matrix(Matrix *M);
int binary_search(Matrix m,int value);

void erase(Matrix *m, Coordinate c);
// int getElem(Matrix m, coordinate c);
int setElem(Matrix *m, Coordinate c,int value);
bool isRef(Matrix m, Coordinate c);
// int getElem(Matrix m, coordinate c);
// int rows(Matrix m);
// int cols(Matrix m);j
Matrix create_matrix(int rows, int cols);

int return_array_pos(Matrix m,Coordinate c);
void show_matrix(Matrix A);
void free_matrix(Matrix M);
Matrix matrix_multiplication(Matrix A,Matrix B);
// Matrix matrix_multiplication(Matrix *A,Matrix *B);
// Matrix matrix_scalar_mul(Matrix *A,int scalar);
// Matrix matrix_substract(Matrix *A,Matrix *B);
// Matrix matrix_sum(Matrix *A,Matrix *B);
// Matrix matrix_division(Matrix *A,Matrix *B);
