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

  printf("%d", n);

  fclose(file);
  return 0;
}
