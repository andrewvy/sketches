#include <stdio.h>
#define MAXLINE 1000
#define MINIMUM_LENGTH 80

/*
 * Exercise 1-17: Write a program to print all input lines that are
 * longer than 80 characters.
 */

int sgetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = sgetline(line, MAXLINE)) > 0)
    if (len > MINIMUM_LENGTH) {
      printf("%s", line);
    }

  return 0;
}

int sgetline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
