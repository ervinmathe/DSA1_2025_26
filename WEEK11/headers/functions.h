#ifndef BINARYSEARCHTREE_BINARY_SEARCH_TREE_H
#define BINARYSEARCHTREE_BINARY_SEARCH_TREE_H
/**
 * Egy csomópontot reprezentáló struktúra a bináris keresőfán.
 * @param info - a csomópont által tárolt adat (egész szám)
 * @param left - pointer a bal oldali gyermekcsomópontra
 * @param right - pointer a jobb oldali gyermekcsomópontra
 */

typedef struct HAZ {
  int info;
  char nev[12];
} HAZ;
typedef struct Node {
  HAZ info;
  struct Node *left, *right;
} Node;

Node *createNewNode(HAZ newData);
Node *insert(Node *node, HAZ data);
Node *deleteNode(Node *root, HAZ data);
Node *minValueNode(Node *node);
Node *maxValueNode(Node *node);
void inorderTraversal(Node *root);
void destroyBinaryTree(Node **root);
#endif
