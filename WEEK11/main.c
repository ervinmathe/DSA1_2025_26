#include "./headers/functions.h"
#include <stdio.h>

int main() {
  FILE *file = fopen("input.txt", "r");
  if (file == NULL) {

    printf("Nem lehetett a file-t megnyitni");
    return 1;
  }

  int n;
  fscanf(file, "%d", &n);

  HAZ temp;
  Node *root = NULL;
  while (fscanf(file, "%s\n%d", temp.nev, &temp.info) == 2) {
    root = insert(root, temp);
  }

  printf("Inorder: ");
  inorderTraversal(root);
  printf("\n");

  fclose(file);
  destroyBinaryTree(&root);
  return 0;
}
