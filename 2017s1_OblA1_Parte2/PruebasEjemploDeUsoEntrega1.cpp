
#include "PruebasEjemploDeUsoEntrega1.h"

PruebasEjemploDeUsoEntrega1::PruebasEjemploDeUsoEntrega1(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUsoEntrega1::~PruebasEjemploDeUsoEntrega1()
{
	
}
char* PruebasEjemploDeUsoEntrega1::getNombre()const
{
	return "PruebasEjemploDeUsoEntrega1";
}

void PruebasEjemploDeUsoEntrega1::correrPruebaConcreta()
{
	PruebasEjerciciosTAD();
	pruebaListaPos();
	pruebaPila();
	pruebaCola();
}

void PruebasEjemploDeUsoEntrega1::PruebasEjerciciosTAD()
{
	// Pruebas Enlistar
	this->mImpresion.iniciarSeccion("PRUEBAS Enlistar");
	pruebaEnlistar("{1,5,2}");
	ver3("Prueba de pasar AB a ListaOrd 1");
	
	pruebaEnlistar("{1,#,2,#,5}");
	ver3("Prueba de pasar AB a ListaOrd 2");

	pruebaEnlistar("{1,2,3,1,#,#,#,#,3,1,2,1,1,#,#,#,#,#,4,1,#,2,2}");
	ver3("Prueba de pasar AB a ListaOrd 3");
	this->mImpresion.cerrarSeccion("PRUEBAS Enlistar");


	// Pruebas UnionListaOrd
	this->mImpresion.iniciarSeccion("PRUEBAS UnionListaOrd");
	pruebaUnionListaOrd("(1,3,5,7,9)", "(2,4,6,8)");
	ver3("Prueba union de dos listas ordenadas 1");
	
	pruebaUnionListaOrd("(100,200,300,400)", "(100,200,300,400)");
	ver3("Prueba union de dos listas ordenadas 2");

	pruebaUnionListaOrd("()", "(-1,0,1,5)");
	ver3("Prueba union de dos listas ordenadas 3");
	this->mImpresion.cerrarSeccion("PRUEBAS UnionListaOrd");


	// Pruebas EstaContenida
	this->mImpresion.iniciarSeccion("PRUEBAS EstaContenida");
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1)");
	ver3("Prueba de pila contenida 1");
	
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1,4,8)");
	ver3("Prueba de pila contenida 2");

	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,1,4,8)");
	ver3("Prueba de pila contenida 3");

	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,4,4,7,1,4,8)");
	ver3("Prueba de pila contenida 4");
	this->mImpresion.cerrarSeccion("PRUEBAS EstaContenida");


	// Pruebas CantidadDeHojas
	this->mImpresion.iniciarSeccion("PRUEBAS CantidadDeHojas");
	pruebaCantidadDeHojas("{1,5,2}");
	ver3("Prueba contar hojas AB iterativo 1");
	
	pruebaCantidadDeHojas("{1,#,2,#,5}");
	ver3("Prueba contar hojas AB iterativo 2");

	pruebaCantidadDeHojas("{1,2,3,1,#,#,#,#,3,1,2,1,1,#,#,#,#,#,4,1,#,2,2}");
	ver3("Prueba contar hojas AB iterativo 3");
	this->mImpresion.cerrarSeccion("PRUEBAS CantidadDeHojas");


	// Pruebas ImprimirPorNiveles
	this->mImpresion.iniciarSeccion("PRUEBAS ImprimirPorNiveles");
	pruebaImprimirPorNiveles("{1,5,2}");
	ver3("Prueba imprimir AB por niveles 1");
	
	pruebaImprimirPorNiveles("{1,#,2,#,5}");
	ver3("Prueba imprimir AB por niveles 2");

	pruebaImprimirPorNiveles("{1,2,3,1,#,#,#,#,3,1,2,1,1,#,#,#,#,#,4,1,#,2,2}");
	ver3("Prueba imprimir AB por niveles 3");
	this->mImpresion.cerrarSeccion("PRUEBAS ImprimirPorNiveles");

}


void PruebasEjemploDeUsoEntrega1::pruebaListaPos()
{
	this->mImpresion.iniciarSeccion("PRUEBAS LISTA POS");

	
	ListaPos<int>* l = new ListaPosImp<int>();


	//cout << "------------------- Prueba agregar principio ----------------------" << endl << endl << endl;
	
	l->AgregarPpio(4);
	l->AgregarPpio(5);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar 2 datos al principio");

	
	//cout << "------------------- Prueba agregar fin ----------------------" << endl << endl << endl;
	
	l->AgregarFin(2);
	l->AgregarFin(1);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar 2 datos al final");

	//cout << "------------------- Prueba agregar posición ----------------------" << endl << endl << endl;
	
	l->AgregarPos(3,2);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar el dato 3 en la posición 2");

	
	//cout<<"--------------------Prueba largo de la lista-------------------"<<endl<<endl<<endl;
	
	cout << l->CantidadElementos()<<endl;
	ver3("Imprimo el largo de la lista");

	
	//cout<<"--------------------Prueba clon de la lista-------------------"<<endl<<endl<<endl;
	
	
	ListaPos<int>* clonL = l->Clon();
	cout << "Resultado Original: " << endl << *l<< endl << endl;
	cout << "Resultado Clon: " << endl << *clonL << endl;
	ver3("Imprimo el la lista original y su clon");
	
	ListaPos<int> *l2 = l->CrearVacia();
	cout<<"["<<*l2<<"]"<<endl;
	ver3("Imprimo luego de crearvacia");

	*l2 = *l;
	cout<<"["<<*l2<<"]"<<endl;
	ver3("Imprimo luego de =");
	
	//cout<<"--------------------Prueba == de la lista (iguales)-------------------"<<endl<<endl<<endl;

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}
	ver3("Imprimo prueba de == sobre listas iguales");

	//cout<<"--------------------Prueba == de la lista (diferentes)-------------------"<<endl<<endl<<endl;
	clonL->BorrarPpio();

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}
	cout << "Resultado Original: " << endl << *l<< endl << endl;

	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo prueba de == sobre listas distintas");

	*clonL = *l;
	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo clon luego de asignarle l");

	//cout<<"--------------------Prueba elemento principio-------------------"<<endl<<endl<<endl;
	

	cout << l->ElementoPpio()<<endl;
	ver3("Imprimo el principio de la lista");

	
	//cout<<"--------------------Prueba elemento fin-------------------"<<endl<<endl<<endl;
	

	cout << l->ElementoFin() <<endl;
	ver3("Imprimo el fin de la lista");

	
	//cout<<"--------------------Prueba elemento posición-------------------"<<endl<<endl<<endl;
	

	cout << l->ElementoPos(3) <<endl;
	ver3("Imprimo el elemento de la cuarta posición");
	
	
	//cout<<"--------------------Prueba eliminar elemento principio-------------------"<<endl<<endl<<endl;
	
	l->BorrarPpio();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el principio");

	//cout<<"--------------------Prueba eliminar elemento fin-------------------"<<endl<<endl<<endl;
	
	l->BorrarFin();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el fin");

	//cout<<"--------------------Prueba eliminar elemento posición-------------------"<<endl<<endl<<endl;
	
	l->BorrarPos(2);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el tercer elemento");

	
	//cout<<"--------------------Prueba eliminar elemento-------------------"<<endl<<endl<<endl;
	
	l->Borrar(3);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el elemento 3");

	
	//cout<<"--------------------Prueba posicion elemento-------------------"<<endl<<endl<<endl;
	
	cout << l->Posicion(4)<<endl;
	ver3("Imprimo la posicion del elemento 4");

	//cout<<"---------------------Prueba elemento pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(4))
	{
		cout<<"Elemento 4 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 4 no pertenece a la lista"<<endl<<endl<<endl;
	}

	ver3("Imprimo si el elemento 4 existe en la lista");

	//cout<<"---------------------Prueba elemento no pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(6))
	{
		cout<<"Elemento 6 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 6 no pertenece a la lista"<<endl<<endl<<endl;
	}

	ver3("Imprimo si el elemento 6 existe en la lista");
	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista se encuentra vacia");

	//cout<<"-------------------Prueba lista es vaciar ----------------------"<<endl<<endl<<endl;
	
	l->Vaciar();
	
	cout<<"["<<*l<<"]"<<endl<<endl<<endl;

	ver3("Imprimo la lista luego de vaciarla");

	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	
	ver3("Imprimo si la lista se encuentra vacia ");

	delete l;
	delete clonL;

	this->mImpresion.cerrarSeccion("PRUEBAS LISTA POS");
}

void PruebasEjemploDeUsoEntrega1::pruebaPila() 
{
	this->mImpresion.iniciarSeccion("PRUEBAS PILA");

	Pila<int>* p = new PilaImp<int>();

	//cout << "------------------- Prueba Pila agregar ----------------------" << endl << endl << endl;
	for (int i = 0; i < 10; i += 2)
	{
		p->Push(i);
	}
	for (int i = 1; i < 10; i += 2)
	{
		p->Push(i);
	}

	cout << *p << endl;
	ver3("Imprimo la pila luego de agregar 10 datos");

	// prueba elminar elemento
	cout << p->Top() << " == 9" << endl;
	p->Pop();
	cout << *p << endl;
	ver3("Imprimo la pila luego de eliminar elemento");

	//cout << "------------------- Prueba Pila no vacio ----------------------" << endl << endl << endl;

	Cadena c = p->EsVacia() ? "True" : "False";
	cout << "Es Vacia: " << c << " == False" << endl;
	ver3("Muestro que la pila no es vacia");
	
	//cout << "---------------------Prueba Clon Pila ----------------------" << endl << endl << endl;

	Pila<int> *clon = p->Clon();

	cout << "Resultado Original: " << endl << *p << endl;
	cout << "Resultado Clon: " << endl << *clon << endl;
	ver3("Clono la pila y imprimo tanto el clon como la original");

	Pila<int> *p2 = p->CrearVacia();
	cout<<"["<<*p2<<"]"<<endl;
	ver3("Imprimo luego de crearvacia");

	*p2 = *p;
	cout<<"["<<*p2<<"]"<<endl;
	ver3("Imprimo luego de =");
	
	//cout << "---------------------Prueba vaciar Pila ----------------------" << endl << endl << endl;

	p->Vaciar();

	cout << *p << endl;
	c = p->EsVacia() ? "True" : "False";
	cout << "Es Vacia: " << c << " == True" << endl;
	ver3("Vacio la pila original y la imprimo");

	//cout << "---------------------Prueba Crear Vacia Pila ----------------------" << endl << endl << endl;

	cout << *p << endl;
	Pila<int> *vacia = p->CrearVacia();
	c = vacia->EsVacia() ? "True" : "False";
	cout << "La nueva Pila es Vacia: " << c << " == True" << endl;
	ver3("Uso el metodo CrearVacia y muestro que es vacia");
	
	//cout << "--------------Prueba Largo Pila --------------" << endl << endl << endl;

	cout << "Resultado Pila Original: " << p->CantidadElementos() << " == 0" << endl << endl;
	cout << "Resultado Pila Clon: " << clon->CantidadElementos() << " == 9" << endl << endl;
	ver3("Muestro el largo de la pila clon y la original");

	//cout << "--------------Prueba Obtener Elementos Pila --------------" << endl << endl << endl;

	while (!clon->EsVacia())
	{
		cout << clon->Top() << " ";
		clon->Pop();
	}
	ver3("Muestro todos los elementos de la pila clon");

	delete p;
	delete clon;
	delete vacia;

	this->mImpresion.cerrarSeccion("PRUEBAS PILA");
}

void PruebasEjemploDeUsoEntrega1::pruebaCola(){
	this->mImpresion.iniciarSeccion("PRUEBAS COLA");
	Cola<int>* c = new ColaImp<int>();

	//cout << "------------------- Prueba agregar elemento ----------------------" << endl << endl << endl;
	for (int i = 5; i >0; i--){
		c->Encolar(i);
	}

	cout<<*c<<endl;
	ver3("Imprimo la cola luego de agregar 5 elementos");

	//cout << "------------------- Prueba primer elemento ----------------------" << endl << endl << endl;

	cout<< c->Principio()<<endl;

	ver3("Imprimo el primer elemento ");

	//cout << "------------------- Prueba desencolar----------------------" << endl << endl << endl;

	cout<< c->Desencolar()<<endl<<endl;

	cout<<*c<<endl;

	ver3("Imprimo el elemento desencolado y la cola");

	//cout << "------------------- Prueba largo de la cola----------------------" << endl << endl << endl;

	cout<<c->CantidadElementos()<<endl;

	ver3("Imprimo el largo de la cola");

	//cout << "---------------------Prueba Clon cola prioridad ----------------------" << endl << endl << endl;

	Cola<int> *clon = c->Clon();

	cout << "Resultado Original: " << endl << *c << endl << endl;

	cout << "Resultado Clon: " << endl << *clon << endl;

	ver3("Imprimo la cola original y el clon de la misma ");

	Cola<int> *c2 = c->CrearVacia();
	cout<<"["<<*c2<<"]"<<endl;
	ver3("Imprimo luego de crearvacia");

	*c2 = *c;
	cout<<"["<<*c2<<"]"<<endl;
	ver3("Imprimo luego de =");

	//cout << "------------------- Prueba vaciar----------------------" << endl << endl << endl;
	c->Vaciar();

	cout<<"["<<*c<<"]"<<endl;

	ver3("Imprimo la cola luego de vaciarla");

	//cout << "------------------- Prueba es vacia----------------------" << endl << endl << endl;
	
	if(c->EsVacia()){
		cout<<"Cola principal se encuentra vacia"<<endl<<endl;
	}else{
		cout<<"Cola principal no se encuentra vacia"<<endl<<endl;
	}

	if(clon->EsVacia()){
		cout<<"Cola clon se encuentra vacia"<<endl<<endl;
	}else{
		cout<<"Cola clon no se encuentra vacia"<<endl<<endl;
	}

	ver3("Imprimo si la cola y su clon son vacias");
	delete c;
	delete clon;
	this->mImpresion.cerrarSeccion("PRUEBAS COLA");
}
