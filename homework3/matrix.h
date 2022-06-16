#include <stdio.h>
#ifndef HEADER_MATRIX
#define HEADER_MATRIX
 

struct matrix{

  unsigned rows;
  unsigned columns;
  double** data;

} typedef matrix;

matrix *create_matrix(unsigned rows, unsigned columns);

void print_matrix(struct matrix *m);

void free_matrix(struct matrix *m);



#endif
