#include "PruebasAuxSem2.h"

#ifndef PRUEBASAUXSEM2_CPP
#define PRUEBASAUXSEM2_CPP



bool PruebaSimplificar(int n, int d, char *output, int &nroPrueba) {
	// PRUEBA SIMPLIFICAR FRACCION
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Simplificar fraccion " << nroPrueba++;

	std::ostringstream strss;
	strss << n << ", " << d;
	char *inputParametersFormated = FrameworkA1::copioString(strss.str().c_str());

	stringstream ss;
	auto old_buf = cout.rdbuf(ss.rdbuf()); //change the underlying buffer and save the old buffer

    simplificar(n, d);

    cout.rdbuf(old_buf); //reset buffer
	string s = ss.str();
	unsigned int sCharL = s.length() + 1;
	char *sChar = new char[sCharL];
	strcpy_s(sChar, sCharL, s.c_str());
	if (sChar[sCharL-2] == 10) sChar[sCharL-2] = '\0'; // elimino el fin de linea
	bool resultadoOK = strcmp(output, sChar) == 0;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, sChar, inputParametersFormated);
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	delete [] sChar;
	return resultadoOK;
}

bool PruebaOcuerrencias123Repetidos(char* vector, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Ocurrencias 123 Repetidos " << nroPrueba++;

	std::ostringstream s;
	s << vector;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	int* vectorParseado = (int*)FrameworkA1::parsearColeccion(vector, largo);
	int* vectorParseadoCopia = (int*)FrameworkA1::parsearColeccion(vector, largo);
	int res = ocurrencias123Repetidos(vectorParseado, largo);

	bool resultadoOK = res == output;
	bool modificoParametros = !FrameworkA1::sonIguales(vectorParseado, vectorParseadoCopia, largo);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	} else if(modificoParametros){
		cout << " -> ERROR modifico parametros" << endl;
		resultadoOK = false;
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	FrameworkA1::destruir(vectorParseado);
	FrameworkA1::destruir(vectorParseadoCopia);
	return resultadoOK;
}

bool PruebaMaximoNumero(unsigned int n, char* vector, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Maximo Numero " << nroPrueba++;

	std::ostringstream s;
	s << n << ", " << vector;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	streambuf *old_buf;
	istringstream oss(vector);
	old_buf = cin.rdbuf();
	cin.rdbuf(oss.rdbuf());

	//int* vectorParseado = (int*)parsear(vector);
	int res = MaximoNumero(n);

	cin.rdbuf(old_buf); //reset buffer

	bool resultadoOK = res == output;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	return resultadoOK;
}

bool PruebaOrdenarVecInt(char* vecStr, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba ordenar vector de int " << nroPrueba++;

	std::ostringstream s;
	s << vecStr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoResultado;
	int *listaPalabras = (int *)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	int largoSolucion;
	int *solucion = (int *)FrameworkA1::parsearColeccion(output, largoSolucion);

	ordenarVecInt(listaPalabras, largoResultado);

	bool resultadoOK = FrameworkA1::sonIguales(listaPalabras, solucion, largoSolucion);
	
	char* resultadoImprimir = FrameworkA1::serializar(listaPalabras, largoResultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaPalabras);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

#endif