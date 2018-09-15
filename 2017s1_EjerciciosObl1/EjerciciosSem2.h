#ifndef EJERCICIOSSEM2_H
#define EJERCICIOSSEM2_H

#include <iostream>
using namespace std;
#include <string.h>


/*
PRE: Recibe dos variables (numerador y denominador). Denominador != 0
POS: Imprime la fraccion simplificada. Si nominador == 0 entonces no se simplifica e imprime la fraccion recibida.

Ejemplo 1
Entrada: n=30 d=12 (30/12)
Salida: 5/2

Ejemplo 2
Entrada: n=10 d=1 (10/1)
Salida: 10/1
*/
void simplificar(int n, int d);

int mcd(int a, int b);

/*
PRE: Recibe un vector de enteros (formado únicamente por los números 1, 2 y 3) y su largo
POS: Devuelve la cantidad de ocurrencias de la subsecuencia [1,2,3] (elementos consecutivos en la secuencia) en ese vector. 
	 Se deben tomar en cuenta las secuencias como 1,2,2,3 o 1,1,2,2,2,2,3,1,2,2,3, etc., donde pueden aparecer varios números 1 juntos, varios 2 y varios 3.
	 
Ejemplo 1
Entrada: [1,2,3,1,2,2,3]
Salida: 2

Ejemplo 2
Entrada [1,2,2,2,2,2,3,1,2,3]
Salida: 2
*/
int ocurrencias123Repetidos(int* vector, int largo);

/*
PRE: Recibe un numero natural n.
POS: Pide el ingreso de n numeros enteros (por cin) y devuelve el mayor de ellos.

Ejemplo 1
Entrada: 3
Se piden por consola 3 numeros
Se ingresan los numeros 7, 0, 3
Retorno: 7

Ejemplo 2
Entrada: 1
Se ingresa: 0
Retorno: 0
*/
int MaximoNumero(unsigned int n);

/*
PRE: recibe un vector de int, y su largo
POS: modifica la posición de los elementos en el vector recibido de tal forma que los elementos 
     queden ordenados de menor a mayor (forma ascendente).

Ejemplo 1: 
Entrada: ([], 0)
Vector resultante: ([])

Ejemplo 2:
Entrada: ([5,4,2], 3)
Vector resultante: ([2,4,5])
*/
void ordenarVecInt(int *vec, int largoVec);

#endif