#include "EjerciciosSem3.h"

#ifndef EJERCICIOSSEM3_CPP
#define EJERCICIOSSEM3_CPP

char* InvertirCase(char* palabra)
{
	char* convertir = new char[largoStr(palabra)+1];
	for (int i = 0; i<largoStr(palabra) + 1; i++)
	{
		if (palabra[i] >= 65 && palabra[i] <= 95)
			convertir[i] = palabra[i] + 32;
		else if (palabra[i] >= 97 && palabra[i] <= 122)
			convertir[i] = palabra[i] - 32;
		else {
			convertir[i] = palabra[i];
		}
	}
	return convertir;
}



int islas(char** mapa, int col, int fil) {
	int cont = 0;
	char** mapAux = copiaListaStr(mapa, col);
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < fil; i++) {
			if (mapAux[j][i] == 'T') {
				cont++;
				borrarIsla(mapAux, col, fil, j, i);
			}
		}
		delete[] mapAux[j];
	}
	delete[] mapAux;
	return cont;
}

void borrarIsla(char** mapa, int col, int fil, int pCol, int pFil) {
	mapa[pCol][pFil] = 'A';
	int vectPosC[8] = { 1,1,0,-1,-1,-1,0,1 };
	int vectPosF[8] = { 0,1,1,1,0,-1,-1,-1 };
	int u, v;
	for (int k = 0; k < 8; k++) {
		u = pCol;
		v = pFil;
		u += vectPosC[k];
		v += vectPosF[k];
		if (dentro(col, fil, u, v) && mapa[u][v] == 'T') {
			borrarIsla(mapa, col, fil, u, v);
		}
	}
}

bool dentro(int col, int fil, int u, int v) {
	return u >= 0 && u < col &&  v >= 0 && v < fil;
}


unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr) {
	int cont = 0;
	for (int i = 0; i < largoVecStr; i++)
	{
		cont += compararPalabras(vecStr[i], substr);
	}
	return cont;
}

unsigned int compararPalabras(char* palabra , char* sub) {
	int j = 0;
	int cont = 0;
	if (largoStr(palabra) >= largoStr(sub)) {
		for (int i = 0; i< largoStr(palabra); i++)
		{
			if (palabra[i] == sub[j]) {
				j++;
			}
			if (sub[j] == '\0') {
				cont++;
				return cont;
			}
		}
	}
	return cont;
}
char **ordenarVecStrings(char **vecStr, int largoVecStr)
{	
	char** aux = copiaListaStr(vecStr, largoVecStr);
	bubbleSort(aux, largoVecStr);
	return aux;
}

void bubbleSort(char **vec, int n) {
	char* aux = NULL;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j <n ; j++)
		{
			if(compararStr(vec[i],vec[j])){
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}


bool compararStr(char* a, char*b) {
	for (int i = 0; a != '\0' && b != '\0' ; i++)
	{
		if (a[i] > b[i]) {
			return true;
		}
	    if (a[i] < b[i]) {
			return false;
		}
	}
	return false;
}


int largoStr(char* vec) {
	int i = 0;
	while (vec[i])
	{
		i++;
	}
	return i;
}

char** copiaListaStr(char** listPalabras, int largoVec) {
	if (largoVec > 0) {
		char** aux = new char*[largoVec];
		for (int i = 0; i < largoVec; i++)
		{
			int largoPalabra = largoStr(listPalabras[i]);
			aux[i] = copiarStr(listPalabras[i], largoPalabra);
		}
		return aux;
	}
		return NULL;
}

char* copiarStr(char* palabra, int largo) {
	char* aux = new char[largo + 1];
	for (int i = 0;i < largo; i++)
	{
		aux[i] = palabra[i];
	}
	aux[largo] = '\0';
	return aux;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	int i = 0; int j = 0; int k = 0;
	int* vec = NULL;
	if (l1 == 0 && l2 == 0)
	{
		return vec;
	}
	else {
		if (l1 == 0 && l2 !=0) //puedo borrar l2 si es cero da false si es distinto de cero da true. !l1 da true cuando es igual a cero 
		{
			int* vec = new int [l2];
			for (int i = 0; i < l2; i++)
			{
				vec[i] = v2[i];
			}
			return vec;
		}
		else if (l2 == 0 && l1 != 0) {
			int* vec = new int[l1];
			for (int i = 0; i < l1; i++)
			{
				vec[i] = v1[i];
			}
			return vec;
		}
		else {
			int * vec = new int[l1 + l2];
			while (l1 != i && l2 !=j) {	
				if (v1[i] <= v2[j])
				{
					vec[k] = v1[i];
					i++;
				}
				else if (v1[i] > v2[j]) {
					vec[k] = v2[j];
					j++;
				}
				k++;
			}
			if (l1 == i && l2 != j)
			{
				while (j < l2)
				{
					vec[k] = v2[j];
					j++;
					k++;
				}
			}
			else {
				while (i < l1)
				{
					vec[k] = v1[i];
					i++;
					k++;
				}
			}
			return vec;
		}
	}
}




bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	if (l1==0) {
		return true;
	}
	else {
		for (int i = l1-1; i >= 0; i--)
		{
			return compararNum(v1[i], v2, l2) && subconjuntoVector(v1,v2,l1-1,l2);
		}
	}
}

bool compararNum(int e, int* vec, int largo) {
	for (int i = 0; i < largo; i++)
	{
		if (vec[i] == e)
		{
			return true;
		}
	}
	return false;
}



char** splitStr(char* str, char separador, int &largoRet)
{
	int i = 0;
	largoRet = cantToKens(str, separador);
	char** vec = new char*[largoRet];
	int largoDos = largoStr(str)+ 1;
	char* copia = new char[largoDos];
	for (int i = 0; i < largoDos; i++)
	{
		copia[i] = str[i];
	}
	char* buffer = NULL;
	char separadores[] = { separador,'\0' };
	char * parte = strtok_s(copia, separadores, &buffer);
	if (parte == NULL) {
		//char** vec = NULL;
		//return vec;
		return NULL;
	}
	else {
		while (parte)// parte!= NULL
		{
			vec[i] = parte;
			i++;
			parte = strtok_s(NULL, separadores, &buffer);
		}
	}
	

	return vec;
}

int cantToKens(char* str, char separador) {
	int cont = 0;
	int largo = largoStr(str) + 1;
	char* copia = new char[largo];
	for (int i = 0; i < largo; i++)
	{
		copia[i] = str[i];
	}
	char* buffer = NULL;
	char separadores[] = { separador,'\0' };
	char * parte = strtok_s(copia,separadores,&buffer);
	while (parte)// parte!= NULL
	{
		cont++;
		parte = strtok_s(NULL, separadores, &buffer);
	}
	delete [] copia;
	return cont;
}

#endif