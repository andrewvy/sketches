#include <stdio.h>

/*
 * C provides several other basic data types:
 * int- integer
 * float - floating point number
 * char - character, single byte
 * short - short integer
 * long - long integer
 * double - double-precision floating point
 * etc..
 */

main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}


/*
 * printf
 * %d - print as decimal integer
 * %6d - print as decimal integer, at least 6 characters wide
 * %f - print as floating point
 * %6f - print as floating point, at least 6 characters after decimal point
 * %.2f - print as floating point, 2 characters after decimal point
 * %6.2 - print as floating point, at least 6 wide and 2 after decimal point
 */
