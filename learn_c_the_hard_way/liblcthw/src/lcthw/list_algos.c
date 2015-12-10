#include <lcthw/list_algos.h>
#include <lcthw/list.h>
#include <lcthw/dbg.h>

int List_bubble_sort(List *list, List_compare compare_func) {
  int has_swapped = 1;

  if (List_count(list) <= 1) {
    return 0;
  }

  do {
    has_swapped = 1;

    LIST_FOREACH(list, first, next, cur) {
      if (cur == list->last || cur->next == NULL) {
        continue;
      }

      if (compare_func(cur->value, cur->next->value) > 0) {
        void *temp = cur->value;
        cur->value = cur->next->value;
        cur->next->value = temp;
        has_swapped = 0;
      }
    }
  } while(!has_swapped);

  return has_swapped;
}

List *List_merge_sort(List *list, List_compare compare_func) {
  return list;
}
