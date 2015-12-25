#include <stdio.h>

/*
 * Exercise 1-14: Write a program to print a histogram of the
 * frequencies of different characters in its input.
 */

#define WORD_ARRAY_SIZE 512
#define OUT 0
#define IN 1

main() {
  int character = 0;
  int numberOfLetters[WORD_ARRAY_SIZE];

  for (int i = 0; i < WORD_ARRAY_SIZE; ++i) {
    numberOfLetters[i] = 0;
  }


  while ((character = getchar()) != EOF) {
    if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
      numberOfLetters[character]++;
    }
  }

  printf("----------------------------\n");
  for (int i = 0; i < WORD_ARRAY_SIZE; ++i) {
    int currentLength = numberOfLetters[i];

    for (int j = 0; j < currentLength; ++j) {
      printf("+");
    }

    printf(" %d\n", currentLength);
  }
  printf("----------------------------\n");

}
