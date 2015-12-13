#ifndef _kv_h
#define _kv_h

typedef KeyValue_s KeyValue;

struct KeyValue_s {
  char *key;
  char *value;
};

struct KeyValueList_s {
  KeyValue *elements;
  int count;
  char *str;
};

void KeyValueList_print(KeyValueList *list);
char * KeyValueList_find(KeyValueList *list, char *key, int *where);
void KeyValueList_free(KeyValueList * *list_p);
KeyValueList * KeyValueList_create(void *buf, int buflen);

#endif
