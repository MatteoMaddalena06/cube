#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

#define CLRSCRN printf("\e[1;1H\e[2J");

int      char2int(char*);
int**    create_imatrix(int, int);
double** create_dmatrix(int, int);
void     delete_matrix(void**, int, int);

#endif
