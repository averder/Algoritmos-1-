#include "EjerciciosSem2.h"

#ifndef EJERCICIOSSEM2_CPP
#define EJERCICIOSSEM2_CPP

void simplificar(int n, int d) {
	int div;
	if (d == 0) {
		cout << n << "/" << d;
	}
	else if (n>d)
	{
		div = mcd(n, d);
		
	}
	else {
		div = mcd(d, n);
	}
	n = n / div;
	d = d / div;
	cout << n << "/" << d;
}

// MCD

int mcd(int a, int b) {
	int resto = a%b;
		while (resto != 0) {
			resto = a % b;
			a = b;
			b = resto;
			resto = a%b;
		}

	return b;
}

int ocurrencias123Repetidos(int* vector, int largo) {
	int contUno = 0;
	int contDos = 0;
	for (int i = 0; i < largo; i++)
	{
		if (vector[i] == 1 && vector[i] < vector[i + 1] && vector[i + 1] != 3 && contUno == 0) {
			contUno++;
		}
		if (vector[i] == 2 && vector[i] < vector[i + 1] && contUno == 1) {
			contUno++;
		}
		else if (vector[i + 1] == 1) {
			contUno = 0;
		}
		if (contUno == 2) {
			contDos++;
			contUno = 0;
		}
	}
	return contDos;
}

int MaximoNumero(unsigned int n) {
	int num;
	int max ;
	for (int i = 0; i < n; i++)
	{
		
		cin >> num;
		cout << endl;
		if (i == 0) {
			max = num;
		}
		
		if (num > max) {
			max = num;
		}
	}

    return max;
}

void ordenarVecInt(int *vec, int largoVec) {
	//bubbleSort
	int compa;
	for (int i = 0; i < largoVec-1; i++)
	{
		
		for (int j = i+1; j < largoVec; j++) {
			if (vec[i] > vec[j]) {
				compa = vec[i];
				vec[i] = vec[j];
				vec[j] = compa; 		
			}
		}
	}
}

#endif