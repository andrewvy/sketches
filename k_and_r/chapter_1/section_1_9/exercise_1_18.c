#include <stdio.h>
#define MAXLINE 1000
#define MINIMUM_LENGTH 80

/*
 * Exercise 1-18: Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines.
 */

int getformattedline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getformattedline(line, MAXLINE)) > 0)
    if (len) {
      printf("%s", line);
    }

  return 0;
}

int getformattedline(char s[], int lim) {
  int c, i;
  int blanks;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && (c != '\n' || c != '\t' || c != '\b'); ++i)
    s[i] = c;

  if (c == '\n' || c == '\t' || c == '\b')
    ++blanks;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  if (i == blanks) {
    return 0;
  }

  s[i] = '\0';

  return i;
}
