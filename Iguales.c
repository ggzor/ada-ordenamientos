#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char c1, c2;
  FILE *f1, *f2;
  int i = 1;

  if (argc == 3) {
    f1 = fopen(argv[1], "rb");
    f2 = fopen(argv[2], "rb");

    if (!(f1 && f2)) {
      printf("No se pudieron abrir ambos archivos '%s' y '%s'.\n", argv[1], argv[2]);
      return -1;
    }

    while (!feof(f1) && !feof(f2)) {
      fread(&c1, 1, 1, f1);
      fread(&c2, 1, 1, f2);

      if (c1 != c2) {
        printf("Se encontró una diferencia en el byte %d de los archivos '%s' y '%s'.\n", i, argv[1], argv[2]);
        return -1;
      }

      i++;
    }

    if (feof(f1) && feof(f2)) {
      printf("Los archivos '%s' y '%s' son iguales!", argv[1], argv[2]);
      return 0;
    } else {
      printf("Los archivos '%s' y '%s' difieren en longitud.\n", argv[1], argv[2]);
    }
  } else {
    printf("Se requieren exactamente dos nombres de archivos para hallar si son iguales.\n");
  }

  return -1;
}