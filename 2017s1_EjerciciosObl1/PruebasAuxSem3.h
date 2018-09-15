#ifndef PRUEBASAUXSEM3_H
#define PRUEBASAUXSEM3_H

#include "FuncAux.h"
#include "EjerciciosSem3.h"


bool PruebaInvertirCase(char *substr, char* output, int &nroPrueba);
bool PruebaIslas(char* datosMapa, int col, int fil, int output, int &nroPrueba);
bool PruebaOcurrenciasSubstring(char *stringVecStr, char *substr, int output, int &nroPrueba);
bool PruebaOrdenarVecStr(char* vecStr, char* output, int &nroPrueba);
bool PruebaIntercalarVector(char* vector1, char* vector2, char* vectorOutput, int &nroPrueba);
bool PruebaSubconjuntoVector(char* vector1, char* vector2, bool output, int &nroPrueba);
bool PruebaSplitStr(char* entrada, char separador, char* output, int &nroPrueba);

#endif