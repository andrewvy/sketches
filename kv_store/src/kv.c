// djb2: http://www.cse.yorku.ca/~oz/hash.html

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "kv.h"

void KeyValueList_print(KeyValueList *list) {
  int i;

  if (list == NULL) {
    return;
  }

  for (i = 0; i < list->count; i++) {
    printf("%2d. %10s=%-10s\n", i, list->elements[i].key, list->elements[i].value);
  }

  return;
}

char *KeyValueList_find(KeyValueList *list, char *key, int *where) {
  int i;
  int start = 0;

  if (where) {
    if (*where > 0) {
      start = *where;
    }
  }

  for (i = start; i < list->count; i++) {
  }
}
