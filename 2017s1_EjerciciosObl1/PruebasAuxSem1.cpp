#include "PruebasAuxSem1.h"

#ifndef PRUEBASAUXSEM1_CPP
#define PRUEBASAUXSEM1_CPP

bool PruebaSuma(int a, int b, int output, int &nroPrueba) {
	// PRUEBA SUMA A+B
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Problema A+B nro " << nroPrueba++;
	
	std::ostringstream s;
	s << a << ", " << b;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int res = Suma(a, b);

	if (res != output) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
		return false;
	}
	cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	return true;
}


bool PruebaImprimirTabla(unsigned int tablaDel, unsigned int desde, unsigned int hasta, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Imprimir Tabla del numero " << nroPrueba++;

	stringstream ss;
	auto old_buf = cout.rdbuf(ss.rdbuf()); 
    
	std::ostringstream strss;
	strss << tablaDel << ", " << desde << ", " << hasta;
	char *inputParametersFormated = FrameworkA1::copioString(strss.str().c_str());

	TablaDel(tablaDel, desde, hasta);
    
	cout.rdbuf(old_buf); 
	string s = ss.str();
	unsigned int sCharL = s.length() + 1;
	char *sChar = new char[sCharL];
	strcpy_s(sChar, sCharL, s.c_str());
	if (sChar[sCharL-2] == 10) sChar[sCharL-2] = '\0'; 
	
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
#endif