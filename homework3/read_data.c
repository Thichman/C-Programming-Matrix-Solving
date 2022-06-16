#include <string.h>
#include "read_data.h"

matrix *import_data(char* file){

  FILE* file1 =  fopen(file, "r");
  char test = fgetc(file1);
  unsigned rowc = 0;
  unsigned columnc = 0;
  while(test != EOF){
    if (test == ' '){
      columnc++;
    }
    if(test == '\n'){
      
     rowc++;
     columnc++;
    }
    test = fgetc(file1);

  }
  columnc = columnc/rowc;
  struct matrix *
m = create_matrix(rowc, columnc);
  
  FILE* file2 =  fopen(file, "r");
  char test2 = fgetc(file2);
  char curr[255];
  unsigned currtrack = 0;
  unsigned rowtrack = 0;
  unsigned coltrack = 0;
 
   while(test2 != EOF){
    if(test2 == ' '){
      m -> data[rowtrack][coltrack] = strtod(curr, NULL);
     coltrack++;
     currtrack = 0;
     memset(curr, 0, sizeof(curr));
    }
    else if(test2 == '\n'){
      m -> data[rowtrack][coltrack] = strtod(curr, NULL);
     coltrack = 0;
     rowtrack++; 
     currtrack = 0;
     memset(curr, 0, sizeof(curr));


    }
    else{
      curr[currtrack] = test2;
      currtrack++; 
   }
   test2 = fgetc(file2);
}     
  return m;

}

