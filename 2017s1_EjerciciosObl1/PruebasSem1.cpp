#include "PruebasSem1.h"

#ifndef PRUEBASSEM1_CPP
#define PRUEBASSEM1_CPP

void PruebasSem1() {
	int nroPrueba;
	int correctos = 0, error = 0;

	nroPrueba = 1;
	FrameworkA1::ver(PruebaSuma(2, 7, 9, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSuma(-8, 6, -2, nroPrueba), correctos, error);

	//prueba imprimir tabla del numero
	nroPrueba = 1;
	FrameworkA1::ver(PruebaImprimirTabla(7, 0, 6, "0*7=0;1*7=7;2*7=14;3*7=21;4*7=28;5*7=35;6*7=42", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(11, 1, 5, "1*11=11;2*11=22;3*11=33;4*11=44;5*11=55", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(0, 0, 0, "0*0=0", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(12, 10, 15, "10*12=120;11*12=132;12*12=144;13*12=156;14*12=168;15*12=180", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(5, 9, 9, "9*5=45", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaImprimirTabla(10, 0, 1, "0*10=0;1*10=10", nroPrueba), correctos, error);
	//fin prueba imprimir tabla del numero

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS CORRECTAS: " << correctos << endl;
	cout << "PRUEBAS INCORRECTAS: " << error << endl;

}

#endif
