#include "PruebasSem2.h"

#ifndef PRUEBASSEM2_CPP
#define PRUEBASSEM2_CPP

void PruebasSem2() {
	int nroPrueba;
	int correctos = 0, error = 0;
	
	//PRUEBAS SIMPLIFICAR
	nroPrueba = 1;
	FrameworkA1::ver(PruebaSimplificar(2, 7, "2/7", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(30, 6, "5/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(6, 30, "1/5", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(1024, 32, "32/1", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSimplificar(1, 1, "1/1", nroPrueba), correctos, error);
	//FIN PRUEBAS SIMPLIFICAR

	//PRUEBAS OCURRENCIAS 123 CON REPETIDOS
	nroPrueba = 1;
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,3]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[3]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,3,1]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,3]", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,2,2,3]", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,1,2,3]", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,1,2,1,3]", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,3,1,2,3,1,2,3,2,3]", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOcuerrencias123Repetidos("[1,2,1,2,1,2,1,3,2,3,1,2,3,1,2,2,3,2,3,1,2,3,1,1,2]", 3, nroPrueba), correctos, error);
	//FIN PRUEBAS OCURRENCIAS 123 CON REPETIDOS
	
	//PRUEBAS MAXIMO NUMERO
	nroPrueba = 1;
	FrameworkA1::ver(PruebaMaximoNumero(3, "2 4 8", 8, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(2, "1 1", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(6, "2 2 8 5 6 7", 8, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(1, "2", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(10, "2 11 20 90 465 45 34 767 32 1", 767, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(4, "-17 89 12 11", 89, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMaximoNumero(3, "-28923 -2229 -1122", -1122, nroPrueba), correctos, error);
	//FIN PRUEBAS MAXIMO NUMERO
	
	//PRUEBA ORDENAR VECTOR DE INT
	nroPrueba = 1;
	FrameworkA1::ver(PruebaOrdenarVecInt("[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[5]", "[5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[1,2,3,4,5]", "[1,2,3,4,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[9,5,1]", "[1,5,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[1,6,4,9,2,4,9,1]", "[1,1,2,4,4,6,9,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecInt("[9,9,5,5,5,1,1]", "[1,1,5,5,5,9,9]", nroPrueba), correctos, error);
	//FIN PRUEBA ORDENAR VECTOR DE INT

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS CORRECTAS: " << correctos << endl;
	cout << "PRUEBAS INCORRECTAS: " << error << endl;
}

#endif