#include <stdio.h>

/*
 * Exercise 1-4: Write a program to print the corresponding
 * Celsius to Fahrenheit table.
 */

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("------------------------------------\n");
  printf("--- Temperature C -> F Table ---\n");
  printf("------------------------------------\n\n\n");

  while (celsius <= upper) {
    fahr = celsius * 9/5 + 32;

    printf("%3.0f\t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
