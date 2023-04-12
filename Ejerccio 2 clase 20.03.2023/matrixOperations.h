
typedef struct Matrix {
    int rows,cols;
    int ** matrix;
} Matrix;


Matrix initialize_matrix(char[]);



Matrix matrix_multiplication(Matrix *A,Matrix *B);
Matrix  matrix_scalar_mul(Matrix *A,int scalar);
Matrix matrix_substract(Matrix *A,Matrix *B);
Matrix matrix_sum(Matrix *A,Matrix *B);
Matrix matrix_division(Matrix *A,Matrix *B);
void show_matrix(Matrix A);
void free_tmatrix(Matrix *M);
