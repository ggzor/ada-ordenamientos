#include <stdlib.h>

int comparar(const void *a, const void *b) { 
  return  *(((int *) a)) - *((int *)b);
}

// Ordenamiento Estándar
void ordenar(int a[], int n) {
  qsort(a, n, sizeof(int), comparar);
}
