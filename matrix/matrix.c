#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** A; // matriz A de ordem N
int** B; // matriz B de ordem N
int** C; // matriz resultado C de ordem N

#define N 10 // dimenssão da matriz

int row, col;

void multiply(int** a, int** b, int** c, int size, int line, int column, int step) {
  int i = 0;
  int x = 0;
  int y;
  int col;
  if (step >0){
    col = column-size;
    x = step*size;
    y = x+size;
  }else{
    col = column;
    x = step*size;;
    y = size;
  }  

  for (i = x; i < y; i++) {
    //printf("c[%d][%d] = a[%d][%d] * b[%d][%d] \n",line,col,line,i,i,col);
    c[line][col] += a[line][i] * b[i][col];
    //printf("%d = %d * %d\n",c[line][col],a[line][i],b[i][col]);
  }
}

int main () {
	  
	  int i, j, k, sum;

	  A = (int**) malloc(N * sizeof(int*));
      B = (int**) malloc(N * sizeof(int*));
      C = (int**) malloc(N * sizeof(int*));

      printf("Loading A\n");
      for (i = 0; i < N; i++) {
        A[i] = (int*) malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
          A[i][j] = i+j;
        }
      }
	
	  printf("Matriz A\n");
      for (i = 0; i < N; i++) {
        printf("| ");
        for (j = 0; j < N; j++) {
          printf("%d\t", A[i][j]);
        }
        printf("|\n");
      }

      printf("\nLoading B\n");
      for (i = 0; i < N; i++) {
        B[i] = (int*) malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
          B[i][j] = i*j;
        }
      }

	  printf("Matriz B\n");
      for (i = 0; i < N; i++) {
        printf("| ");
        for (j = 0; j < N; j++) {
          printf("%d\t", B[i][j]);
        }
        printf("|\n");
      }	

      //printf("\nLoading C\n");
      for (i = 0; i < N; i++) {
        C[i] = (int*) malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
          C[i][j] = 0;
        }
      }
	  
	  //for (k=0;k<N;k++){
        //printf("k = %d\n",k);
        for (i = 0; i < N; i++) {
          for (j = 0; j < N; j++) {
            sum=0;
            for(k=0;k<N;k++)
               sum=sum+A[i][k]*B[k][j];
            C[i][j]=sum;         
          }
        }
      //}
	  
	  printf("Matriz C\n");
      for (i = 0; i < N; i++) {
        printf("| ");
        for (j = 0; j < N; j++) {
          printf("%d\t", C[i][j]);
        }
        printf("|\n");
      }

	  
	  return 0;
}
