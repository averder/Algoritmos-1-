#include "FuncAux.h"

//#ifndef FUNCAUX_CPP
//#define FUNCAUX_CPP

struct NodoListaAux {
	int dato;
	bool esVacio;
	NodoListaAux *sig;
	NodoListaAux(int x, bool vacio) : dato(x), esVacio(vacio), sig(NULL) {}
	NodoListaAux() : dato(-1), esVacio(true), sig(NULL) {} //constructor por defecto
};

/*
struct NodoABNivel {
	int dato;
	int nivel;
	NodoABNivel *izq;
	NodoABNivel *der;
	NodoABNivel() : dato(-1), izq(NULL), der(NULL), nivel(-1) {}
	NodoABNivel(int x, int n) : dato(x), izq(NULL), der(NULL), nivel(n) {}
};
*/

void append(char *&str, char *strA);
char *intToStr(int i);
unsigned int cantDatos(NodoListaS* l);
unsigned int cantDatos(NodoListaAux* l);
NodoAB *convertListaAuxToAB(NodoListaAux* & l, int &largo);
NodoAG *convertListaAuxToAG(NodoListaAux* & l, int &largo);
void destruir(NodoListaAux *&l);
void agregarFin(NodoListaS *&l, int val);
void abALista(NodoAB *a, NodoListaS *&l);
unsigned int pow2(unsigned pwr);
unsigned int altura(NodoAB* a);
void recorroABYCargoVector(NodoAB *a, NodoAB **vec, unsigned int posVecActual, unsigned int largoVec);
/*
PRE:
POS:ordena el vector recibido
*/
void ordenarVector(int *vec, int largoVec);
/*
PRE:
POS:devuelve un vector ordenado con los datos del arbol a 
*/
int *abAVectorOrdenado(NodoAB *a, int &largoVec);

/*
PRE: 
POS: concatena dest y src, poniendo src al final de dest. Aumenta el tamaño  de dest.
*/
void concat(char *&dest, char *src);
/*
PRE: debe recibir un vector de strings del largo indicado
POS: imprime el vector vec
*/
void imprimirVectorStrings(char** vec, int largo);
/*
PRE: debe recibir una matriz que debe tener las columnas y filas indicadas
POS: imprime matriz mat
*/
void imprimirMatrizInts(int** mat, int columnas, int filas);
/*
PRE:
POS:Imprime lista l
*/
void imprimirLista(NodoListaS *l);

/*
PRE: todos los caracteres de stringDatos son enteros. Formato: "1,4,7,2"
POS: devuelve un vector con los enteros de stringDatos y retorna la cantidad de datos en el parametro largo
	 El vector retornado debe ser destruido
*/
int *parsearVectorInt(char *stringDatos, int &largo);
/*
PRE: todos los caracteres de stringDatos son strings. Formato: "'str1','str2','str3'"
POS: devuelve un vector de strings con los datos de stringDatos y retorna la cantidad de datos en el parametro largo
	 El vector retornado y cada uno de los strings debe ser destruido
*/
char **parsearVectorStrings(char *stringDatos, int &largo);
/*
PRE: todos los caracteres de stringDatos son enteros. Formato "2,4,1,8"
POS: devuelve una lista con los enteros de stringDatos y el largo
*/
NodoListaS *parsearLista(char *stringDatos, int &largo);
/*
PRE: los caracteres de stringDatos son enteros o #. # indica fin de la rama. Formato "2,#,8,1,2"
POS: devuelve una arbol con los datos de stringDatos y la cantidad de elementos
*/
NodoAB* parsearAB(char *stringDatos, int &largo);
/*
PRE:
POS: devuelve una nueva lista, igual a l
*/
NodoListaS *copiarLista(NodoListaS *l);
/*
PRE:
POS: devuelve la altura de a
*/
unsigned int altura(NodoAB* a);
/*
PRE:
POS: devuelve cantidad de nodos de a
*/
unsigned int cantDatos(NodoAB* a);
/*
PRE:
POS: retorna el maximo de un AB no vacio
*/ 
int maxAB(NodoAB *a);
/*
PRE:
POS: retorna el minimo de un AB no vacio
*/ 
int minAB(NodoAB *a);
unsigned int cantDatos(NodoAG* a);



void imprimirVectorStrings(char** vec, int largo){
	if(vec!=NULL){
		for(int i=0; i < largo; i++){
			int j = 0;
			while(vec[i][j]!='\0') {
				cout<<vec[i][j];
				j++;
			} 
			cout<<" ";
		}
		cout << endl;
	}else
		cout<<"Array Vacio!"<<endl;
}

void imprimirMatrizInts(int** mat, int columnas, int filas){
	if(mat!=NULL){
		for(int f=0; f < filas; f++){
			for(int c=0; c < columnas; c++){
				cout<<mat[c][f] <<"\t";
			} 
			cout<<endl;
		}
	}else
		cout<<"Matriz Vacia!"<<endl;
}








void imprimirListaAux(NodoListaS *l) {
	if (l == NULL)
		return;
	cout << l->dato;
	if (l->sig != NULL)
		cout << ",";
	imprimirListaAux(l->sig);
}

void imprimirLista(NodoListaS *l) {
	cout << "{";
	imprimirListaAux(l);
	cout << "}";
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoListaS *esp, NodoListaS *rec) {
	cout << "\tParametros de entrada: FrameworkA1::ver ARCHIVO DE PRUEBAS" << endl;
	cout << "\tSe esperaba: ";
	imprimirLista(esp);
	cout << endl;
	cout << "\tSe recibio:  ";
	imprimirLista(rec);
	cout << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoListaS *esp, NodoListaS *rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: ";
	imprimirLista(esp);
	cout << endl;
	cout << "\tSe recibio:  ";
	imprimirLista(rec);
	cout << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoAB *esp, NodoAB *rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << FrameworkA1::serializar(esp) << endl;
	cout << "\tSe recibio:  " << FrameworkA1::serializar(rec) << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoAG *esp, NodoAG *rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << FrameworkA1::serializar(esp) << endl;
	cout << "\tSe recibio:  " << FrameworkA1::serializar(rec) << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(bool esp, bool rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << FrameworkA1::serializar(esp) << endl;
	cout << "\tSe recibio:  " << FrameworkA1::serializar(rec) << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(int esp, int rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << FrameworkA1::serializar(esp) << endl;
	cout << "\tSe recibio:  " << FrameworkA1::serializar(rec) << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(char *esp, char *rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << esp << endl;
	if (rec != NULL)
		cout << "\tSe recibio:  " << rec << endl;
	else
		cout << "\tSe recibio:  " << "NULL" << endl;
}

void FrameworkA1::ver(bool res, int &correctos, int &error) {
	if (res == true)
		correctos++;
	else
		error++;
}





//
//// IMPRIME LOS ELEMENTOS DEL ARBOL POR NIVELES CON EL #. TODO: quitar los # del final (pero que quede siempre par)
//void imprimirABAux(NodoAB *a) {
//	if(a==NULL){
//		return;
//	}
//	ColaArray c = crearColaArray(pow2(altura(a)+1) - 1); // calculo lugar para todos los nodos del arbol como si fuera completo mas un nivel extra por los #
//	encolar(c, a);
//	while(!esVacia(c)){
//		NodoAB* nodo = (NodoAB*)frente(c);
//		if (nodo == NULL)
//			cout << "#";
//		else
//			cout << nodo->dato;
//		
//		desencolar(c);
//		if (nodo != NULL) {
//		//if (nodo->izq != NULL) {
//			encolar(c, nodo->izq);
//		//}
//		//if (nodo->der != NULL) {
//			encolar(c, nodo->der);
//		//}
//		}
//		if (!esVacia(c)) 
//			cout << ",";
//	}	
//	FrameworkA1::destruir(c);
//	return;
//}


void recorroABYCargoVector(NodoAB *a, NodoAB **vec, unsigned int posVecActual, unsigned int largoVec) {
	if (a==NULL)
		return;
	recorroABYCargoVector(a->izq, vec, 2*posVecActual+1, largoVec);
	assert(posVecActual < largoVec);
	vec[posVecActual] = a;
	recorroABYCargoVector(a->der, vec, 2*posVecActual+2, largoVec);
}

void FrameworkA1::imprimirABGrande(NodoAB *a) {
//	imprimirAB(a);
	if (a == NULL) {
		cout << "Arbol vacio" << endl;
		return;
	}

	unsigned int alt = altura(a);
	unsigned int largoVec = pow2(alt) - 1; 
	NodoAB **vec = new NodoAB*[largoVec];
	for (unsigned int i=0; i<largoVec; i++)
		vec[i] = NULL;
	recorroABYCargoVector(a, vec, 0, largoVec);

	//for (unsigned int i=0; i<largoVec; i++) {
	//	if (vec[i] == NULL)
	//		cout << "# ";
	//	else
	//		cout << vec[i]->dato << " ";
	//}
	//cout << endl;

	unsigned int cantNodosUltimoNivel = pow2(alt-1);

	for (unsigned int i=1; i<=alt; i++) {
		unsigned int posInicialNivel = pow2(i-1) - 1; 
		unsigned int cantNodosNivel = pow2(i-1);
		unsigned int espacios;
		if (alt == i) {
			espacios = 0;
			cout << " ";
		}
		else
			espacios = pow2(alt - i - 1);
		//for (unsigned int i=0; i<espacios; i++) {
		//	cout << setw(3) << "";
		//}
		for (unsigned int j=posInicialNivel; j<posInicialNivel+cantNodosNivel; j++) {
			for (unsigned int k=0; k<espacios; k++)
				cout << setw(3) << "";
			assert(j < largoVec);
			if (vec[j] == NULL)
				cout << setw(3) << "#";
			else
				cout << setw(3) << vec[j]->dato;
			//for (unsigned int i=0; i<espacios; i++)
			//	cout << setw(3) << "";
		}
		cout << endl;
	}

}



// PRE: 
// POS: RETORNA STRING CON LOS ELEMENTOS DEL ARBOL POR NIVELES CON EL #. NOTA: tambien quita los # del final pero lo deja siempre par)
char *abAStrAux(NodoAB *a) {
	int numConsecutivos = 0, cantElementos = 0;
	char *ret = FrameworkA1::copioString("");
	char *aux;
	if(a==NULL){
		return ret;
	}
	ColaArray c = crearColaArray(pow2(altura(a)+1) - 1); // calculo lugar para todos los nodos del arbol como si fuera completo mas un nivel extra por los #
	ColaArray salida = crearColaArray(pow2(altura(a)+1) - 1); // calculo lugar para todos los nodos del arbol como si fuera completo mas un nivel extra por los #
	encolar(c, a);
	while(!esVacia(c)){
		NodoAB* nodo = (NodoAB*)frente(c);
		if (nodo == NULL) {
			aux = FrameworkA1::copioString("#");
			encolar(salida, aux);
			numConsecutivos++;
			cantElementos++;
		}
		else {
			aux = intToStr(nodo->dato);
			encolar(salida, aux);
			numConsecutivos = 0;
			cantElementos++;
		}
		
		desencolar(c);
		if (nodo != NULL) {
		//if (nodo->izq != NULL) {
			encolar(c, nodo->izq);
		//}
		//if (nodo->der != NULL) {
			encolar(c, nodo->der);
		//}
		}
	}	
	destruir(c);

	if (numConsecutivos % 2 != 0) 
		numConsecutivos--;
	int cantidadACopiar = cantElementos - numConsecutivos;
	// concateno en el string a retornar
	concat(ret, "{");
	for (int i=0; i<cantidadACopiar; i++) { //while (!esVacia(salida)) {
		aux = (char*)frente(salida);
		desencolar(salida);
		concat(ret, aux);
		delete [] aux;
		if (i < cantidadACopiar-1) {
			concat(ret, ",");
		}
	}
	concat(ret, "}");
	destruir(salida);
	
	return ret;
}



// PRE: 
// POS: RETORNA STRING CON LOS ELEMENTOS DEL AG
char *agAStrAux(NodoAG *a) {
	char *ret = FrameworkA1::copioString("");
	if(a==NULL){
		append(ret, ",#");
		return ret;
	}
	append(ret, ",");
	char *aux = intToStr(a->dato);
	append(ret, aux);
	char *ph = agAStrAux(a->ph);
	append(ret, ph);
	delete [] ph;
	char *sh = agAStrAux(a->sh);
	append(ret, sh);
	delete [] sh;
	return ret;
}



unsigned int pow2( unsigned pwr ) {
   return pwr==0? 1 : 2*pow2(pwr-1);
}

char *FrameworkA1::copioString(const char *str) {
	unsigned int len = strlen(str) + 1;
	char *ret = new char[len];
	strcpy_s(ret, len, str);
	return ret;
}

void append(char *&str, char *strA)
{
	unsigned int l = strlen(str) + strlen(strA) + 1;
	char *ret = new char[l];
	strcpy_s(ret, l, str);
	strcat_s(ret, l, strA);
	delete [] str;
	str = ret;
}

char *intToStr(int i) {
	unsigned int len = 11 + 1; // int min: -2147483648 max: 2147483647
	char *ret = new char[len];
	_itoa_s(i, ret, len, 10);
	char *ret2 = FrameworkA1::copioString(ret); // reservo la memoria justa
	delete [] ret;
	return ret2;
}

void concat(char *&dest, char *src) {
	unsigned int retL = strlen(dest) + strlen(src) + 1;
	char *ret = new char[retL];
	strcpy_s(ret, retL, dest);
	strcat_s(ret, retL, src);
	delete [] dest;
	dest = ret;
}

NodoListaS * copiarLista(NodoListaS *l) {
	if (l == NULL)
		return NULL;
	NodoListaS *n = new NodoListaS(l->dato);
	n->sig = copiarLista(l->sig);
	return n;
}

void borrarPpio(NodoListaAux* & l) {
	NodoListaAux* temp = l;
	l = l->sig;
	delete temp;
}

void agregarFin(NodoListaS *&l, int val)
{
    if (l == NULL)
        l = new NodoListaS(val);
    else
        agregarFin(l->sig, val);
}


void ordenarVector(int *vec, int largoVec) {
	for (int i = 0; i < largoVec; i++) {
		for (int j = 0; j < largoVec - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				int aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}
}

void listaAVector(NodoListaS *l, int *vec, int &pos)
{
    if (l != NULL) {
        vec[pos++] = l->dato;
		listaAVector(l->sig, vec, pos);
    }
}

int *listaAVectorOrdenado(NodoListaS *l, int &largoVec) {
	largoVec = cantDatos(l);
	int *vec = new int[largoVec];
	int pos = 0;
	listaAVector(l, vec, pos);
	ordenarVector(vec, largoVec);
	return vec;
}

void abAVector(NodoAB *a, int *vec, int &pos)
{
    if (a != NULL) {
        abAVector(a->izq, vec, pos);
        vec[pos++] = a->dato;
        abAVector(a->der, vec, pos);
    }
}

int *abAVectorOrdenado(NodoAB *a, int &largoVec) {
	largoVec = cantDatos(a);
	int *vec = new int[largoVec];
	int pos = 0;
	abAVector(a, vec, pos);
	ordenarVector(vec, largoVec);
	return vec;
}

void agAVector(NodoAG *a, int *vec, int &pos)
{
    if (a != NULL) {
        agAVector(a->ph, vec, pos);
        vec[pos++] = a->dato;
        agAVector(a->sh, vec, pos);
    }
}

int *agAVectorOrdenado(NodoAG *a, int &largoVec) {
	largoVec = cantDatos(a);
	int *vec = new int[largoVec];
	int pos = 0;
	agAVector(a, vec, pos);
	ordenarVector(vec, largoVec);
	return vec;
}



unsigned int cantDatos(NodoListaAux* l) {
	if (l == NULL)
		return 0;
	return cantDatos(l->sig) + 1;
}

unsigned int cantDatos(NodoListaS* l) {
	if (l == NULL)
        return 0;
    return cantDatos(l->sig) + 1;
}

unsigned int cantDatos(NodoAB* a) {
	if (a == NULL)
        return 0;
    return cantDatos(a->izq) + cantDatos(a->der) + 1;
}

unsigned int cantDatos(NodoAG* a) {
	if (a == NULL)
        return 0;
    return cantDatos(a->ph) + cantDatos(a->sh) + 1;
}

unsigned int altura(NodoAB* a) {
    if (a == NULL)
        return 0;
    return max(altura(a->izq), altura(a->der)) + 1;
}











void FrameworkA1::destruir(char** vec, int largo){
	if(vec!=NULL){
		for(int i=0; i < largo; i++){
			delete [] vec[i];
		}
		delete vec;
	}
}

void FrameworkA1::destruir(int** mat, int columnas){
	if(mat!=NULL){
		for(int i=0; i < columnas; i++){
			delete [] mat[i];
		}
		delete mat;
	}else
		cout<<"Matriz Vacia!"<<endl;
}

void FrameworkA1::destruir(int* vec) {
	if(vec!=NULL){
		delete vec;
	}
}

void FrameworkA1::destruir(NodoListaS *&l) {
    while (l!=NULL) {
        NodoListaS *aux = l;
        l = l->sig;
        delete aux;
		l = NULL;
    }
}

void destruir(NodoListaAux *&l) {
    while (l!=NULL) {
        NodoListaAux *aux = l;
        l = l->sig;
        delete aux;
		l = NULL;
    }
}

void FrameworkA1::destruir(NodoAB *&a) {
    while (a!=NULL) {
        FrameworkA1::destruir(a->izq);
        FrameworkA1::destruir(a->der);
        delete a;
		a = NULL;
    }
}

void FrameworkA1::destruir(NodoAG *&a) {
    while (a!=NULL) {
        FrameworkA1::destruir(a->ph);
        FrameworkA1::destruir(a->sh);
        delete a;
		a = NULL;
    }
}



bool FrameworkA1::sonIguales(char* resultado, char* esperado){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;
	
	return strcmp(resultado, esperado) == 0;
}

bool FrameworkA1::sonIguales(int* resultado, int* esperado, int largo){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int i=0; i < largo; i++){
		if (resultado[i]!=esperado[i])
			return false; 
	}	
	return true;
}

bool FrameworkA1::sonIguales(int** resultado, int** esperado,int columnas,int filas){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int f=0; f < filas; f++){
		for(int c=0; c < columnas; c++){
			if (resultado[c][f]!=esperado[c][f])
				return false;
		} 
	}	
	return true;
}

bool FrameworkA1::sonIguales(char** resultado, char** esperado, int cantStr){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int f=0; f < cantStr; f++){
		if(strcmp(resultado[f], esperado[f]) != 0) 
			return false;
	}
	return true;
}

bool FrameworkA1::sonIguales(char** resultado, char** esperado, int columnas, int filas) {
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int f=0; f < filas; f++){
		for(int c=0; c < columnas; c++){
			if (resultado[c][f]!=esperado[c][f])
				return false;
		} 
	}	
	return true;
}

bool FrameworkA1::sonIgualesDatosForma(NodoListaS *l1, NodoListaS *l2) {
    if (l1 == NULL && l2 == NULL)
        return true;
    if (l1 == NULL || l2 == NULL)
        return false;
    if (l1->dato != l2->dato)
        return false;
    return FrameworkA1::sonIgualesDatosForma(l1->sig, l2->sig);
}

bool FrameworkA1::sonIgualesDatos(NodoListaS *l1, NodoListaS *l2) {
	int largo1, largo2;
	int *v1 = listaAVectorOrdenado(l1, largo1);
	int *v2 = listaAVectorOrdenado(l2, largo2);
	bool ret;
	if (largo1 != largo2)
		ret = false;
	else
		ret = FrameworkA1::sonIguales(v1, v2, largo1);
	delete [] v1;
	delete [] v2;
	return ret;
}

bool FrameworkA1::sonIgualesDatosForma(NodoAB *a1,NodoAB *a2) {
	if (a1 == NULL && a2 == NULL)
        return true;
    if (a1 == NULL || a2 == NULL)
        return false;
    if (a1->dato != a2->dato)
        return false;
    return FrameworkA1::sonIgualesDatosForma(a1->izq, a2->izq) && FrameworkA1::sonIgualesDatosForma(a1->der, a2->der);
}

bool FrameworkA1::sonIgualesDatos(NodoAB *a1, NodoAB *a2) {
	int largo1, largo2;
	int *v1 = abAVectorOrdenado(a1, largo1);
	int *v2 = abAVectorOrdenado(a2, largo2);
	bool ret;
	if (largo1 != largo2)
		ret = false;
	else
		ret = FrameworkA1::sonIguales(v1, v2, largo1);
	delete [] v1;
	delete [] v2;
	return ret;
}

bool FrameworkA1::sonIgualesDatosForma(NodoAG *a1,NodoAG *a2) {
	if (a1 == NULL && a2 == NULL)
        return true;
    if (a1 == NULL || a2 == NULL)
        return false;
    if (a1->dato != a2->dato)
        return false;
    return FrameworkA1::sonIgualesDatosForma(a1->ph, a2->ph) && FrameworkA1::sonIgualesDatosForma(a1->sh, a2->sh);
}

bool FrameworkA1::sonIgualesDatos(NodoAG *a1, NodoAG *a2) {
	int largo1, largo2;
	int *v1 = agAVectorOrdenado(a1, largo1);
	int *v2 = agAVectorOrdenado(a2, largo2);
	bool ret;
	if (largo1 != largo2)
		ret = false;
	else
		ret = FrameworkA1::sonIguales(v1, v2, largo1);
	delete [] v1;
	delete [] v2;
	return ret;
}

bool FrameworkA1::compartenMemoria(char** vec1, int largoVec1, char** vec2, int largoVec2) {
	if (vec1 == NULL || vec2 == NULL)
		return false;
	for(int i1=0; i1<largoVec1; i1++) {
		for(int i2=0; i2<largoVec2; i2++) {
			if (vec1[i1] == vec2[i2]) {
				return true;
			}
		}
	}
	return false;
}

bool FrameworkA1::compartenMemoria(NodoListaS *l1, NodoListaS *l2) {
	NodoListaS *l1aux = l1;
	NodoListaS *l2aux = l2;
	while (l1aux != NULL) {
		l2aux = l2;
		while (l2aux != NULL) {
			if (l1aux == l2aux) return true;
			l2aux = l2aux->sig;
		}
		l1aux = l1aux->sig;
	}
	return false;
}

bool FrameworkA1::compartenMemoria(int *vec1, int *vec2, int largoVec1, int largoVec2) {
	if (vec1 == NULL || vec2 == NULL)
	{
		return false;
	}
	int contador1 = 0;
	int contador2 = 0;
	while (contador1 < largoVec1)
	{
		contador2 = 0;
		while (contador2 < largoVec2)
		{
			if (&vec1[contador1] == &vec2[contador2]) return true;
			contador2++;
		}
		contador1++;
	}
	return false;
}

void abAVectorPunteros(NodoAB *a1, NodoAB **vec, unsigned int &pos) {
	if (a1 != NULL) {
		vec[pos++] = a1;
		abAVectorPunteros(a1->izq, vec, pos);
		abAVectorPunteros(a1->der, vec, pos);
	}
}

void agAVectorPunteros(NodoAG *a1, NodoAG **vec, unsigned int &pos) {
	if (a1 != NULL) {
		vec[pos++] = a1;
		agAVectorPunteros(a1->ph, vec, pos);
		agAVectorPunteros(a1->sh, vec, pos);
	}
}

bool FrameworkA1::compartenMemoria(NodoAB *a1, NodoAB *a2) {
	unsigned int pos1 = 0, pos2 = 0;
	unsigned int cant1 = cantDatos(a1);
	unsigned int cant2 = cantDatos(a2);
	NodoAB **vec1 = new NodoAB *[cant1];
	NodoAB **vec2 = new NodoAB *[cant2];
	abAVectorPunteros(a1, vec1, pos1);
	abAVectorPunteros(a2, vec2, pos2);

	for (unsigned int i1=0; i1<cant1; i1++) {
		for (unsigned int i2=0; i2<cant2; i2++) {
			if (vec1[i1] == vec2[i2]) return true;
		}
	}
	return false;
}

bool FrameworkA1::compartenMemoria(NodoAG *a1, NodoAG *a2) {
	unsigned int pos1 = 0, pos2 = 0;
	unsigned int cant1 = cantDatos(a1);
	unsigned int cant2 = cantDatos(a2);
	NodoAG **vec1 = new NodoAG *[cant1];
	NodoAG **vec2 = new NodoAG *[cant2];
	agAVectorPunteros(a1, vec1, pos1);
	agAVectorPunteros(a2, vec2, pos2);

	for (unsigned int i1=0; i1<cant1; i1++) {
		for (unsigned int i2=0; i2<cant2; i2++) {
			if (vec1[i1] == vec2[i2]) return true;
		}
	}
	return false;
}

// Retorna el maximo de un AB no vacio
int maxAB(NodoAB *a) 
{
	if (a->izq == NULL && a->der == NULL)
		return a->dato;
	if (a->izq == NULL)
		return max(maxAB(a->der), a->dato);
	if (a->der == NULL)
		return max(maxAB(a->izq), a->dato);
	int maxIzq2 = max(maxAB(a->izq), a->dato);
	int maxDer2 = max(maxAB(a->der), a->dato);
	return max(maxIzq2, maxDer2);
}

// Retorna el minimo de un AB no vacio
int minAB(NodoAB *a) 
{
	if (a->izq == NULL && a->der == NULL)
		return a->dato;
	if (a->izq == NULL)
		return min(minAB(a->der), a->dato); 
	if (a->der == NULL)
		return min(minAB(a->izq), a->dato);
	int minIzq2 = min(minAB(a->izq), a->dato);
	int minDer2 = min(minAB(a->der), a->dato);
	return min(minIzq2, minDer2);
}

bool FrameworkA1::esABB(NodoAB *a) 
{
	if (a == NULL) 
		return true;
	if (a->izq != NULL && maxAB(a->izq) > a->dato)
		return false;
	if (a->der != NULL && minAB(a->der) < a->dato)
		return false;
	return FrameworkA1::esABB(a->izq) && FrameworkA1::esABB(a->der);
}




int *parsearVectorInt(char *stringDatos, int &largo) {
	NodoListaS *l = parsearLista(stringDatos, largo);
	largo = cantDatos(l);
	if (largo == 0)
		return NULL;
	int *ret = new int[largo];
	NodoListaS *aux = l;
	for (int i=0; i<largo; i++) {
		ret[i] = aux->dato;
		aux = aux->sig;
	}
	return ret;
}

char **parsearVectorStrings(char *stringDatos, int &largo) {
	unsigned int largoStr = strlen(stringDatos);
	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	int cant = 0;
	for(unsigned int i=0; i<largoStr; i++) {
		if (stringDatosC[i] == '\'') {
			cant++;
			for(i++; i<largoStr; i++) {
				if (stringDatosC[i] == '\'') {
					break;
				}
			}
		}
	}
	largo = cant;
	if (largo == 0)
		return NULL;
	char** ret = new char*[largo];
	int pos = 0;
	for(unsigned int i=0; i<largoStr; i++) {
		if (stringDatosC[i] == '\'') {
			char *ini = &stringDatosC[i+1];
			for(i++; i<largoStr; i++) {
				if (stringDatosC[i] == '\'') {
					stringDatosC[i] = '\0';
					ret[pos++] = FrameworkA1::copioString(ini);
					break;
				}
			}
		}
	}
	delete [] stringDatosC;
	return ret;
}

NodoListaS *parsearLista(char *stringDatos, int &largo) {
	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	NodoListaS *ret = NULL;
	NodoListaS *ant = NULL;
	largo = 0;
	char *next_token1;
	char *token1 = strtok_s(stringDatosC, ", ", &next_token1);
	while (token1 != NULL) {
		int val = atoi(token1);
		largo++;
		NodoListaS *n = new NodoListaS(val);
		if (ret == NULL) {
			ret = ant = n;
		}
		else {
			ant->sig = n;
			ant = n;
		}
		token1 = strtok_s(NULL, ", ", &next_token1);
	}
	delete [] stringDatosC;
	return ret;
}

NodoListaAux* splitStringToListaAux(char *stringDatos) {
	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	NodoListaAux *ret = NULL;
	NodoListaAux *ant = NULL;
	char *next_token1;
	char *token1 = strtok_s(stringDatosC, ", ", &next_token1);
	while (token1 != NULL) {
		NodoListaAux *n;
		if(token1[0] == '#'){
			n = new NodoListaAux(-1, true);
		}else{
			int val = atoi(token1);
			n = new NodoListaAux(val, false);
		}
		if (ret == NULL) {
			ret = ant = n;
		}
		else {
			ant->sig = n;
			ant = n;
		}
		token1 = strtok_s(NULL, ", ", &next_token1);
	}
	delete [] stringDatosC;
	return ret;
}

NodoAB *convertListaAuxToAB(NodoListaAux* & l, int &largo){
	ColaArray c = crearColaArray(cantDatos(l));
	NodoAB* a = NULL;
	if(l==NULL || l->esVacio){
		destruir(c);
		largo = 0;
		return a;
	}
	largo = 1;
	a = new NodoAB(l->dato);
	encolar(c, a);
	borrarPpio(l);
	while(!esVacia(c)){
		NodoAB* nodo = (NodoAB*)frente(c);
		desencolar(c);
		if(l!=NULL){
			if (!l->esVacio) {
				largo++;
				nodo->izq = new NodoAB(l->dato);
				encolar(c, nodo->izq);
			}
			borrarPpio(l);
		}
		if(l!=NULL){
			if (!l->esVacio) {
				largo++;
				nodo->der = new NodoAB(l->dato);
				encolar(c, nodo->der);
			}
			borrarPpio(l);
		}
	}	
	destruir(c);
	return a;
}

NodoAG *convertListaAuxToAG(NodoListaAux* & l, int &largo){
	if (l == NULL)
		return NULL;

	NodoAG* a = NULL;

	
	return a;
}

void convertListaAuxToAG(NodoListaAux* &l, NodoAG *&a, int &largo){
	if (l == NULL)
	{
		a = NULL;
		return;		
	}

	if (l->esVacio)
	{
		a = NULL;
		borrarPpio(l);
		return;
	}

	a = new NodoAG(l->dato);
	largo++;
	borrarPpio(l);
	convertListaAuxToAG(l, a->ph, largo);
	convertListaAuxToAG(l, a->sh, largo);
}

NodoAB* parsearAB(char *stringDatos, int &largo) {
	NodoListaAux *listaAB = splitStringToListaAux(stringDatos);
	NodoAB* ret = convertListaAuxToAB(listaAB, largo);
	return ret;
}

NodoAG* parsearAG(char *stringDatos, int &largo) {
	NodoListaAux *listaAux = splitStringToListaAux(stringDatos);
	largo = 0;
	NodoAG* ret;
	convertListaAuxToAG(listaAux, ret, largo);
	return ret;
}

void* FrameworkA1::parsearColeccion(char *stringDatos, int &largo) {
	// detecto tipo de dato
	NodoAB *a;
	NodoAG *ag;
	NodoListaS *l;
	char **vecStr;
	int *vecInt;

	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	char *ini = &stringDatosC[1];
	stringDatosC[strlen(stringDatosC)-1] = '\0';
	switch (stringDatos[0]) {
	case '{': // arbol
		if (stringDatos[1] != '{') { //AB
			a = parsearAB(ini, largo);
			delete [] stringDatosC;
			return a;
		}
		else // AG
		{
			ini++;
			stringDatosC[strlen(stringDatosC)-1] = '\0';
			ag = parsearAG(ini, largo);
			delete [] stringDatosC;
			return ag;
		}
	case '(': // lista
		l = parsearLista(ini, largo);
		delete [] stringDatosC;
		return l;
	case '[': // vector
		if (stringDatosC[1] == '\'') { // vector string
			vecStr = parsearVectorStrings(ini, largo);
			delete [] stringDatosC;
			return vecStr;
		}
		else { // vector int
			vecInt = parsearVectorInt(ini, largo);
			delete [] stringDatosC;
			return vecInt;
		}
	}

	return NULL; // no se reconoce el formato
}

char *FrameworkA1::serializar(int i) {
	return intToStr(i);
}

char *FrameworkA1::serializar(bool b) {
	char *str;
	if (b) {
		str = FrameworkA1::copioString("true");
	}
	else {
		str = FrameworkA1::copioString("false");
	}
	return str;
}

void serializarAux(NodoListaS *l, char *&str) {
	if (l == NULL)
		return;
	char *strNum = FrameworkA1::serializar(l->dato);
	concat(str, strNum);
	delete [] strNum;
	if (l->sig != NULL)
		concat(str, ",");
	serializarAux(l->sig, str);
}

char *FrameworkA1::serializar(NodoListaS *l) {
	char *str;
	if(l!=NULL){
		str = FrameworkA1::copioString("(");
		serializarAux(l, str);
		concat(str, ")");
	}else {
		str = FrameworkA1::copioString("()");
	}
	return str;
}

char *FrameworkA1::serializar(NodoAB *a) {
	char *str;
	if(a!=NULL){
		str = abAStrAux(a);
	}else {
		str = FrameworkA1::copioString("{}");
	}
	return str;
}

char *FrameworkA1::serializar(NodoAG *a) {
	char *str;
	if(a!=NULL){
		str = copioString("{{");
		char *str2 = agAStrAux(a);
		char *str3 = str2;
		if (strlen(str3) > 0) str3++;
		append(str, str3);
		delete [] str2;
		append(str, "}}");
	}else {
		str = FrameworkA1::copioString("{{}}");
	}
	return str;
}

char *FrameworkA1::serializar(int *vec, int largo) {
	char *str;
	if(vec!=NULL){
		str = FrameworkA1::copioString("[");
		for(int i=0; i < largo; i++){
			char *numStr = FrameworkA1::serializar(vec[i]);
			concat(str, numStr);
			delete [] numStr;
			if (i<largo-1)
				concat(str, ",");
		}
		concat(str, "]");
	}else {
		str = FrameworkA1::copioString("[]");
	}
	return str;
}

char *FrameworkA1::serializar(char **vecStr, int largo) {
	char *str;
	if(vecStr!=NULL){
		str = FrameworkA1::copioString("[");
		for(int i=0; i < largo; i++){
			concat(str, "\'");
			concat(str, vecStr[i]);
			concat(str, "\'");
			if (i<largo-1)
				concat(str, ",");
		}
		concat(str, "]");
	}else {
		str = FrameworkA1::copioString("[]");
	}
	return str;
}
