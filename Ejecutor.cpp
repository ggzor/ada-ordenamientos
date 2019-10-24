#include <iostream>
#include <chrono>
#include <unistd.h>

extern void ordenar(int a[], int n);

void imprimirDuracion(int64_t nanosegundos) {
  int64_t factores[] = { 
    1000, // Microsegundos
    1000, // Milisegundos
    1000, // Segundos
    60,   // Minutos
    60,   // Horas
    24    // Días
  }; 
  char nombres[][3] = { "ns", "us", "ms", "s", "m", "h", "d" };

  int64_t valores[7];
  int i = 0;

  for (int64_t factor : factores) {
    valores[i] = nanosegundos % factor;
    nanosegundos /= factor;
    i++;
  }
  valores[i] = nanosegundos;

  bool noCeroEncontrado = false;
  for (int j = 6; j >= 0; j--) {
    if (valores[j] != 0)
      noCeroEncontrado = true;

    if (noCeroEncontrado) {
      std::cout << valores[j] << nombres[j] << " ";
    }
  }

  std::cout << std::endl;
}

void imprimirFechaActual() {
  std::chrono::high_resolution_clock reloj;
  time_t fecha = reloj.to_time_t(reloj.now());
  std::cout << std::ctime(&fecha) << std::endl;
}

int *cargarArchivo(const char *nombre, int cantidad) {
  int *valores = (int *)malloc(sizeof(int) * cantidad);
  FILE *archivo = fopen(nombre, "r");
  
  for (int i = 0; i < cantidad; i++)
    fscanf(archivo, "%d", valores + i);

  fclose(archivo);
  return valores;
}

void guardarArchivo(int *a, int cantidad, const char *nombre) {
  char nombreArchivo[100];
  sprintf(nombreArchivo, "Resultados_%s_%d.txt", nombre, cantidad);

  FILE *archivo = fopen(nombreArchivo, "w");

  for (int i = 0; i < cantidad; i++)
    fprintf(archivo, "%d ", a[i]);
  
  fclose(archivo);
}

int main(int argc, char **argv) {
  if (argc > 1) {
    std::chrono::high_resolution_clock reloj;

    int cantidad;
    sscanf(argv[1], "%*[^0-9]%d", &cantidad);

    #ifdef __linux__
      char *nombreOrdenamiento = &argv[0][2];
    #else
      char *nombreOrdenamiento = argv[0];
    #endif
  
    std::cout << "Se ejecutará el ordenamiento " << nombreOrdenamiento << " del archivo \"" << argv[1] << "\". ";
    imprimirFechaActual();
    std::cout << "Cantidad de números: " << cantidad << std::endl;

    std::cout << "Comenzando carga del archivo." << std::endl;
    auto inicio = reloj.now();
    int *arreglo = cargarArchivo(argv[1], cantidad);
    auto fin = reloj.now();
    std::cout << "Carga finalizada en ";
    imprimirDuracion((fin - inicio).count());

    std::cout << "Comenzando ordenamiento de los datos. ";
    imprimirFechaActual();
    inicio = reloj.now();
    ordenar(arreglo, cantidad);
    fin = reloj.now();
    std::cout << "Ordenamiento finalizado en ";
    imprimirDuracion((fin - inicio).count());

    std::cout << "Guardando archivo. ";
    imprimirFechaActual();
    inicio = reloj.now();
    guardarArchivo(arreglo, cantidad, nombreOrdenamiento);
    fin = reloj.now();
    std::cout << "Escritura finalizada en ";
    imprimirDuracion((fin - inicio).count());
  } else {
    std::cout << "No se proporcionaron los argumentos suficientes para ejecutar el ordenamiento." << std::endl;
  }
}