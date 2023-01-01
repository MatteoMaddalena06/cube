#include "header/utils.h"

int char2int(char* value)
{
    int result = 0;

    for(int i = 0; value[i]; i++)
      result = (result*10) + (value[i] - 0x30);

    return result;
}

int** create_imatrix(int row, int col)
{
    int** new_matrix = (int**)malloc(row * sizeof(int*));

    while(row--)
      new_matrix[row] = (int*)calloc(col, sizeof(int));

    return new_matrix;
}

double** create_dmatrix(int row, int col)
{
    double** new_matrix = (double**)malloc(row * sizeof(double*));

    while(row--)
      new_matrix[row] = (double*)calloc(col, sizeof(double));

    return new_matrix;
}

void delete_matrix(void** matrix, int row, int col)
{
    while(row--)
      free(matrix[row]);

    free(matrix);
}
