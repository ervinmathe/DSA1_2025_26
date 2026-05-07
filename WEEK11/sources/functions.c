#include "../headers/functions.h"
#include "../headers/constants.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNewNode(HAZ newData) {
  Node *newItem = (Node *)malloc(sizeof(Node));
  if (!newItem) {
    printf(MEMORY_ALLOCATION_ERROR_MESSAGE);
    exit(MEMORY_ALLOCATION_ERROR_CODE);
  }
  newItem->info = newData;
  newItem->left = newItem->right = NULL;
  return newItem;
}

void inorderTraversal(Node *root) {
  if (root == NULL)
    return;
  inorderTraversal(root->left);
  printf("%s %d ", root->info.nev, root->info.info);
  inorderTraversal(root->right);
}

void destroyBinaryTree(Node **root) {
  if (*root == NULL)
    return;
  destroyBinaryTree(&(*root)->left);
  destroyBinaryTree(&(*root)->right);
  free(*root);
  *root = NULL;
}

Node *insert(Node *node, HAZ data) {
  if (node == NULL)
    return createNewNode(data);
  if (node->info.info < data.info)
    node->right = insert(node->right, data);
  else
    node->left = insert(node->left, data);
  return node;
}

Node *minValueNode(Node *node) {
  Node *current = node;
  while (current != NULL && current->left != NULL)
    current = current->left;
  return current;
}

Node *maxValueNode(Node *node) {
  Node *current = node;
  while (current != NULL && current->right != NULL)
    current = current->right;
  return current;
}

Node *deleteNode(Node *root, HAZ data) {
  if (root == NULL)
    return NULL;
  if (root->info.info < data.info) {
    root->right = deleteNode(root->right, data);
  } else if (root->info.info > data.info) {
    root->left = deleteNode(root->left, data);
  } else {
    // node to be deleted
    if (root->right == NULL && root->left == NULL) {
      free(root);
      return NULL;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    } else if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    }

    Node *temp = maxValueNode(root->left);
    root->info = temp->info;
    root->left = deleteNode(root->left, temp->info);
  }
  return root;
}
