#include <stdlib.h>

void merge(int a[], int l, int m, int u) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = u - m;

  int *L = (int *) malloc(sizeof(int) * n1);
  int *U = (int *) malloc(sizeof(int) * n2);

  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  
  for (j = 0; j < n2; j++)
    U[j] = a[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2)
    a[k++] = L[i] <= U[j] ? L[i++] : U[j++];

  while (i < n1)
    a[k++] = L[i++];

  while (j < n2)
    a[k++] = U[j++];

  free(L);
  free(U);
}

void mergeSort(int a[], int l, int u) {
  int medio;

  if (l < u) {
    medio = l + (u - l) / 2;

    mergeSort(a, l, medio);
    mergeSort(a, medio + 1, u);
    merge(a, l, medio, u);
  }
}

void ordenar(int a[], int n) {
  mergeSort(a, 0, n - 1);
}
