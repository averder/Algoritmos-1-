#include "EjerciciosSem1.h"

#ifndef EJERCICIOSSEM1_CPP
#define EJERCICIOSSEM1_CPP



int Suma(int a, int b) {
    return a+b;
}

void TablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	for (int i = desde; i <= hasta  && hasta - desde !=0 ; i++)
	{
		if (i != hasta) {
			cout << i << "*" << tablaDel << "=" << tablaDel*i << ";";
		}
		else {
			cout << i << "*" << tablaDel << "=" << tablaDel*i ;
		}
		
	}
	if (hasta - desde == 0)
		cout << desde << "*" << tablaDel << "=" << tablaDel*desde ;
}

#endif
