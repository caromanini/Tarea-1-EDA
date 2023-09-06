# Instrucciones de ejecución
Para utilizar el programa, se deben seguir los siguientes pasos: 

1. En el directorio "Tarea-1-EDA-main", crear otro directorio llamado build con el comando:

```bash 
mkdir build
```
2. Ir al directorio build y crear cmake con comando: 

```bash
cmake ..
```
3. Actualizar el Makefile con comando:

```bash
make
```
4. Para ejecutar, ingresar:

```bash
./sort_ruts ruts_100.txt M
```

En el paso 4, sort_ruts corresponde al nombre del archivo donde se encuentra el codigo, ruts_100.txt el nombre del archivo donde se encuentran los datos y M el algoritmo con el que se va a ordenar. 

## Opciones de algoritmos
- Insertion Sort (I)
- Merge Sort (M)
- Radix Sort (R)
- Quick Sort (Q)