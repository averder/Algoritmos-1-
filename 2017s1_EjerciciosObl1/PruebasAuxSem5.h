#ifndef PRUEBASAUXSEM5_H
#define PRUEBASAUXSEM5_H

#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#include "FuncAux.h"
#include "EjerciciosSem5.h"
#include "Definiciones.h"

bool PruebaEliminarNesimoDesdeElFinal(char* inputLista, int n, char* output, int &nroPrueba);
bool PruebaListaOrdenadaInsertionSort(char* inputLista, char* output, int &nroPrueba);
bool PruebaListaOrdenadaSelectionSort(char* inputLista, char* output, int &nroPrueba);
bool PruebaInvertirParcial(char* inputLista, char* output, int &nroPrueba);
bool PruebaIntercalarIter(char* inputLista1, char* inputLista2, char* output, int &nroPrueba);
bool PruebaIntercalarRec(char* inputLista1, char* inputLista2, char* output, int &nroPrueba);
bool PruebaInsComFin(char* inputLista, int n, char* output, int &nroPrueba);
bool PruebaEXOR(char* inputLista1, char* inputLista2, char* output, int &nroPrueba);
bool PruebaEliminarDuplicadosListaOrdenadaDos(char* inputLista, char* output, int &nroPrueba);
bool PruebaPalindromo(char* inputLista, bool output, int &nroPrueba);
bool PruebaEliminarSecuencia(char* inputListaOriginal, char* inputSecuenciaAEliminar, char* output, int &nroPrueba);
bool PruebaMoverNodo(char* inputListaOriginal, unsigned int inicial, unsigned int final, char* output, int &nroPrueba);

#endif