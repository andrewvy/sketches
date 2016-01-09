#include <stdio.h>

/*
 * Exercise 1-13: Write a program to print a histogram of the lengths of words in
 * its input. It is easy to draw the histogram with the bars horizontal; a vertical
 * orientation is more challenging.
 */

#define WORD_ARRAY_SIZE 50
#define OUT 0
#define IN 1

main() {
  int maxLengthOfWord = 0;
  int currentWordIndex = 0;
  int currentLength = 0;
  int character = 0;
  int numberOfLetters[WORD_ARRAY_SIZE];
  int state = 0;

  for (int i = 0; i < WORD_ARRAY_SIZE; ++i) {
    numberOfLetters[i] = 0;
  }


  while ((character = getchar()) != EOF) {
    if (character == ' ' || character == '\n' || character == '\t') {
      state = OUT;

      if (currentWordIndex + 1 <= WORD_ARRAY_SIZE) {
        currentWordIndex++;
        numberOfLetters[currentWordIndex] = currentLength;

        if (currentLength > maxLengthOfWord) {
          maxLengthOfWord = currentLength;
        }
      }

      currentLength = 0;
    } else if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
      state = IN;
      currentLength++;
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
