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
  int info;
  struct Node *left, *right;
} Node;
/**
 * Memóriát foglal egy új csomóponthoz.
 * @param newData - az új csomópont adata
 * @return a lefoglalt csomópont pointere
 */
Node *createNewNode(int newData);
/**
 * Beszúr egy új csomópontot a bináris keresőfába.
 * @param node - a fa gyökércsomópontja
 * @param key - az új csomópont adata
 *
 * @return pointer a beszúrt csomópontra
 */
Node *insert(Node *node, int key);
/**
 * Inorder bejárás (BAL-GYÖKÉR-JOBB sorrend).
 * @param root - a bináris keresőfa gyökércsomópontja
 */
void inorderTraversal(Node *root);
/**
 * Megkeresi a legkisebb elemet a fában.
 * @param node - a kiinduló csomópont
 * @return pointer a legkisebb elemre
 */
Node *minValueNode(Node *node);
/**
 * Megkeresi a legnagyobb elemet a fában.
 * @param node - a kiinduló csomópont
 * @return pointer a legnagyobb elemre
 */
Node *maxValueNode(Node *node);
/**
 * Töröl egy adott csomópontot a bináris keresőfából.
 * @param root - a fa gyökércsomópontja
 * @param key - a törlendő csomópont kulcsa
 * @return pointer az új gyökércsomópontra
 */
Node *deleteNode(Node *root, int key);
/**
 * Felszabadítja a bináris keresőfához lefoglalt memóriát.
 * @param root - pointer a fa gyökércsomópontjára mutató pointerre
 */
void destroyBinaryTree(Node **root);
#endif
