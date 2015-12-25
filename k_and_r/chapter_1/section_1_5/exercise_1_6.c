#include <stdio.h>

/*
 * Exercise 1-6: Verify that the expression
 *  `getchar() != EOF` is 0 or 1.
 */

main() {
  int c;

  while (((c = getchar()) != EOF) == 1)
    putchar(c);
}
