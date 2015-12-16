#include "minunit.h"
#include <binarytree.h>

static BNode *tree = NULL;
static int test1 = 10;
static int test2 = 27;
static int test3 = 8;
static int test4 = 600;
static int test5 = 1;

char *test_create() {
  tree = BTree_init();

  mu_assert(tree != NULL, "Failed to create tree.");

  return NULL;
}

char *test_insert() {
  BTree_insert(tree, test1);
}

char *test_destroy() {
  BTree_destroy(tree);
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_insert);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
