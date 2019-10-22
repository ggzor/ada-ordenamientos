from pathlib import Path
from random import seed, randrange
from datetime import datetime
from sys import argv

seed(31 + 5 + 99)
numeroMaximo = 100_000
medidaSeccion = 10_000_000
formatoArchivo = 'Numeros_{}.txt'

horaInicio = datetime.now()

def obtenerBloques(n, medidaBloque):
    while n > 0:
        if n >= medidaBloque:
            yield medidaBloque
            n -= medidaBloque
        else:
            yield n
            n = 0

def generarNumeros(n):
    with open(formatoArchivo.format(n), 'w') as archivo:
        i = 0
        for medida in obtenerBloques(n, medidaSeccion):
            archivo.write(f'{" ".join(map(lambda _: str(randrange(numeroMaximo)), range(medida)))} ')
            i += medida

            if i % 10_000_000 == 0:
                print(f'{i} - {datetime.now() - horaInicio}')        

if len(argv) > 1:
    n = int(argv[1])

    if Path(formatoArchivo.format(n)).exists():
        print(f'El archivo con {n} números aleatorios ya existe. Saliendo del programa.')
        exit(0)

    print(f'Generando {n} números aleatorios (inicio {horaInicio}): ')
    
    generarNumeros(n)
    
    horaFin = datetime.now()
    delta = horaFin - horaInicio
    print(f'Terminando generación de números aleatorios (duracion = {delta})')
