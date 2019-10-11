 void ordenar(int a[], int n) {
   int cambio, i, j, temp, fd = n;

  do {
    if (fd / 1.3 > 1) 
      fd = (int) (fd / 1.3);
    else
      fd = 1;
    
    cambio = 0;

    for (i = 0; i < n - fd; i++) {
      j = i + fd;

      if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        cambio = 1;
      }
    }
  } while((fd != 1) || cambio);
 }