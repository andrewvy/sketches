/*
 * EXTRA CREDIT
 * ------------
 * Create a struct on the /stack/
 * Initialize it with the dot syntax rather than arrow syntax
 * Pass a structure to other functions without using a pointer
 *
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person create_person(char *name, int age, int height, int weight) {
  struct Person who;

  who.name = name;
  who.age = age;
  who.height = height;
  who.weight = weight;

  return who;
}

void print_person(struct Person who) {
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[]) {
  struct Person joe = create_person("Joe Alex", 32, 64, 140);
  struct Person frank = create_person("Frank Blank", 20, 72, 180);

  print_person(joe);
  print_person(frank);

  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;
  print_person(joe);

  frank.age += 20;
  frank.weight += 20;
  print_person(frank);

  return 0;
}
