#include <stdio.h>

/*
 * Exercise 1-9: Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank.
 */

main() {
  int c;
  int hadBlank;

  while ((c = getchar()) != EOF) {
    if (c == ' ' && !hadBlank) {
      putchar(c);
      hadBlank = 1;
    } else if (c != ' ') {
      putchar(c);
      hadBlank = 0;
    }
  }
}
