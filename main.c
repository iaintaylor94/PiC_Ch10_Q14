// Program to convert a numnber to a character string

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Declare Functions
int intLength (int);
char *numToString (int);
char *negNumToString (int);

int main(void) {
  
  char *retPtr;
  int in = -100;

  printf ("Input: %d\n", in);
  retPtr = negNumToString(in);
  printf ("Output: %s\n", retPtr);
  
  return 0;
}

// Define Functions
int intLength(int input) {
  int len = 0;
  
  while (input != 0) {
    len++;
    input /= 10;
  }
  
  return len;
}

char *numToString (int input) {
  char *heapString = (char*) malloc (intLength(input) + 1);

  heapString[intLength(input)] = '\0';
  for (int i = intLength(input) - 1; i >= 0; i--) {
    heapString[i] = (input % 10) + '0';
    input /= 10;
  }
  
  return heapString;
}

char * negNumToString (int input) {
  bool isNegative = false;
  if (input < 0) {
    isNegative = true;
    input *= - 1;
  }

  char *posString = numToString(input);

  if (isNegative) {
    char *output = (char*) malloc(strlen(posString) + 2);
    *output = '-'; // output[0] = '-'
    *(output + strlen(posString) + 1) = '\0'; // output[strlen(posString + 1)] = '\0'

    // Fill middle characters
    for (int i = 0; i < strlen(posString); i++)
      *(output + i + 1) = *(posString + i);

    free (posString);
    return output;
  }
  
  return posString;
}