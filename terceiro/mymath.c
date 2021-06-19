#include "mymath.h"
#include <string.h>


char * calculate(int number) {
  char *initialStr = "[";
  char *buffer = (char*)malloc(sizeof(char)*500);

  strcat(buffer, initialStr);
  
  if (number <= 0) {
    strcat(buffer, "]\n\0");
    return buffer;
  }
  
  for (int i = 1; i < number; i++) {
    char str[10] = "";
    if (number % i == 0) {
      sprintf(str, "%d", i);
      strcat(str, ", ");
      strcat(buffer, str);
    }
  }

  char str[10] = "";

  sprintf(str, "%d", number);
  strcat(str, "]\n\0");
  strcat(buffer, str);

  return buffer;
}