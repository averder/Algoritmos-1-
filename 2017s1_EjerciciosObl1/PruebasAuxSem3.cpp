#include "PruebasAuxSem3.h"

#ifndef PRUEBASAUXSEM3_CPP
#define PRUEBASAUXSEM3_CPP


bool PruebaInvertirCase(char *substr, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Invertir Case de palabra " << nroPrueba++;

	std::ostringstream s;
	s << substr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	char *substringCopia = FrameworkA1::copioString(substr);

	char* res = InvertirCase(substr);

	bool resultadoOK = FrameworkA1::sonIguales(res, output);
	bool parametrosModificados = !FrameworkA1::sonIguales(substr, substringCopia);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	}
	else if(parametrosModificados) {
		cout << " -> ERROR parametro modificado" << endl;
	} else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	delete [] substringCopia;
	return resultadoOK;
}

bool PruebaIslas(char* datosMapa, int col, int fil, int output, int &nroPrueba) {
	// PRUEBA ISLAS
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Islas " << nroPrueba++;
	int contador = 0;
	int largo;

	std::ostringstream s;
	s << datosMapa << ", " << col << ", " << fil;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	
	char** cDatosMapa = (char**)FrameworkA1::parsearColeccion(datosMapa, largo);
	char** mapa = new char*[col];
	char** copiaMapa = new char*[col];
	for(int c=0; c<col; c++){
		mapa[c] = new char[fil];
		copiaMapa[c] = new char[fil];
	}
	for(int f=0; f<fil;f++){
		for(int c=0; c<col; c++){
			mapa[c][f] = cDatosMapa[contador][0];
			copiaMapa[c][f] = cDatosMapa[contador][0];
			contador++;
		}
	}
	int resultado = islas(mapa, col, fil);
	bool parametrosModificados = !FrameworkA1::sonIguales(mapa, copiaMapa, col, fil);
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}
	else if(parametrosModificados) {
		cout << " -> ERROR parametro modificado" << endl;
		resultadoOK = false;
	} else 
		cout << " -> OK" << endl;
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(cDatosMapa, largo);
	FrameworkA1::destruir(mapa, fil);
	return resultadoOK;
}

bool PruebaOcurrenciasSubstring(char *stringVecStr, char *substr, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Ocurrencias Substring " << nroPrueba++;

	std::ostringstream s;
	s << stringVecStr << ", " << substr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoVecStr;
	char** vecStr = (char**)FrameworkA1::parsearColeccion(stringVecStr, largoVecStr);

	char *substringCopia = FrameworkA1::copioString(substr);
	char** vecStrCopia = (char**)FrameworkA1::parsearColeccion(stringVecStr, largoVecStr);

	int res = ocurrenciasSubstring(vecStr, largoVecStr, substr);

	bool resultadoOK = res == output;

	bool modificoParametros = !((FrameworkA1::sonIguales(vecStr, vecStrCopia, largoVecStr)) || (strcmp(substr, substringCopia) != 0));
	
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, res, inputParametersFormated);
	} else if(modificoParametros) {
		cout << " -> ERROR modifico parametros" << endl;
		resultadoOK = false;
	} else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	FrameworkA1::destruir(vecStr, largoVecStr);
	FrameworkA1::destruir(vecStrCopia, largoVecStr);
	delete [] substringCopia;
	return resultadoOK;
}

bool PruebaOrdenarVecStr(char* vecStr, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba ordenar vector de strings " << nroPrueba++;

	std::ostringstream s;
	s << vecStr;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largoResultado;
	char** listaPalabras = (char**)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	char** listaPalabrasCopia = (char**)FrameworkA1::parsearColeccion(vecStr, largoResultado);
	int largoSolucion;
	char** solucion = (char**)FrameworkA1::parsearColeccion(output, largoSolucion);

	char** resultado = ordenarVecStrings(listaPalabras, largoResultado);

	bool parametrosModificados = !FrameworkA1::sonIguales(listaPalabras, listaPalabrasCopia, largoResultado);
	bool compartenMem = FrameworkA1::compartenMemoria(resultado, largoResultado, listaPalabras, largoResultado);
	bool resultadoOK = FrameworkA1::sonIguales(resultado, solucion, largoSolucion);
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado, largoResultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(compartenMem) {
		cout << " -> ERROR vector devuelto comparte memoria con parametro" << endl;
		resultadoOK = false;
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(listaPalabras,largoResultado);
	FrameworkA1::destruir(listaPalabrasCopia,largoResultado);
	FrameworkA1::destruir(resultado,largoResultado);
	FrameworkA1::destruir(solucion,largoResultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}


bool PruebaIntercalarVector(char* vector1, char* vector2, char* vectorOutput, int &nroPrueba)
{
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Intercalar Vectores " << nroPrueba++;
	
	std::ostringstream s;
	s << vector1 << ", " << vector2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoV1 = 0;
	int* vector1Parseado = (int*)FrameworkA1::parsearColeccion(vector1, largoV1);
	int* vector1ParseadoCopia = (int*)FrameworkA1::parsearColeccion(vector1, largoV1);

	int largoV2 = 0;
	int* vector2Parseado = (int*)FrameworkA1::parsearColeccion(vector2, largoV2);
	int* vector2ParseadoCopia = (int*)FrameworkA1::parsearColeccion(vector2, largoV2);

	int largoResultadoEsperado = 0;
	int* vectorResultadoEsperado = (int*)FrameworkA1::parsearColeccion(vectorOutput, largoResultadoEsperado);

	int largoRes = largoV1 + largoV2; // asumo que resultado tiene ese largo

	assert(largoRes == largoResultadoEsperado); // por si las pruebas estan mal armadas
	
	int* resultado = intercalarVector(vector1Parseado, vector2Parseado, largoV1, largoV2);
	bool parametrosModificados = false;

	parametrosModificados = !FrameworkA1::sonIguales(vector1Parseado, vector1ParseadoCopia, largoV1);
	parametrosModificados = parametrosModificados || !FrameworkA1::sonIguales(vector2Parseado, vector2ParseadoCopia, largoV2);

	bool compartenMem = FrameworkA1::compartenMemoria(resultado, vector1Parseado, largoRes, largoV1) || FrameworkA1::compartenMemoria(resultado, vector2Parseado, largoRes, largoV2);

	bool resultadoOK = FrameworkA1::sonIguales(resultado, vectorResultadoEsperado, largoResultadoEsperado);
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado, largoRes);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(vectorOutput, resultadoImprimir, inputParametersFormated);
	}
	else if (compartenMem) {
		cout << " -> ERROR vector devuelto comparte memoria con parametro" << endl;
		resultadoOK = false;
	}
	else if (parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(vector1Parseado);
	FrameworkA1::destruir(vector1ParseadoCopia);
	FrameworkA1::destruir(vector2Parseado);
	FrameworkA1::destruir(vector2ParseadoCopia);
	FrameworkA1::destruir(vectorResultadoEsperado);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaSubconjuntoVector(char* vector1, char* vector2, bool output, int &nroPrueba)
{
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Subconjunto Vector " << nroPrueba++;

	std::ostringstream s;
	s << vector1 << ", " << vector2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largoV1 = 0;
	int* vector1Parseado = (int*)FrameworkA1::parsearColeccion(vector1, largoV1);


	int largoV2 = 0;
	int* vector2Parseado = (int*)FrameworkA1::parsearColeccion(vector2, largoV2);	

	bool resultado = subconjuntoVector(vector1Parseado, vector2Parseado, largoV1, largoV2);

	bool resultadoOK = (resultado == output);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}
	else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	delete vector1Parseado;
	delete vector2Parseado;
	return resultadoOK;
}

bool PruebaSplitStr(char* entrada, char separador, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba split de strings " << nroPrueba++;

	std::ostringstream s;
	s << "String:" << entrada << " Separador:" << separador;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo = strlen(entrada) +1;
	char* entradaCopia = new char[largo];
	strcpy_s(entradaCopia,largo,entrada);

	int largoEsperado;
	char** esperado = (char**)FrameworkA1::parsearColeccion(output, largoEsperado);

	int largoObtenido;
	char** obtenido = splitStr(entrada,separador,largoObtenido);

	bool parametrosModificados = !FrameworkA1::sonIguales(entrada,entradaCopia);

	bool resultadoOK = largoEsperado == largoObtenido && FrameworkA1::sonIguales(obtenido,esperado,largoEsperado);
	
	char* resultadoImprimir = FrameworkA1::serializar(obtenido, largoObtenido);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	delete[] obtenido;
	delete[] entradaCopia;
	delete[]resultadoImprimir;
	return resultadoOK;
}

#endif