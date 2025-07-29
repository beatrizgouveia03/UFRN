#include <stdio.h>

int main(void) {
  int n;
  int i, j, x, y;

  scanf("%d", &n);

  int piramide[n][n];

  if (n % 2 == 0) {
    x = n / 2;
  } else {
    x = n / 2 + 1;
  }

  printf("%d\n", x);

  for (y = 0; y < x; y++) {

    for (i = y; i < n-y; i++) {
      for (j = y; j < n-y; j++) {
        if ((i == y) || (j == y) || (i == n - 1 - y) ||
            (j == n - 1 - y)) {
          piramide[i][j] = y + 1;
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%d", piramide[i][j]);
    }
    printf("\n");
  }

  return 0;
}