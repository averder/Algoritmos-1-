#ifndef COLA_ARRAY_H
#define COLA_ARRAY_H

/* IMPLEMENTACION DE COLA CON ARRAY Y FONDO
*/

#include <iostream>
#include <assert.h>
using namespace std;

struct colaArray;
typedef colaArray *ColaArray;

/*
PRE:
POS: devuelve una ColaArray vacia, de dimension t
*/
ColaArray crearColaArray(int t);
/*
PRE:
POS: destruye ColaArray c, libera memoria
*/
void destruir(ColaArray &c);
/*
PRE: 
POS: Se vacia la cola
*/
void vaciar(ColaArray c);
/*
PRE: 
POS: Retorna true si la cola es vacia
*/
bool esVacia(ColaArray c);
/*
PRE: 
POS: retorna true, si la cola esta llena
*/
bool estaLlena(ColaArray c);
/*
PRE: cola no es vacia
POS: devuelve el elemento de la primera posicion de la cola
*/
void *frente(ColaArray c);
/*
PRE: cola no es vacia
POS: devuelve el ultimo elemento de la cola,  y lo elimina
*/
void desencolar(ColaArray c);
/*
PRE: cola no esta llena
POS: agrega el dato en la ultima posicion de la cola
*/
void encolar(ColaArray c, void * dato);


#endif