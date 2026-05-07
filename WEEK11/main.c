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
  printf("\n\n");

  Node *tolvaj = root;
  printf("A tolvaj utja: ");
  while (tolvaj != NULL) {
    printf("%s %d ", tolvaj->info.nev, tolvaj->info.info);
    tolvaj = tolvaj->right;
  }

  fclose(file);
  destroyBinaryTree(&root);
  return 0;
}
