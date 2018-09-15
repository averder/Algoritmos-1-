#include "PruebasSem5.h"

#ifndef PRUEBASSEM5_CPP
#define PRUEBASSEM5_CPP

void PruebasSem5() {
	int nroPrueba;
	int correctos = 0, error = 0;

	nroPrueba = 1;
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("()", 50 ,"()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1)", 50 ,"(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1)", 1 ,"()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1,2,3,4,5)", 2 ,"(1,2,3,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1,2,3,4,5,6,7,8,9,10)",10 ,"(2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1,2,3,4,5,6,7,8,9,10)", -5 ,"(1,2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1,2,3,4,5,6,7,8,9,10)",0 ,"(1,2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("()", 1, "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(1,2,3,4,5,6,7,8,9,10)", 1, "(1,2,3,4,5,6,7,8,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("(5, 6, 7, 8, 9)", 1, "(5, 6, 7, 8)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarNesimoDesdeElFinal("()", 0, "()", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(4)", "(4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(1,1,1)", "(1,1,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(1,2,3)", "(1,2,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(1,4,2)", "(1,2,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(2,3,1)", "(1,2,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(-2,-3,-1)", "(-3,-2,-1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(1,1,4,1,3,8)", "(1,1,1,3,4,8)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(-2,3,1)", "(-2,1,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(3,5,2,1,0)", "(0,1,2,3,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(9,2,2,5,1)", "(1,2,2,5,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(3,1,-1,1,0)", "(-1,0,1,1,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(10,9,8,7,6,5,4,3,2,1,0,-1,-2)", "(-2,-1,0,1,2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(7,3,7,10,-1,1,-6,0,-10,2,1,2)", "(-10,-6,-1,0,1,1,2,2,3,7,7,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(10,9,8,7,6,5,4,3,2,1,0,-1,-2)", "(-2,-1,0,1,2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(8,7,5,2,-3,-1)", "(-3,-1,2,5,7,8)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(1,2,0,10,3,4)", "(0,1,2,3,4,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(1,2,4,3)", "(1,2,3,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaInsertionSort("(-2,0,3,1,1)", "(-2,0,1,1,3)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(4)", "(4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(1,1,1)", "(1,1,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(1,2,3)", "(1,2,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(1,4,2)", "(1,2,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(2,3,1)", "(1,2,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(-2,-3,-1)", "(-3,-2,-1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(1,1,4,1,3,8)", "(1,1,1,3,4,8)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(-2,3,1)", "(-2,1,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(3,5,2,1,0)", "(0,1,2,3,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(9,2,2,5,1)", "(1,2,2,5,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(3,1,-1,1,0)", "(-1,0,1,1,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(10,9,8,7,6,5,4,3,2,1,0,-1,-2)", "(-2,-1,0,1,2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(7,3,7,10,-1,1,-6,0,-10,2,1,2)", "(-10,-6,-1,0,1,1,2,2,3,7,7,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(10,9,8,7,6,5,4,3,2,1,0,-1,-2)", "(-2,-1,0,1,2,3,4,5,6,7,8,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(8,7,5,2,-3,-1)", "(-3,-1,2,5,7,8)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(1,2,0,10,3,4)", "(0,1,2,3,4,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(1,2,4,3)", "(1,2,3,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaListaOrdenadaSelectionSort("(-2,0,3,1,1)", "(-2,0,1,1,3)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaInvertirParcial("()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(1)", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(1,2,3,4)", "(3,2,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(-1,-2)", "(-1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(1,2,3,4,3,2,1,0)", "(1,2,3,4,3,2,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(1,2,3,4,3,2,1)", "(2,3,4,3,2,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(1,1,1)", "(1,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(0,1,2,3,4,5,6,7,8,9,10)", "(9,8,7,6,5,4,3,2,1,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(0,1,0,5,0,1,0)", "(1,0,5,0,1,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInvertirParcial("(8,9,5,1)", "(5,9,8)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaIntercalarIter("()", "()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(1)", "()", "(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(1)", "(2)", "(1,2)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(1,3,5,7,9)", "(2,4,6,8)", "(1,2,3,4,5,6,7,8,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(1,3,5,7,9,9)", "(2,2,4,6,8)", "(1,2,2,3,4,5,6,7,8,9,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(100,200,300,400)", "(100,200,300,400)", "(100,100,200,200,300,300,400,400)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("()", "(-1,0,1,5)", "(-1,0,1,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(19,24,233,2344)", "(-1222,-129,-12,0,0,0,0,0,0,1,2,3,4,12)", "(-1222,-129,-12,0,0,0,0,0,0,1,2,3,4,12,19,24,233,2344)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(-1,-1,-1)", "(-1,-1,-1,-1)", "(-1,-1,-1,-1,-1,-1,-1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(-4,-1,0,5,7,10,12)", "(0,1,1)", "(-4,-1,0,0,1,1,5,7,10,12)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarIter("(2,2)", "(2,2)", "(2,2,2,2)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaIntercalarRec("()", "()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(1)", "()", "(1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(1)", "(2)", "(1,2)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(1,3,5,7,9)", "(2,4,6,8)", "(1,2,3,4,5,6,7,8,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(1,3,5,7,9,9)", "(2,2,4,6,8)", "(1,2,2,3,4,5,6,7,8,9,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(100,200,300,400)", "(100,200,300,400)", "(100,100,200,200,300,300,400,400)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("()", "(-1,0,1,5)", "(-1,0,1,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(19,24,233,2344)", "(-1222,-129,-12,0,0,0,0,0,0,1,2,3,4,12)", "(-1222,-129,-12,0,0,0,0,0,0,1,2,3,4,12,19,24,233,2344)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(-1,-1,-1)", "(-1,-1,-1,-1)", "(-1,-1,-1,-1,-1,-1,-1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(-4,-1,0,5,7,10,12)", "(0,1,1)", "(-4,-1,0,0,1,1,5,7,10,12)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaIntercalarRec("(2,2)", "(2,2)", "(2,2,2,2)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaInsComFin("(1,2,1)", 0,"(0,1,2,1,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(1,2,3,4)", 5,"(5,4,3,2,1,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(5)", 4,"(4,5,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("()", 4,"(4,4)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(5,4,3,2,1,2,3,4,5)", 6, "(6,5,4,3,2,1,2,3,4,5,6)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(1,1,1,1,1)", 1, "(1,1,1,1,1,1,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(3,2,1)", 0, "(0,1,2,3,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(9,5,6,1,2,4,8,9,5,55,2)", 33, "(33,2,55,5,9,8,4,2,1,6,5,9,33)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(1,2,3,4,5)", 3, "(3,5,4,3,2,1,3)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaInsComFin("(9,5,1,7,5,3)", 1000, "(1000,3,5,7,1,5,9,1000)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaEXOR("(100,200,300,400)", "(100,200,300,400)","()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(1,2,3,4)", "(2,3,5,7)", "(1,4,5,7)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("()", "()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("()", "(-1,0,1,5)", "(-1,0,1,5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(19,24,233,2344)", "(-1222,-129,-12,0,0,0,0,0,0,1,2,3,4,12)", "(-1222,-129,-12,0,1,2,3,4,12,19,24,233,2344)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(-9,-5,-1)", "(1,6,8,9)", "(-9,-5,-1,1,6,8,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(0,2,3)", "(0,1,2,5,7,9,11)", "(1,3,5,7,9,11)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(1,2,2,2,3,4)", "(1,3,5,7)", "(2,4,5,7)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(100,200,300,400)", "(100,200,200,300,400)","()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEXOR("(1,1,2,5)", "(2,3,3,5)", "(1,3)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(100,100,200,200,300,300,400,400)", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(-1,0,1,1,1,1,5,5,5,5,5)", "(-1,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(-5,-5,-4,0,2,3,5,6,7,9,10,15,50,65,78,150)", "(-4,0,2,3,5,6,7,9,10,15,50,65,78,150)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(0,1,2,2,3,3,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,10)", "(0,1,9,10)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(0,0,0,1,1,1)", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(1,1,2,2,2,3,3,3,3,5)", "(5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(5)", "(5)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(-1,0,1)", "(-1,0,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarDuplicadosListaOrdenadaDos("(0,1,1,2,2,2,3,3,3,3,4,4,4,4,4)", "(0)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaPalindromo("(1,0,1)", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("()", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1)", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,1)", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,2)", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,2,3)", false, nroPrueba), correctos, error);	
	FrameworkA1::ver(PruebaPalindromo("(1,2,3,4,3,3,1)", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,2,3,4,3,2,1)", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,2,3,4,3,2)", false, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,2,3,3,2,1)", true, nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaPalindromo("(1,1,1,1,1,1,1)", true, nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaEliminarSecuencia("()", "()", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(1,2,3,4,5,6,7,8,9,0)", "(2,3,4)", "(1,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(1,2,3,4,5,6,7,8,9,0)", "(2,4,5,6)", "(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(1,2,3,4,5,6,7,8,9,0)", "()", "(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("()", "(1,2,3,4,5,6,7,8,9,0)", "()", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(1,2,3,4,5,6,7,8,9,0)", "(1,2)", "(3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(1,2,3,4,5,6,7,8,9,0)", "(9,0)", "(1,2,3,4,5,6,7,8)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(1,2,1,2,4,5,6,7,8,9,0)", "(1,2)", "(1,2,4,5,6,7,8,9,0)", nroPrueba), correctos, error); 
		FrameworkA1::ver(PruebaEliminarSecuencia("(4,2,1,2,5,6,4,2,2,1)", "(4,2,2)", "(4,2,1,2,5,6,1)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaEliminarSecuencia("(4,3,2,1,4,3,2,1)", "(4,3,2,1,0)", "(4,3,2,1,4,3,2,1)", nroPrueba), correctos, error);

	nroPrueba = 1;
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 1, 2,"(2,1,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 1, 5,"(2,3,4,5,1,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 5, 1,"(5,1,2,3,4,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 1, 1,"(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 3, 11,"(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 3, 7,"(1,2,4,5,6,7,3,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 7, 3,"(1,2,7,3,4,5,6,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 12, 2,"(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 10, 9,"(1,2,3,4,5,6,7,8,0,9)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 10, 10,"(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 0, 10,"(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);
	FrameworkA1::ver(PruebaMoverNodo("(1,2,3,4,5,6,7,8,9,0)", 10, 0,"(1,2,3,4,5,6,7,8,9,0)", nroPrueba), correctos, error);

	cout << "----------------------------------------------"<<endl;
	cout << "----------------------------------------------"<<endl;
	cout << "PRUEBAS CORRECTAS: " << correctos << endl;
	cout << "PRUEBAS INCORRECTAS: " << error << endl;
}

#endif