#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Node {
  char item;
  struct Node *next;
}Node;


typedef struct Stack {
  Node *top;
}Stack;


void createStack(Stack *stack) {
  stack->top = NULL;
}


void stackUp(char data, Stack *stack) {
  Node *new = (Node *)malloc(sizeof(Node));

  new->item = data;
  new->next = stack->top;
  stack->top = new;
}


char pop(Stack *stack) {
  Node *temp = stack->top;

  if(temp == NULL) {
    return -1;
  }
  
  char c = temp->item;
  stack->top = temp->next;
  temp->next = NULL;
  free(temp);
  return c;
}


void putStringInStack(char *str, Stack *stack) {
  int len = strlen(str);
  for(int i = 0; i < len; i++) {
    stackUp(str[i], stack);
  }
}


void printStack(Stack *stack, FILE *arq) {
  Node *ptr = stack->top;
  if (ptr == NULL) {
    return;
  }
  while(ptr != NULL) {
    fputc(ptr->item, arq);
    ptr = ptr->next;
  }
  fputc('\n', arq);
}


int toLowerCase(char character) {
  if (character >= 97 && character <= 122) {
    character -= 32;
  }
  return character;
}


int palindrome(char *str) {
  int len = strlen(str) - 1;
  int k = len / 2;
  for (int i = 0, j = len; i <= len; i++, j--) {
    if (toLowerCase(str[i]) != toLowerCase(str[j])) {
      return 0;
    }
  }
  return 1;
}


int main() {
  FILE *input, *output;
  
  input = fopen("entrada.txt", "rt");
  if(input == NULL) {
    printf("erro\n");
  }

  output = fopen("saida.txt", "wt");

  while (!feof(input)) {
    char str[100];
    char *result;

    result = fgets(str, '\n', input);
    str[strcspn(str, "\n")] = 0;
    
    int len = strlen(str);
    
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    putStringInStack(str, stack);

    printStack(stack, output);
    if(palindrome(str)) {
      fputs("Palindromo\n", output);
    }
  }
  fclose(input);
  fclose(output);
  return 0;
}