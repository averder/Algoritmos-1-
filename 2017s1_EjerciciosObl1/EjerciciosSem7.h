#ifndef EJERCICIOSSEM7_H
#define EJERCICIOSSEM7_H

#include <iostream>
using namespace std;
#include <string.h>
#include "Definiciones.h"


/*
PRE: recibe un arbol binario
POS: devuelve la altura del arbol recibido.
	 Se define altura de un árbol binario como la cantidad de nodos del camino más largo que va desde la raíz hasta una hoja.

Ejemplo
Entrada: {1,2,3,#,#,4,#,#,5}
   1
  / \
 2   3
    /
   4
    \
     5
Retorno: 4 
*/
int altura(NodoAB* raiz);
int max(int a, int b);
bool esVacia(NodoAB* r);
/*
PRE: Recibe dos arboles binarios.
POS: Retorna true si y solo si los dos arboles son iguales.
(Dos arboles binarios son iguales si tienen los mismos elementos en las mismas posiciones).

Ejemplo
Entrada: {1,2,3}, {1,2,3}
   1     1
  / \   / \
 2   3 2   3
Salida: true

Entrada: {1,3,2}, {1,2,3}
   1     1
  / \   / \
 3   2 2   3
Salida: false
*/
bool sonIguales(NodoAB* p, NodoAB* q);

/*
PRE: Recibe un árbol binario (raiz) y un entero (n)
POS: Retorna true si y solo si existe un camino desde la raíz hasta una hoja que sume sum.
	 El árbol vacío suma 0.

Ejemplo
Entrada: {1,2,3}, 4
   1
  / \
 2   3
Salida: true
*/
bool existeCaminoConSuma(NodoAB* raiz, int sum);
bool esHoja(NodoAB* r);
/*
PRE: Recibe un árbol binario
POS: Retorna true si y solo si el arbol está balanceado.
	 Un arbol está balanceado, si y solo si, para cualquier nodo, la diferencia de altura entre la rama
	 izquierda y la derecha es a lo sumo 1.
	 Notar que si el árbol es vacío entonces está balanceado.

Ejemplo
Entrada: {1,#,2,#,3}
  1
   \
    2
     \
      3
Salida: false
*/
bool esArbolBalanceado(NodoAB* raiz);

/*
PRE: Recibe un árbol binario (a) y un entero (k) mayor a 0.
POS: Retorna una lista con todos los elementos presentes en el nivel k del arbol a ordenados de izquierda 
a derecha. En caso de no existir el nivel retornar NULL.

El árbol no debe ser modificado en la función.

Ejemplo
Entrada: {1,2,3,4,5}, 2
        1
      /   \
     2     3
    / \    
   4   5 
Salida: (2,3)
*/
NodoLista* enNivel(NodoAB* a, int k);

/*
PRE: Recibe un árbol (a) y dos enteros (desde y hasta) mayores a 0.
POS: Retorna la cantidad de nodos ubicados entre los niveles desde y hasta del árbol a.

En caso de no haber ningún nodo entre los niveles dados o que éstos no sean válidos (desde>hasta), se deberá 
retornar 0. Recordar que (en caso de existir) la raíz de un árbol ocupa el nivel 1.

Ejemplo
Entrada: {1,2,3,4,5,6,#}, desde=2, hasta=4
        1
      /   \
     2     3
    / \   /     
   4   5 6   
Salida: 5
*/
int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta);

/*
PRE: Recibe un árbol binario de busqueda de enteros y un entero (x).
	 x pertenece al árbol.
POS: Retorna la lista con camino de la raíz hasta donde se encuentra el elemento x en el árbol.

Ejemplo
Entrada: {8,3,10,1,5,9,13}, 9
        8
      /   \
     3     10
    / \   /  \  
   1   5 9    13
Salida: (8,10,9)
*/
NodoLista* camino(NodoAB* arbol, int x);

/*
PRE: recibe un arbol binario, y un entero k mayor o igual a 0
POS: retorna un nuevo árbol en el cual cada nodo Invertirá sus punteros de izquierda y derecha, "espejando" el árbol 
     solo se consideraran los elementos en niveles menores o iguales a k
	 si k es mayor o igual a la altura del árbol, se deberá retornar una copia completa Invertida.
	 si k=0, retornará NULL
	 el arbol recibido por parametro no debe ser modificado

Ejemplo:
Entrada: {1,2,3,4,5,6,7,8,9}, 3
         1
       /    \
     2       3
    /  \    /  \
   4    5  6    7
 /  \ 
8    9
Retorno:
         1
       /    \
     3       2
    /  \    /  \
   7    6  5    4
*/
NodoAB* invertirHastak(NodoAB* a, int k); 

/*
PRE: recibe un arbol binario de búsqueda a, no vacío
POS: elimina el dato que se encuentra en la raíz de a.
	 Luego de la función el arbol debe seguir siendo una arbol binario de busqueda
	 la forma del arbol resultante no es importante (siempre que sea un ABB)

Ejemplo: {3,2,6}
   3
  / \
 2   6
Resultado: {2,#,6} 
*/
void borrarNodoRaiz(NodoAB * & A);
void insertarSubABB(NodoAB* &r1, NodoAB* r2);
/*
PRE: Recibe un árbol binario de búsqueda (ABB).
POS: Devuelve true si existen dos naturales en el ABB tales que sumados son equivalentes a n.

Ejemplo
Entrada: {5,3,7,1,4,6,#}, 8
	   5 
	  / \  
	 3   7 
	/\	 /
   1  4 6  

Salida: true
*/
bool SumaABB(NodoAB* a, int n);
void deleteLista(NodoLista* a);
NodoLista* menoresNABB(NodoAB* a, int n);
/*
PRE: Recibe un árbol binario de búsqueda (ABB) y n natural perteneciente o no al ABB.
POS: Dado un número n, computa su sucesor tal que sea perteneciente al ABB.
	 Es decir el menor número tal que es mayor que n y pertenece al árbol.
	 Si no se encuentra el sucesor devuelve -1.
	 No se pueden usar estructuras auxiliares (vector, lista, otro arbol, etc).

Ejemplo 1
Entrada: {5,3,7,1,4,6,#}, 3
   5
 /    \
 3     7
/\	  /
1 4 6

Salida: 4
----------
Ejemplo 2
Entrada: {5,3,7,1,4,6,#}, 2
   5 
 /   \
 3     7
/\	  /
1 4 6

Salida: 3
----------
Ejemplo 2
Entrada: {5,3,7,1,4,6,#}, 7
   5
 /    \
3      7
/\	  /
1 4  6

Salida: -1
*/
int Sucesor(NodoAB* a, int n);
int minSucesor(int a, int b);

/*
PRE: recibe un arbol binario
POS: devuelve el nivel con mas nodos, desde el nivel 1 hasta nivelHasta.
	 
En caso de que el árbol sea vacio se debera retornar cero.
Ante un empate debera retornar el número de nivel mas pequeño.

Ejemplo
Entrada: {1,2,3,#,#,4,#,#,5}
   1
  / \
 2   3
    /
   4
    \
     5
Retorno: 2

*/
int nivelMasNodos(NodoAB* raiz, int nivelHasta);
int cantNodosNivel(NodoAB* raiz, int nivel);
/*
Implemente un procedimiento void borraPares(NodoAB *&arbol); que dado un árbol binario de busqueda
a elimine todos los elementos pares del mismo, modificando al árbol pasado por parámetro.

Ejemplos:
borrarPares({4,2,6,1,3,5,7}) = {5,3,7,1}
*/
void borrarPares(NodoAB* & a);



/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano),
POS: devuelve la altura del arbol recibido.
	 Se define altura de un árbol binario como la cantidad de nodos del camino más largo que va desde la raíz hasta una hoja.

Ejemplo
Entrada: {{1,2,5,#,#,3,#,4,#,#}}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: 3 
*/
int alturaAG(NodoAG* raiz);
bool esVacio(NodoAG* raiz);

/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano) 
POS: Retorn la suma los valores de los niveles pares y resta los valores de los impares.
	 La  raíz se encuentra en el nivel 1.

Ejemplo
Entrada: {{1,2,5,#,#,3,#,4,#,#}}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: 3
 */
int SumaPorNiveles(NodoAG* raiz);

	
/*
PRE: Recibe un arbol general sin repetidos implementado como un arbol binario (primer hijo – siguiente hermano) 
	 y una lista de enteros  
POS: Retorna true si y sólo si la lista es un prefijo de algún camino del árbol general, comenzando desde la raíz.
	 La lista vacía es prefijo de cualquier camino (incluso del camino vacío, si el árbol es vacío).
	 No se permite usar funciones o procedimientos auxiliares en este ejercicio.

Ejemplo 1
Entrada: {{1,2,5,#,#,3,7,4,#,#}},{1,2,5}
    1
   / 
  2 - 3 - 4
 /	  |
5     7   

Retorno: true
------------------------
Ejemplo 2
Entrada: {{1,2,5,#,#,3,#,4,#,#}},{1,2,3,4}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: false
------------------------
Ejemplo 3
Entrada: {{1,2,5,#,#,3,#,4,#,#}},{1,4}
    1
   / 
  2 - 3 - 4
 /   
5        

Retorno: true
------------------------
Ejemplo 4
Entrada: {{1,2,5,#,#,3,#,4,#,#}},{6,8}
    1   -   6
   /       /
  2 - 3   7 - 8
 /   
5        

Retorno: true
 */
bool EsPrefijo(NodoAG *a, NodoLista *l);


/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano) 
	 y un número.
POS: Retorna una lista con los datos en el camino de la raiz al número dado.
	 Si el número está repetido retorna el camino que incluya a los primeros hermanos.
     Si el número no se encuentra en el árbol retorna NULL.
	

	Ejemplo:    ENTRADA   
				ARBOL              DATO 5;
				  1
				  |
				  2 -> 3
				  |    |
				  4	   5
				
				SALIDA  1->3->5;
				
*/
NodoLista* CaminoAG(NodoAG *a, int dato);
void insertarPrincipio2(NodoLista* &l, int valor);
int largoLista2(NodoLista* l);

/*
PRE: Recibe un arbol general implementado como un arbol binario (primer hijo – siguiente hermano).
POS: Retorna el nivel con mas nodos del AG. En caso de haber mas de un nivel con la misma cantidad 
	 de nodos retorna el menor. La  raíz se encuentra en el nivel 1.
	 NOTA: Esta operación se puede realizar en O(n).

		Ejemplo:    ENTRADA   
				ARBOL              
				  1					Nivel 1
				  |
				  2 -> 3			Nivel 2
				  |    |
				  4	   5			Nivel 3
				
				SALIDA  Nivel 2;
*/	

int NivelConMasNodosAG(NodoAG * arbolGeneral);
void cargarVector(int* vector, NodoAG* arbolGeneral, int nivel);
int pMax(int* vector, int altura);
#endif