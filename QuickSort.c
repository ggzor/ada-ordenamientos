// Ordenamiento Quicksort
void quicksort(int a[], int l, int u) {
  int i = l, j, p, temp;

  if (l < u) {
    p = a[u];

    // Separación de elementos con respecto al pivote
    for (j = l; j < u; j++) {
      if (a[j] < p) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++;
      }
    }

    // Colocación del pivote en la posición final
    temp = a[i];
    a[i] = a[u];
    a[u] = temp;

    // Casos recursivos
    quicksort(a, l, i - 1);
    quicksort(a, i + 1, u);
  }
}

void ordenar(int a[], int n) {
  quicksort(a, 0, n - 1);
}