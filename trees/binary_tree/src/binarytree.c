#include <dbg.h>
#include <stdlib.h>
#include <binarytree.h>

void *BTree_init() {
  BNode *tree = malloc(sizeof(*tree));
  check_mem(tree);

  return tree;

error:
  if (tree) free(tree);

  return NULL;
}

BNode *BTree_new_node(int value) {
  BNode *node = malloc(sizeof(*node));
  check_mem(node);
  node->value = value;
  return node;

error:
  if (node) free(node);
  return NULL;
}

int BTree_insert(BNode *tree, int value) {
  BNode *node = NULL;

  if (!(value)) {
    return 0;
  }

  if (!(tree)) {
    node = BTree_new_node(value);
    check(node != NULL, "Failed to create node");
    return 1;
  }

  if (value < tree->value) {
    BTree_insert(&tree->left, value);
  } else if (value > tree->value) {
    BTree_insert(&tree->right, value);
  }

error:
  if (node) free(node);
  return 0;
}

int BTree_destroy(BNode *tree) {
  if (!(tree)) {
    return 0;
  }

  BTree_destroy(tree->left);
  BTree_destroy(tree->right);
  free(tree);
}
