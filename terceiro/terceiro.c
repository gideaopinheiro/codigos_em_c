#include "mymath.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
  FILE *input;
  FILE *output;

  input = fopen("numeros.txt", "r");

  if (input == NULL) {
    printf("ERRO: Deve haver um arquivo chamado 'numeros.txt' no mesmo diretório deste programa!\n");
  }

  int amount;
  fscanf(input, "%d", &amount);

  output = fopen("divisores.txt", "w");
  while(amount--) {
    int number;
    fscanf(input, "%d", &number);
    char *str = calculate(number);
    fputs(str, output);
  }

  fclose(output);
  fclose(input);

  return 0;
}