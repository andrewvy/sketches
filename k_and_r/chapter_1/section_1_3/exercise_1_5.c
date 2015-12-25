#include <stdio.h>

/*
 * Exercise 1-5: Modify the temperature conversion program to print
 * the table in reverse order, that is, from 300 degress to 0.
 */

main() {
  int fahr;

  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
  }
}

/*
 * The choice between while and for is arbitrary, based on which
 * seems clearer. The for is usually appropriate for loops in which
 * the initialization and increment are single statements and logically
 * related, since it is more compact than while and it keeps the loop
 * control statements together in one place.
 *
 */
