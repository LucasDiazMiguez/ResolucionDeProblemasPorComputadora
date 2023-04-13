#include <stdio.h>
#include <stdlib.h> 
#include "matrixOperations.h"

// Usar doxigen

//arrancar el array de posiciones con un  determinado valor y a medida que pide
// + espacio hay que duplicarlo. 
// implementar busqueda binaria para inserci
//usar assets


Matrix create_matrix(int rows,int cols){
    
    int randomSize=0;
    Matrix M; 
    randomSize = rand() % (rows>cols ? cols:rows);
    M.cols = cols;
    M.rows = rows;
    M.filled_size = 5;
    M.total_size = 5 + randomSize; //fixie la cantida de datos al ppio
    M.matrix = (MatrixElement *) calloc(M.total_size,sizeof(MatrixElement));
    printf("random size is %d \n",randomSize);
    printf("filled_size is %d \n",M.filled_size);
    printf("total size es  %d \n",M.total_size);
    if (!M.matrix)
    {
        printf("memory alocation error");
        exit(-1);
    }
    
    Coordinate newCoord;
    int randomValue;

    for (int i = 0; i <M.filled_size ; i++)
        {
            newCoord.row =  rand()%rows;
            newCoord.col =  rand()%cols;
            printf(" esta definida la pos (%d,%d)  ? %s ",newCoord.row,newCoord.col,isRef(M,newCoord)?"si":"no");
            if (!isRef(M,newCoord))
            {
                randomValue = rand()%300;
                if (!M.matrix)
                {
                    printf("memory alocation error");
                    exit(-1);
                }
                M.matrix[i].coordinates.row = newCoord.row;
                M.matrix[i].coordinates.col = newCoord.col;
                M.matrix[i].value = randomValue;
                printf("random value  is %d \n",randomValue);
            }
        } 

    if (!M.matrix)
    {
        printf("memory alocation error");
        exit(-1);
    }

    printf("\nMATRIX CREADA\n");
    return M;
    
}
void show_matrix(Matrix A){
    for (int i = 0; i < A.filled_size; i++)
        printf("(%d,%d) = %d \n",A.matrix[i].coordinates.row,A.matrix[i].coordinates.col,A.matrix[i].value);

}


void free_matrix(Matrix M){
            free(M.matrix);
}
bool isRef(Matrix M, Coordinate C){
    for (size_t i = 0; i < M.filled_size; i++)
    {
        if (M.matrix[i].coordinates.row == C.row &&
        M.matrix[i].coordinates.col == C.col )
        {
            printf("\n coordenadas de matriz %d,%d = %d,%d",M.matrix[i].coordinates.row,M.matrix[i].coordinates.col,C.row,C.col);
            // printf("\n coordenadas propuestas %d,%d");
            return 1;
        }
        
    }

    return  0;
}



// Function to swap two struct elements
// void swap(struct RowColumnValue* a, struct RowColumnValue* b) {
//   struct RowColumnValue temp = *a;
//   *a = *b;
//   *b = temp;
// }

int order_matrix(Matrix *M){
    
    MatrixElement b;
        for(int i = 0; i < M->filled_size; i++){
            for( int j = 0; j<M->filled_size; j++)
            {
                if(
                    ((M->matrix[i].coordinates.row)>
                    (M->matrix[j].coordinates.row))
                )
                {
                    b = M->matrix[i];
                    M->matrix[i] = M->matrix[j];
                    M->matrix[j]=b;
                }else if
                (
                    ((M->matrix[i].coordinates.row)==
                    (M->matrix[j].coordinates.row))
                     &&
                ( 
                    (M->matrix[i].coordinates.row)>
                    (M->matrix[j].coordinates.row))
                ){
                    b = M->matrix[i];
                    M->matrix[i] = M->matrix[j];
                    M->matrix[j]=b;
                }
            }
        }
        printf("va matriz con rows ordenadas\n");
        show_matrix(*M);
}

bool validCoordinates(Matrix m, Coordinate c){
    
    printf(" \n es valida la coordenada ? %s ",(m.cols>= c.col && m.rows>= c.row) ?"si\n":"no \n");
    return (m.cols>= c.col && m.rows>= c.row);
}


int binary_search(Matrix m,int value){
    int left=0;
    int right = m.filled_size;
    int midInd = (left+right)/2;
    while (left<=right)
    {
        if (m.matrix[midInd].value == value)
            return midInd;
          
        if (m.matrix[midInd].value >= value)
            right = midInd-1;
        else
            left = midInd+1;
            
        midInd = (left+right)/2;
    }
    printf("midInf %d \n",midInd);
    return -1;
}
int setElem(Matrix *m, Coordinate c,int value){
    if (validCoordinates(*m,c))
    {
        if (!isRef(*m,c))
        {
            if (m->filled_size==m->total_size)
            {
                printf("es igual al totalsize");
                show_matrix(*m);

                m->matrix = (MatrixElement *) realloc(m->matrix, 2*m->total_size*sizeof(MatrixElement));
                m->total_size = m->total_size*2;
            if (!(m->matrix))
                {
                    printf("memory alocation error");
                    exit(-1);
                }
                
                show_matrix(*m);
            }
            m->matrix[m->filled_size].coordinates.col = c.col;
            m->matrix[m->filled_size].coordinates.row = c.row;
            m->matrix[m->filled_size].value = value;
            printf("value para poner en la matriz (%d %d)= %d",     m->matrix[m->filled_size].coordinates.col,
                     m->matrix[m->filled_size].coordinates.row,
                     m->matrix[m->filled_size].value = value);
            m->filled_size++;
        }
        else
            printf("ya existe referenciado");
    }else
    {
        printf("no son validas las coord");
        return 0;
    }
}


int return_array_pos(Matrix M,Coordinate C){
    if (validCoordinates(M,C) && isRef(M,C))
    {
        for (size_t i = 0; i < M.filled_size; i++)
        {
            if (M.matrix[i].coordinates.row == C.row &&
                M.matrix[i].coordinates.col == C.col )
            {
                return i;
            }
        }
    }
    return 0;
}

void erase(Matrix *m, Coordinate c){

    if (validCoordinates(*m,c))
    {
        if (isRef(*m,c))
        {
            if ((m->filled_size)== (m->total_size)/2)
            {
                printf("es igual al totalsize");
                m->matrix = (MatrixElement *) realloc(m->matrix, ((m->total_size)/2)*sizeof(MatrixElement));
                m->total_size = (m->total_size)/2;
            }
    
            m->matrix[return_array_pos(*m,c)].value= 0;
            m->matrix[return_array_pos(*m,c)].coordinates.col=0;
            m->matrix[return_array_pos(*m,c)].coordinates.row=0;
            m->filled_size--;
        }
        else
            printf("ya existe referenciado");
    }else
    {
        printf("no son validas las codord");
    }
}

