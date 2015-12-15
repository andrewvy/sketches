#ifndef _binarytree_h
#define _binarytree_h

struct BNode;

typedef struct {
  int value;
  struct BNode *right;
  struct BNode *left;
} BNode;

BNode *BTree_init();
BNode *BTree_new_node(int value);
int BTree_insert(BNode **tree, int value);
int BTree_destroy(BNode *tree);

#endif
