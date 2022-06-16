#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


matrix *create_matrix(unsigned rows, unsigned columns){


  struct matrix *m;
  m = (struct matrix*)malloc(sizeof(struct matrix));
  m ->rows = rows;
  m ->columns = columns;
  m -> data = (double **)malloc(sizeof(double *) * m -> rows);
   for (int i = 0; i < m -> rows; i++) {
   m -> data[i] = (double *)malloc(sizeof(double) * m -> columns);
   for (int j = 0; j < m -> columns; j++){
	  m -> data[i][j] = 0.0;

	}
  }

  return m;

}

void print_matrix(struct matrix *c){
  for(int i = 0; i < c ->rows; i++){
    for(int j = 0; j < c ->columns; j++){
      printf("%f ", c ->data[i][j]);

    }
    printf("\n");

  }

}

void free_matrix(struct matrix *c){

   for (int i = 0; i < c -> rows; i++) {
     free (c -> data[i]);
   }
   free (c -> data);
   free (c);

}

