#include <stdio.h>

/*
 * Exercise 1-8: Write a program to count blanks, tabs and newlines.
 */

main() {
  int c;
  int nl = 0;
  int tabs = 0;
  int blanks = 0;

  while((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
    } else if (c == '\t') {
      ++tabs;
    } else if (c == ' ') {
      ++blanks;
    }
  }

  printf("New Lines: %d\n", nl);
  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
}
