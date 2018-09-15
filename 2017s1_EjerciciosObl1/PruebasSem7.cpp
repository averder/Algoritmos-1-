#include "PruebasSem7.h"

#ifndef PRUEBASSEM7_CPP
#define PRUEBASSEM7_CPP

void PruebasSem7() {
	int nroPrueba;
	int correctos = 0, error = 0;

	//Altura Arbol
	nroPrueba = 1;
	FrameworkA1::ver(PruebaAltura("{1,5,2}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,#,2,#,5}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{}", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,2,3}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,3,#}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,#,#}", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,2,3,1,#,#,#,#,3,1,2,1,1,#,#,#,#,#,4,1,#,2,2}", 9, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}", 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{3,3,3,#,1,#,1,#,1,#,1,2,2,#,#,#,#,#,3,1,#,#,4}", 8, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAltura("{1,3,#,1,#}", 3, nroPrueba), correctos, error);
	//Fin Altura arbol

	nroPrueba = 1;
	//Pruebas son iguales
	FrameworkA1::ver(PruebaSonIguales("{1,2,3,#,#,4,#,#,5}","{1,2,3,#,#,4,#,#,5}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1,2,3,#,#,4,#,#,5}","{1,2,3}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1,2,3}", "{1,2,3}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1,3,2}", "{1,2,3}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{}","{}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{}","{1}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1}","{}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1,1,#,5,7,1,5,6,1}","{1,1,#,5,7,1,5,6,2}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1,#,2,1,1,1,1}", "{1,#,2,1,1,1,1}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSonIguales("{1,#,2,1,1,1,1}", "{1,2,#,1,1,1,1}", false, nroPrueba), correctos, error);
	//Fin pruebas son iguales

	nroPrueba = 1;
	//Pruebas existe camino con suma
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{}", 0, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,2,3}", 4, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,2,3,#,#,4,#,#,5}", 3, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,2,3,#,#,4,#,#,5}", 2, false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,2,3,#,#,4,#,#,5}", 4, false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,2,3,#,#,4,#,#,5}", 13, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,1,#,5,7,1,5,6,2}", 14, false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,1,#,5,7,1,5,6,2}", 9, false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,1,#,5,7,1,5,6,2}", 11, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{1,1,#,5,7,1,5,6,2}", 12, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{-1,1,#,5,7,1,5,6,2}", 10, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaExisteCaminoConSuma("{-7,1,#,5,7,1,5,6,2}", 0, true, nroPrueba), correctos, error);
	//Fin pruebas existe camino con suma

	nroPrueba = 1;
	//Pruebas es arbol balanceado
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1,5,2}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1,#,2,#,3}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1,5,2,4}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1,2,2,4,3}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{0,-3,1,5,#,#,9,#,#,#,1,#,0,#,1,4,#,#,5,#,#}", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1, 2, 3, 4, 5, #, 6}", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsArbolBalanceado("{1, 2, 3, 4, 5, 6, 7}", true, nroPrueba), correctos, error);
	//Fin pruebas es arbol balanceado

	nroPrueba = 1;
	//Pruebas en nivel
	FrameworkA1::ver(PruebaEnNivel("{}", 1, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,5,6,7}", 1, "(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,5,6,7}", 2, "(2,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,5,6,7}", 3, "(4,5,6,7)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,5,6,7}", 4, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,#,5,6,#,7,8,9,#,10,#,#,11,#,#,#,12,13,#,#,14,#,#,15}", 1, "(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,#,5,6,#,7,8,9,#,10,#,#,11,#,#,#,12,13,#,#,14,#,#,15}", 2, "(2,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,#,5,6,#,7,8,9,#,10,#,#,11,#,#,#,12,13,#,#,14,#,#,15}", 3, "(4,5,6)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,#,5,6,#,7,8,9,#,10,#,#,11,#,#,#,12,13,#,#,14,#,#,15}", 4, "(7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,#,5,6,#,7,8,9,#,10,#,#,11,#,#,#,12,13,#,#,14,#,#,15}", 5, "(11,12,13)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEnNivel("{1,2,3,4,#,5,6,#,7,8,9,#,10,#,#,11,#,#,#,12,13,#,#,14,#,#,15}", 6, "(14,15)", nroPrueba), correctos, error);
	//Fin pruebas en nivel

	nroPrueba = 1;
	//Pruebas cantidad de nodos entre niveles
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,4,5,6,7}", 1, 1, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,4,5,6,7}", 1, 2, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,4,5,6,7}", 1, 4, 7, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,4,5,6,7}", 2, 4, 6, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 1, 6, 9, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 5, 4, 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 2, 3, 5, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{}", 1, 3, 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{}", 1, 1, 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{}", 3, 1, 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCantNodosEntreNiveles("{1,2,3,4,#,#,#,5}", 3, 3, 1, nroPrueba), correctos, error);
	//Fin pruebas cantidad de nodos entre niveles

	nroPrueba = 1;
	//Pruebas camino
	FrameworkA1::ver(PruebaCamino("{8,3,10,1,5,9,13}", 9, "(8,10,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{4}", 4, "(4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{1,#,2,#,3,#,4,#,5}", 1, "(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{10,5,13,#,6,#,15,#,9,#,30,7,#}", 13, "(10,13)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{-80,-130,-1,#,-90,-5,10}", -90, "(-80,-130,-90)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{120,53,180,33,88,150,300,15,#,66,100,#,#,#,#,#,18,#,#,#,#,#,31}", 180, "(120, 180)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{0,-5,8,-10,-4,5,1000000}", 0, "(0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{120,53,180,33,88,150,300,15,#,66,100,#,#,#,#,#,18,#,#,#,#,#,31}", 18, "(120, 53, 33, 15, 18)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{10,5,13,#,6,#,15,#,9,#,30,7,#}", 7, "(10, 5, 6, 9, 7)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCamino("{0,-5,8,-10,-4,5,1000000}", 5, "(0, 8, 5)", nroPrueba), correctos, error);
	//Fin pruebas camino

	//Invertir hasta k
	nroPrueba = 1; 
	FrameworkA1::ver(PruebaInvertirHastak("{}", 5, "{}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3}", 10, "{1,3,2}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,4,5,6,7}", 0, "{}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,4,5,6,7}", 1, "{1}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,4,5,6,7}", 2, "{1,3,2}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,4,5,6,7}", 3, "{1,3,2,7,6,5,4}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 1, "{1}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 2, "{1,3,2}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 3, "{1,3,2,6,5,4}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 4, "{1,3,2,6,5,4,#,8,7}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirHastak("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 5, "{1,3,2,6,5,4,#,8,7,#,#,#,#,9}", nroPrueba), correctos, error);
	//Fin Invertir hasta k

	//borrar nodo raiz
	nroPrueba = 1;
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{1}", "{}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{1,#,2}", "{2}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{3,2,6}", "{2,#,6}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{8,3,10,1,5,9,13}", "{1,3,5,9,10,13}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{5,3,7,2,4,6}", "{2,3,6,7,4}", nroPrueba), correctos, error);  
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{5,3,6,1,4}", "{3,6,1,4}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{1,#,2,#,3,#,4,#,5}", "{2,3,4,5}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{10,5,13,#,6,#,15,#,9,#,30,7,#}", "{5,6,7,9,13,15,30}", nroPrueba), correctos,error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{0,-5,8,-10,-4,5,1000000}", "{-10,-5,-4,5,8,1000000}", nroPrueba), correctos,error);
	FrameworkA1::ver(PruebaBorrarNodoRaiz("{120,53,180,33,88,130,300,15,#,66,100,#,#,#,#,#,18,#,#,#,#,#,31}", "{100,53,180,33,88,130,300,15,#,66,#,#,#,#,#,#,18,#,#,#,31}", nroPrueba), correctos,error);
	//fin borrar nodo raiz

	//Pruebas Suma equivalente a n en ABB
	nroPrueba = 1;
	FrameworkA1::ver(PruebaSumaABB("{3,1,4,0,2}", 7, true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{}", 0, false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{2}",3,false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{1}",1,false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{2,#,4}",3,false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{2,#,4}",6,true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10}",10,true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10}",1024,false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10}",39,false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10}",18,true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10}",12,true, nroPrueba), correctos, error);
	/*FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10,6,#,1,#,#,#,6,#,#,20}",30,true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10,6,#,1,#,#,#,6,#,#,20}",21,true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10,6,#,1,#,#,#,6,#,#,20}",23,true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaABB("{5,3,8,2,4,7,10,6,#,1,#,#,#,6,#,#,20}",20,false, nroPrueba), correctos, error);
*/
	//Pruebas Sucesor de n en ABB
	nroPrueba = 1;
	FrameworkA1::ver(PruebaSucesorABB("{2,#,4}", 2, 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{3,1,4}", 1, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{5,3,8,2,4,7,10}", 5, 7, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{5,3,8,2,4,7,10}", 3, 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{10,7,20,5,8,#,25,3,6,#,#,#,#,1,4}", 10, 20, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{10,7,20,5,8,#,25,3,6,#,#,#,#,1,4}", 3, 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{10,7,20,5,8,#,25,3,6,#,#,#,#,1,4}", 7, 8, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{5,2,#}", 3, 5, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{10,7,20,5,8,#,25,3,6,#,#,#,#,1,4}", 3, 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{10,7,20,5,8,#,25,3,6,#,#,#,#,1,4}", 11, 20, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{5,2,#}", 7, -1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSucesorABB("{5,2,#,1,3}", 5, -1, nroPrueba), correctos, error);


	//Pruebas nivel con mas nodos
	nroPrueba = 1;
	FrameworkA1::ver(PruebaNivelMasNodos("{}", 0, 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1}", 1, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,4,5,6,7}", 1, 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,4,5,6,7}", 2, 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,4,5,6,7}", 3, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,4,5,6,7}", 5, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 5, 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,#,4,5,6,#,#,#,#,7,8,#,#,#,9}", 2, 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,#,4,5,6,7,8,9,10,11,12,#,#,#,13}", 5, 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelMasNodos("{1,2,3,#,4,5,6,7,8,9,10,11,12,#,#,#,13}", 3, 3, nroPrueba), correctos, error);
	//Fin pruebas nivel con mas nodos

	nroPrueba = 1;
	FrameworkA1::ver(PruebaBorrarPares("{5,3,7,2,4,6,8}", "{5,3,7}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{5,3,7}", "{5,3,7}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{5}", "{5}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{}", "{}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{4,2,6}", "{}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{4}", "{}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{3,2,9}", "{3,#,9}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{7,5,8,4,6}", "{5,#,7}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{8,6,10,#,#,9}", "{9}", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaBorrarPares("{17,10,20,6,14,18,22,4,8,12,16}", "{17}", nroPrueba), correctos, error);
	
	nroPrueba = 1;
	FrameworkA1::ver(PruebaAlturaAG("{{}}", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAlturaAG("{{1,2,5,#,#,3,#,4,#,#}}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAlturaAG("{{1,2,5,#,6,11,#,#,#,3,#,4,7,#,8,#,9,#,10}}", 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaAlturaAG("{{5,7,1,#,#,3,8,#,4,#,#,1,#,#,10,9,1,#,#,3,2}}",3,nroPrueba),correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaSumaPorNiveles("{{}}", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{6}}", -6, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{6,2}}", -4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{6,#,4,#,1}}", -11, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{90,60,10,40,#,45}}", 45, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{90,60,10,40,#,45,12,#,#,3,#,2,#,43}}", 81, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{1,2,3,#,1}}", -3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{1,2,5,#,#,3,#,4,#,#}}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{1,2,5,#,20,#,#,3,#,4,7,#}}", -24, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{1,-7,5,#,20,#,#,3,#,4,7,33,#}}", 0, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaSumaPorNiveles("{{1,-7,5,#,15,#,#,3,#,4,8,34,#}}", 5, nroPrueba), correctos, error);

	nroPrueba = 1;
				   
	FrameworkA1::ver(PruebaEsPrefijo("{{}}","()", true,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1}}","()", true,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{}}","(1,2,3,4)", false, nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,2,5,#,#,3,7,4,#,#}}","(1,2,5)",true,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{2,4,6,#,8}}","(2,3,6,8)", false,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{2,4,6,#,8}}","(2,4,6,8)", false,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,2,3,#,#,#,1}}","(1,2,3)", true,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,2,3,#,1}}","(1,2,3,4)", false,nroPrueba),correctos,error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,#,3,#,4,7,33,#}}","()",true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,#,3,#,4,7,33,#}}","(1,-7,4)",false, nroPrueba), correctos, error);	
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,3,4,7,33,#}}","(1,-7,3,4,7)",true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,#,3,#,4,7,33,#}}","(1,4,7,33)",true,nroPrueba),correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,#,3,#,4,7,33,#}}","(1,-7,5,20)",false,nroPrueba),correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,#,3,#,#,4,7,33,#}}","(4,7,33)",true,nroPrueba),correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{1,-7,5,#,20,#,#,3,#,#,4,7,33,#,88,45}}","(4,7,88,45)",true,nroPrueba),correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{5,7,1,#,#,3,8,#,4,#,#,1,#,#,10,9,1,#,#,3,2}}","(10,3,2)",true,nroPrueba),correctos, error);
	FrameworkA1::ver(PruebaEsPrefijo("{{5,7,1,#,#,3,8,#,4,#,#,1,#,#,10,9,1,#,#,3,2}}","(10,9,1,1)",false,nroPrueba),correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaCaminoAG("{{1,#,#}}", 1, "(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,#,#}}", 5, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,3,#,4,#,#}}", 4, "(1,2,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,4,#,#}}", 4, "(1,2,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,4,#,#,3,5,#,#}}", 5, "(1,3,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,4,#,#,3,5,#,#,6,7,#,#}}", 6, "(1,6)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#}}", 9, "(1,7,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#}}", 4, "(1,2,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#,#,10,11,12,#,13,#,#}}", 13, "(10,11,13)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#}}", 5, "(1,2,4,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#}}", 7, "(1,7)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaCaminoAG("{{5,7,1,#,#,3,8,#,4,#,#,1,#,#,10,9,1,#,#,3,2}}",2,"(10,3,2)",nroPrueba),correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,#,#}}", 1, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,#,3}}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,4,#,#,3,5,#,#}}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,3,#,4,#,5,#,6,#,#,#}}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,4,#,#,3,5,#,#,6,#,7,8,#,9,#,10,#,11,#,#}}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#}}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,3,#,4,5,#,#,#,6,#,7,8,#,9,#,#,10,#,11,#,#}}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,3,#,4,#,5,#,6,#,#,7,#,9,#,10,#,#}}", 2, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,3,#,4,#,5,#,6,#,#,7,8,#,9,#,10,#,#}}", 3, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,4,#,#,3,5,11,#,12,#,13,#,14,#,15,#,#,#,6,#,7,8,#,9,#,#}}", 4, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaNivelConMasNodosAG("{{1,2,4,#,#,3,5,#,#,#,6,7,#,#,8,#,9,#,#}}", 1, nroPrueba), correctos, error);

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS CORRECTAS: " << correctos << endl;
	cout << "PRUEBAS INCORRECTAS: " << error << endl;
}

#endif