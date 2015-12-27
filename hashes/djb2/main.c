#include <stdio.h>

/*
 * djb2 algorithm
 * http://www.cse.yorku.ca/~oz/hash.html
 *
 * was used by redis momentarily.
 */

unsigned long djb2_hash(unsigned char *str) {
  unsigned long hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + c;

  return hash;
}

int main() {
  unsigned long hash_1, hash_2, hash_3, hash_4;
  unsigned char value_1[] = "string to be hashed";
  unsigned char value_2[] = "2nd string to be hashed";
  unsigned char value_3[] = "3rd string to be hashed";
  unsigned char value_4[] = "4th string to be hashed";

  hash_1 = djb2_hash(value_1);
  hash_2 = djb2_hash(value_2);
  hash_3 = djb2_hash(value_3);
  hash_4 = djb2_hash(value_4);

  printf("hash: %lu, string: %s\n", hash_1, value_1);
  printf("hash: %lu, string: %s\n", hash_2, value_2);
  printf("hash: %lu, string: %s\n", hash_3, value_3);
  printf("hash: %lu, string: %s\n", hash_4, value_4);

  return 0;
}
