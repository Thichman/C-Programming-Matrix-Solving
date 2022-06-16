#include "matrix.c"
#include "read_data.c"
#include "write_pgm.c"
int main(int argc, char*argv[]){
 
 struct matrix* mat = import_data(argv[1]);
  write_pgm(mat, argv[2]);








}
