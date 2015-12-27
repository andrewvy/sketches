#include <stdio.h>

/*
 * Exercise 1-15: Rewrite the temperature conversion program of
 * Section 1.2 to use a function for conversion.
 */

float convert_fahrenheit_to_celsius(float fahr) {
  return 5 * (fahr - 32) / 9;
}

int main() {
  float fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  while (fahr <= upper) {
    printf("%3.0f\t%6.1f\n", fahr, convert_fahrenheit_to_celsius(fahr));
    fahr = fahr + step;
  }

  return 0;
}
