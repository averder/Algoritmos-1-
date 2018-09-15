#ifndef PRUEBASAUXSEM7_H
#define PRUEBASAUXSEM7_H

#include <sstream>
#include <string>
#include <iostream>
#include "FuncAux.h"
#include "EjerciciosSem7.h"
#include "Definiciones.h"

bool PruebaAltura(char* inputTree, int output, int &nroPrueba);
bool PruebaSonIguales(char* inputArbol1, char* inputArbol2, bool output, int &nroPrueba);
bool PruebaExisteCaminoConSuma(char* inputArbol, int suma, bool output, int &nroPrueba);
bool PruebaEsArbolBalanceado(char* inputArbol, bool output, int &nroPrueba);
bool PruebaEnNivel(char* inputArbol, int k, char* output, int &nroPrueba);
bool PruebaCantNodosEntreNiveles(char* inputArbol, int desde, int hasta, int output, int &nroPrueba);
bool PruebaCamino(char* inputArbol, int x, char* output, int &nroPrueba);
bool PruebaInvertirHastak(char* inputArbol, int k, char* output, int &nroPrueba);
bool PruebaBorrarNodoRaiz(char* inputArbol, char *output, int &nroPrueba);
bool PruebaSumaABB(char* inputArbol, int n, bool output, int &nroPrueba);
bool PruebaSucesorABB(char* inputArbol, int n, int output, int &nroPrueba);
bool PruebaNivelMasNodos(char* inputArbol, int nivelHasta, int output, int &nroPrueba);
bool PruebaBorrarPares(char *inputABB, char *outputABB, int &nroPrueba);

bool PruebaAlturaAG(char *inputTree, int output, int &nroPrueba);
bool PruebaSumaPorNiveles(char *inputTree, int output, int &nroPrueba);
bool PruebaEsPrefijo(char *inputTree,char *inputList, bool output, int &nroPrueba);
bool PruebaCaminoAG(char *inputTree,int dato, char* outputList, int &nroPrueba);
bool PruebaNivelConMasNodosAG(char *inputTree, int output, int &nroPrueba);

#endif