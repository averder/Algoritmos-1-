#include "PruebasAuxSem7.h"

#ifndef PRUEBASAUXSEM7_CPP
#define PRUEBASAUXSEM7_CPP

bool PruebaAltura(char* inputTree, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Altura de un arbol binario " << nroPrueba++;
	
	std::ostringstream s;
	s << inputTree;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());
	
	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoAB* copiaArbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);
	int resultado = altura(arbol);
	
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = output == resultado;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
	} else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	return resultadoOK;
}

bool PruebaSonIguales(char* inputArbol1, char* inputArbol2, bool output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Son iguales " << nroPrueba++;
	
	std::ostringstream s;
	s << inputArbol1 << ", " << inputArbol2;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol1 = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol1, largo);
	largo = 0;
	NodoAB* arbol2 = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol2, largo);
	bool resultado = sonIguales(arbol1, arbol2);
	
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol1);
	FrameworkA1::destruir(arbol2);
	return resultadoOK;
}

bool PruebaExisteCaminoConSuma(char* inputArbol, int suma, bool output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba existe camino con suma " << nroPrueba++;
	
	std::ostringstream s;
	s << inputArbol << ", " << suma;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	bool resultado = existeCaminoConSuma(arbol, suma);
	
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

bool PruebaEsArbolBalanceado(char* inputArbol, bool output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba es arbol balanceado " << nroPrueba++;
	
	std::ostringstream s;
	s << inputArbol;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	bool resultado = esArbolBalanceado(arbol);
	
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

bool PruebaEnNivel(char* inputArbol, int k, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba en nivel " << nroPrueba++;
	
	std::ostringstream s;
	s << inputArbol << ", " << k;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	NodoLista* resultado = enNivel(arbol, k);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	char* resultadoImprimir = FrameworkA1::serializar(resultado);
	
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(resultado);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaCantNodosEntreNiveles(char* inputArbol, int desde, int hasta, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba cantidad de nodos entre niveles " << nroPrueba++;
	
	std::ostringstream s;
	s << inputArbol << ", " << desde << ", " << hasta;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	int resultado = cantNodosEntreNiveles(arbol, desde, hasta);
	
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

bool PruebaCamino(char* inputArbol, int x, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba camino " << nroPrueba++;
	
	std::ostringstream s;
	s << inputArbol << ", " << x;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);

	assert(FrameworkA1::esABB(arbol));

	largo = 0;
	NodoAB* arbolCopia = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	NodoLista* resultado = camino(arbol, x);
	largo = 0;
	NodoLista* solucion = (NodoLista*)FrameworkA1::parsearColeccion(output, largo);

	bool modificoParametros = !FrameworkA1::sonIgualesDatosForma(arbol, arbolCopia);

	char* resultadoImprimir = FrameworkA1::serializar(resultado);
	
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(modificoParametros){
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(arbolCopia);
	FrameworkA1::destruir(resultado);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaInvertirHastak(char* inputArbol, int k, char* output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Invertir hasta k " << nroPrueba++;

	std::ostringstream s;
	s << inputArbol << ", " << k;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	largo=0;
	NodoAB* copiaArbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	NodoAB* resultado = invertirHastak(arbol, k);
	largo=0;
	NodoAB* solucion = (NodoAB*)FrameworkA1::parsearColeccion(output, largo);
	
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, solucion);
	
	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	FrameworkA1::destruir(solucion);
	FrameworkA1::destruir(resultado);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaBorrarNodoRaiz(char* inputArbol, char *output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba borrar nodo raiz " << nroPrueba++;

	std::ostringstream s;
	s << inputArbol;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());


	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);

	// NUEVO chequeo de pruebas
	assert(FrameworkA1::esABB(arbol));

	borrarNodoRaiz(arbol);
	largo=0;
	NodoAB* solucion = (NodoAB*)FrameworkA1::parsearColeccion(output, largo);

	char* resultadoImprimir = FrameworkA1::serializar(arbol);
	bool resultadoOK = FrameworkA1::sonIgualesDatos(arbol, solucion);
	bool noEsABB = !FrameworkA1::esABB(arbol);
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultadoImprimir, inputParametersFormated);
	} else if(noEsABB) {
		cout << " -> ERROR el resultado no es un ABB" << endl;
		resultadoOK = false;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(solucion);
	delete[]resultadoImprimir;
	return resultadoOK;
}

bool PruebaSumaABB(char* inputArbol, int n, bool output, int& nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba suma equivalente a n en ABB " << nroPrueba++;

	std::ostringstream s;
	s << inputArbol << ", " << n;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	NodoAB* copiaArbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	
	bool resultado = SumaABB(arbol, n);
	
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

bool PruebaSucesorABB(char* inputArbol, int n, int output, int& nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba sucesor de ABB " << nroPrueba++;

	std::ostringstream s;
	s << inputArbol << ", " << n;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	NodoAB* copiaArbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	
	int resultado = Sucesor(arbol, n);
	
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

bool PruebaNivelMasNodos(char* inputArbol, int nivelHasta, int output, int &nroPrueba){
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba nivel con mas nodos " << nroPrueba++;

	std::ostringstream s;
	s << inputArbol << ", " << nivelHasta;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);
	NodoAB* copiaArbol = (NodoAB*)FrameworkA1::parsearColeccion(inputArbol, largo);

	int resultado = nivelMasNodos(arbol, nivelHasta);
	
	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = resultado == output;
	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
		resultadoOK = false;
	}else {
		cout << " -> OK" << endl;
	}
	
	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}

bool PruebaBorrarPares(char *inputABB, char *outputABB, int &nroPrueba){
	// PRUEBA
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba BorrarPares nro " << nroPrueba++;

	std::ostringstream s;
	s << inputABB;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	NodoAB *a, *correcta;
	int largo;
	a = (NodoAB*)FrameworkA1::parsearColeccion(inputABB, largo);

	assert(FrameworkA1::esABB(a));

	correcta = (NodoAB*)FrameworkA1::parsearColeccion(outputABB, largo);
	borrarPares(a);

	bool resultadoOK = FrameworkA1::sonIgualesDatos(correcta, a);
	bool noEsABB = !FrameworkA1::esABB(a);
	if (!resultadoOK){
		cout << " -> ERROR salida incorrecta" << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(correcta, a, inputParametersFormated);
	} else if(noEsABB) {
		cout << " -> ERROR el resultado no es un ABB" << endl;
		resultadoOK = false;
	}
	else
		cout << " -> OK" << endl;

	delete [] inputParametersFormated;
	FrameworkA1::destruir(a);
	FrameworkA1::destruir(correcta);
	return resultadoOK;
}



bool PruebaAlturaAG(char *inputTree, int output, int &nroPrueba)
{
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba AlturaAG Nro " << nroPrueba++;

	std::ostringstream s;
	s << inputTree;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAG * arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoAG * copiaArbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	
	//bool b2 = FrameworkA1::compartenMemoria(a, a2);

	int resultado = alturaAG(arbol);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = output == resultado;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	return resultadoOK;
}

bool PruebaSumaPorNiveles(char *inputTree, int output, int &nroPrueba)
{
	cout << "----------------------------------------------"<<endl;
	cout << "Prueba Suma por niveles AG numero: " << nroPrueba++;

	std::ostringstream s;
	s << inputTree;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAG * arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoAG * copiaArbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	

	int resultado = SumaPorNiveles(arbol);

	bool parametrosModificados = !FrameworkA1::sonIgualesDatosForma(arbol, copiaArbol);
	bool resultadoOK = output == resultado;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	} else if(parametrosModificados) {
		cout << " -> ERROR se modificaron los parametros" << endl;
	} else {
		cout << " -> OK" << endl;
	}

	delete [] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	return resultadoOK;
}

bool PruebaEsPrefijo(char *inputTree,char *inputList, bool output, int &nroPrueba)
{
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Prefijo AG numero: " << nroPrueba++;

	std::ostringstream s;
	s << inputTree << ", " << inputList;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo, largoLista;
	NodoAG * arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoAG * copiaArbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoLista* camino = (NodoLista *)FrameworkA1::parsearColeccion(inputList, largoLista);

	//NodoLista*resultado = CaminoAG(arbol, dato);
	bool resultado = EsPrefijo(arbol,camino);
	largo = 0;

	//bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, outpo);
	bool resultadoOK = resultado == output;
	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}

	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	return resultadoOK;
}

bool PruebaCaminoAG(char *inputTree, int dato, char* outputList, int &nroPrueba) {
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Camino AG " << nroPrueba++;

	std::ostringstream s;
	s << inputTree << ", " << dato;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo, largoLista;
	NodoAG * arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoAG * copiaArbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);
	NodoLista* camino = (NodoLista *)FrameworkA1::parsearColeccion(outputList, largoLista);

	NodoLista* resultado = CaminoAG(arbol,dato);
	largo = 0;

	bool resultadoOK = FrameworkA1::sonIgualesDatosForma(resultado, camino);

	char* resultadoImprimir = FrameworkA1::serializar(resultado);

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(outputList, resultadoImprimir, inputParametersFormated);
	}

	else {
		cout << " -> OK" << endl;
	}

	delete[] resultadoImprimir;
	delete[] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	FrameworkA1::destruir(copiaArbol);
	return resultadoOK;
}

bool PruebaNivelConMasNodosAG(char *inputTree, int output, int &nroPrueba)
{
	cout << "----------------------------------------------" << endl;
	cout << "Prueba Nivel con mas Nodos " << nroPrueba++;

	std::ostringstream s;
	s << inputTree;
	char *inputParametersFormated = FrameworkA1::copioString(s.str().c_str());

	int largo;
	NodoAG * arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);

	int resultado = NivelConMasNodosAG(arbol);

	bool resultadoOK = resultado==output;

	if (!resultadoOK) {
		cout << " -> ERROR salida incorrecta " << endl;
		FrameworkA1::imprimirEsperadoVsRecibido(output, resultado, inputParametersFormated);
	}
	else {
		cout << " -> OK" << endl;
	}

	delete[] inputParametersFormated;
	FrameworkA1::destruir(arbol);
	return resultadoOK;
}



#endif