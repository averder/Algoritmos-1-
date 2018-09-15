#ifndef EJERCICIOSSEM1_H
#define EJERCICIOSSEM1_H

#include <iostream>
using namespace std;
#include <string.h>


/*	
	Problema A+B
	Pre:
	Pos: Retorna la suma de a+b
*/
int Suma(int a, int b);


/*
PRE: recibe tres numero enteros positivos. desde <= hasta
POS: imprime la tabla del numero 'tablaDel' entre los números 'desde' y 'hasta' inclusive, por consola.
	 la tabla del numero se debe mostrar en una linea y cada ecuacion se debe separar por punto y coma.

Ejemplo 1
Entrada: (2, 0, 4)
Salida: 0*2=0;1*2=2;2*2=4;3*2=6;4*2=8
*/
void TablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta);


#endif