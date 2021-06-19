#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myMatrix.h"

void percorre_labirinto(int a, int i, int j, int m, int n, int* PTR, int matrix[m][n]){
    if((j < n) && (i < m) && (j >= 0) && (i >= 0)) {
    
        if(matrix[i][j] == 1 || matrix[i][j] == -1) return;

        a = 1;
        
        int temp = matrix[i][j];
        matrix[i][j] = -1;
      

        percorre_labirinto(a, ++i, j, m, n, PTR, matrix);
        i-=1;
        percorre_labirinto(a, i, ++j, m, n, PTR, matrix);
        j-=1;
        percorre_labirinto(a, --i, j, m, n, PTR, matrix);
        i+=1;
        percorre_labirinto(a, i, --j, m, n, PTR, matrix);
        j+=1;

        matrix[i][j] = temp;
        
        if ((a == 1) && (i == m-1) && (j == n-1)) {
          *PTR = 1;
        }
    }
}



int main() {
  FILE *input, *output;
  input = fopen("labirinto.txt", "rt");
  output = fopen("resultado.txt", "w");

  int amount;
  fscanf(input, "%d", &amount);

  while(amount > 0) {
    int x, y;
    char line[100];
    
    fscanf(input, "%d %d ", &x, &y);

    int matrix[x][y];

    for (int i = 0; i < x; i++) {
      fgets(line, 100, input);
      line[strcspn(line, "\n")] = 0;
      int len = strlen(line);

      for (int r = 0, c = 0; r < len; r++) {
        if (line[r] == 48 || line[r] == 49) {
          matrix[i][c] = line[r] - 48;
          c++;
        }
      }
    }
    int k = 0;
    percorre_labirinto(0, 0, 0, x, y, &k, matrix);

    if (k == 1)
      fputs("True\n", output);
    else
      fputs("False\n", output);
    
    amount -= 1;
  }

  fclose(input);
  fclose(output);

  return 0;
}