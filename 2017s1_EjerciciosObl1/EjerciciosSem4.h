#ifndef EJERCICIOSSEM4_H
#define EJERCICIOSSEM4_H

#include <iostream>
using namespace std;
#include <string.h>

/*
PRE: Recibe un vector de enteros y su largo.
POS: Modifica el vector recibido de tal forma que los elementos queden ordenados de menor a mayor.
     Se deberá utilizar el algoritmo MergeSort para ordenar los elementos.
	
Ejemplo:  
Entrada = ( [5,3,2,4,1], 5 )

SALIDA
Resultado = ( [1,2,3,4,5], 5 )
*/
void OrdenarVecIntMergeSort(int *vector, int largoVector);


#endif