#include "PruebasSem4.h"

#ifndef PRUEBASSEM4_CPP
#define PRUEBASSEM4_CPP

void PruebasSem4() {
	int nroPrueba;
	int correctos = 0, error = 0;

	//Pruebas ordenar vector de int MergeSort
	nroPrueba = 1;
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[]", "[]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[4]", "[4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,1,1]", "[1,1,1]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,3]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,4,2]", "[1,2,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[2,3,1]", "[1,2,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,-3,-1]", "[-3,-2,-1]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,1,4,1,3,8]", "[1,1,1,3,4,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,3,1]", "[-2,1,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[3,5,2,1,0]", "[0,1,2,3,5]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[9,2,2,5,1]", "[1,2,2,5,9]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[3,1,-1,1,0]", "[-1,0,1,1,3]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[10,9,8,7,6,5,4,3,2,1,0,-1,-2]", "[-2,-1,0,1,2,3,4,5,6,7,8,9,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[7,3,7,10,-1,1,-6,0,-10,2,1,2]", "[-10,-6,-1,0,1,1,2,2,3,7,7,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[10,9,8,7,6,5,4,3,2,1,0,-1,-2]", "[-2,-1,0,1,2,3,4,5,6,7,8,9,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[8,7,5,2,-3,-1]", "[-3,-1,2,5,7,8]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,0,10,3,4]", "[0,1,2,3,4,10]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[1,2,4,3]", "[1,2,3,4]", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaOrdenarVecIntMergeSort("[-2,0,3,1,1]", "[-2,0,1,1,3]", nroPrueba), correctos, error);

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS CORRECTAS: " << correctos << endl;
	cout << "PRUEBAS INCORRECTAS: " << error << endl;
}

#endif