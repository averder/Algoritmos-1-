#ifndef EJERCICIOSSEM3_H
#define EJERCICIOSSEM3_H

#include <iostream>
using namespace std;
#include <string.h>

/*
PRE: Recibe un string palabra.
POS: Retorna un nuevo string con el case Invertido. Es decir si un caracter es lowercase 
     debe pasar a ser uppercase y viceversa. 
	 Se pueden utilizar funciones auxiliares, pero no funciones de bibliotecas 
	 de C/C++ (como strcpy, toupper, tolower etc.).

Ejemplo 1
Entrada: "hola"
Retorno: "HOLA"

Ejemplo 2
Entrada: "Write IN C"
Retorno: "wRITE in c"
*/



char* InvertirCase(char* palabra);
int largoStr(char* palabra);
char** copiaListaStr(char** listPalabras, int largoVec);
char* copiarStr(char* palabra, int largo);

/*
PRE:  recibe un mapa representado por una matriz, de dimensiones col x fil, en la cual 'A' representa un lugar donde hay agua, y 'T' donde hay tierra
POS:  devuelve la cantidad de islas del mapa. Una isla es un conjunto de tierras adyacentes, ortogonal o diagonal (puede ser una sola).
      Los indices del mapa recibido se deben usar como mapa[c][f] donde c y f corresponden a la columna y fila respectivamente.
	  La matriz recibida debe ser retornada sin cambios.

Ejemplo 1
Entrada: (['T','A','T','A'], 4, 1)
Retorno: 2

Ejemplo 2
Entrada: (['T','T','A'
		   'A','A','T'
		   'A','A','A'
		   'T','T','A'], 3, 4)
Retorno: 2
*/
int islas(char** mapa, int col, int fil);
void borrarIsla(char** mapa, int col, int fil, int pCol, int pFil);
bool dentro(int col, int fil, int u, int v);

/*
PRE: Recibe un vector de strings, la cantidad de strings que hay en el vector y el substring a buscar.
POS: Devuelve la cantidad de ocurrencias de ese substring en los strings del vector.
	 El subtring a buscar se puede encontrar contenido dentro del string (con caracteres antes y después) y 
	 solamente se debe contar una vez por string.
	 El vector recibido y los strings que contiene no deberán ser modificados.
	 Se pueden utilizar funciones auxiliaries pero no se pueden usar las funciones de las bibliotecas del sistema (ejemplo strlen, strcpy, etc).

Ejemplo 1
Entrada: vecStr=['chauhcar','chanu','cha'] substr="chau"
Salida: 1

Ejemplo 2
Entrada: vecStr=['so','l'] substr="sol"
Salida: 0

Ejemplo 3
Entrada: vecStr=['holahola','hola'] substr="hola"
Salida: 2
*/
unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr);
unsigned int compararPalabras(char* palabra, char* sub);

/*
PRE: recibe un vector de strings, y su largo
POS: retorna un nuevo vector, que contiene los strings de vecStr ordenados. Este nuevo vector, no debe compartir memoria con vecStr.
	 los strings se deberán ordenar, comparando caracter a caracter, según la tabla ASCII.
	 El vector recibido y los strings que contiene no deberán ser modificados.
	 Se pueden usar funciones auxiliares, que deberán implementar. 
	 No se pueden usar las funciones de las bibliotecas del sistema (ejemplo strlen, strcpy, etc).
	 NOTA: recordar que un string es un puntero al primer caracter de una serie de caracteres consecutivos, y termina en '\0'

Ejemplo 1: 
Entrada: (["hola","tierra","arriba"], 3)
Retorno: (["arriba","hola","tierra"])

Ejemplo 2:
Entrada: (["134","122","122","567"], 4)
Retorno: (["122","122","134","567"])
*/
char **ordenarVecStrings(char **vecStr, int largoVecStr);

void bubbleSort(char **vec, int n);
bool compararStr(char* a, char*b);

/*
PRE: Recibe dos vectores ordenados ascendentemente v1 y v2 y sus respectios largos l1 y l2
POS: Retorna un nuevo vector ordenado con los elementos de v1 y v2. 
	 Los vectores pueden contener elementos repetidos, y deberán aparecer todos ellos.
	 El vector retornado no debe compartir memoria.

Ejemplo
Entrada: (1,3,5,6), (2,3,4)
Lista resultado: (1,2,3,3,4,5,6)
*/
int* intercalarVector(int* v1, int* v2, int l1, int l2);

/*
PRE: Recibe 2 vectores v1 y v2, no ordenados, y sus respectios largos l1 y l2
POS: Retorna true si y solo si v1 es un subconjunto de v2
	 Los vectores pueden contener elementos repetidos.
	 Nota: el vector vacío será considerado como el conjunto vacío. Recordar que el conjunto vacío por definición es subconjunto de cualquier otro conjunto.

Ejemplo 1:
Entrada: (5,2,2,1), (1,2,3,4,5,6)
Salida: TRUE

Ejemplo 2:
Entrada: (), (1, 2, 3)
Salida: TRUE

Ejemplo 3:
Entrada: (1, 1, 1, 4, 2) (1, 2, 5)
Salida: FALSE

*/
bool subconjuntoVector(int* v1, int* v2, int l1, int l2);
bool compararNum(int e, int* vec, int largo);
/*
PRE: Recibe un string str y un caracter separador
POS: Retorna un array de string que contiene los substrings que se encuentran en str entre los separadores.
	 Descarta los substrings vacíos. Si no hay substrings retorna NULL.
	 Se debe setear el parámetro largoRet (no leer) con el tamaño del vector retornado.
	 Se pueden usar las funciones de la biblioteca string.h (por ejemplo strtok/strtok_s)

Ejemplo 
Entrada: "ab:cdef:gh"
Salida: ['ab', 'cdef', 'gh']

Ejemplo 
Entrada: ":cdef:gh"
Salida: ['cdef', 'gh']

Ejemplo 
Entrada: "ab:cdef:"
Salida: ['ab', 'cdef']

Ejemplo
Entrada: "::"
Salida: NULL
*/
char** splitStr(char* str, char separador, int &largoRet);
int cantToKens(char* str, char separador);

#endif