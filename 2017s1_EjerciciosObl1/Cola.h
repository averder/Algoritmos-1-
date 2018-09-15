#ifndef COLA_H
#define COLA_H

/* IMPLEMENTACION DE COLA CON ARRAY Y FONDO
*/

#include <iostream>
#include <assert.h>
using namespace std;

struct colaArray;
typedef colaArray *Cola;

/*
PRE:
POS: devuelve una cola vacia, de dimension t
*/
Cola crearCola(int t);
/*
PRE:
POS: destruye cola c, libera memoria
*/
void destruir(Cola &c);
/*
PRE: 
POS: Se vacia la cola
*/
void vaciar(Cola c);
/*
PRE: 
POS: Retorna true si la cola es vacia
*/
bool esVacia(Cola c);
/*
PRE: 
POS: retorna true, si la cola esta llena
*/
bool estaLlena(Cola c);
/*
PRE: cola no es vacia
POS: devuelve el elemento de la primera posicion de la cola
*/
void *frente(Cola c);
/*
PRE: cola no es vacia
POS: devuelve el ultimo elemento de la cola,  y lo elimina
*/
void desencolar(Cola c);
/*
PRE: cola no esta llena
POS: agrega el dato en la ultima posicion de la cola
*/
void encolar(Cola c, void * dato);


#endif