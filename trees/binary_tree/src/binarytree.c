#include <dbg.h>
#include <stdlib.h>
#include <binarytree.h>

BNode *BTree_init() {
  BNode *tree = malloc(sizeof(*tree));
  BNode *right = malloc(sizeof(*right));
  BNode *left = malloc(sizeof(*left));
  tree->right = right;
  tree->left = left;
  check_mem(tree);
  check_mem(right);
  check_mem(left);

  return tree;

error:
  if (tree) free(tree);
  if (right) free(right);
  if (left) free(left);

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
  if (!value) {
    return 0;
  }

  if (!tree) {
    tree = BTree_new_node(value);
    return 1;
  }

  if (value < tree->value) {
    BTree_insert(&tree->left, value);
  } else if (value > tree->value) {
    BTree_insert(&tree->right, value);
  }

error:
  if (tree) free(tree);
  return 0;
}

int BTree_destroy(BNode *tree) {
  if (!tree) {
    return 0;
  }

  BTree_destroy((BNode *) tree->left);
  BTree_destroy((BNode *) tree->right);
  free(tree);
}
