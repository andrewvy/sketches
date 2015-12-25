#include <stdio.h>

#define IN 1
#define OUT 0

/*
 * Exercise 1-12: Write a program that prints its input one word per line.
 */

main() {
  int c, nw, state;

  state = OUT;
  nw = 0;

  while ((c = getchar()) != EOF) {
	  if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      putchar('\n');
    } else if (state == OUT) {
		  state = IN;
		  putchar(c);
	  } else if (state == IN) {
		  putchar(c);
	  }
  }
}
