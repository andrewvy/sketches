#include <dbg.h>
#include <stdlib.h>
#include <binarytree.h>

BNode *BTree_init() {
  BNode *tree = calloc(1, sizeof(BNode));
  check_mem(tree);
  return tree;

error:
  if (tree) free(tree);

  return NULL;
}

BNode *BTree_new_node(int value) {
  BNode *node = calloc(1, sizeof(*node));
  check_mem(node);
  node->value = value;
  return node;

error:
  if (node) free(node);
  return NULL;
}

int BTree_insert(BNode **tree, int value) {
  if (!value) {
    return 0;
  }

  if (!(*tree)) {
    *tree = BTree_new_node(value);
    return 1;
  }

  if (value < (*tree)->value) {
    return BTree_insert(&(*tree)->left, value);
  } else if (value > (*tree)->value) {
    return BTree_insert(&(*tree)->right, value);
  }

error:
  if (tree) free(tree);
  return 0;
}

int BTree_destroy(BNode *tree) {
  if (!(tree)) {
    return 0;
  }

  BTree_destroy(&tree->left);
  BTree_destroy(&tree->right);
  free(tree);
}
