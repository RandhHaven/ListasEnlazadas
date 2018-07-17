#include<iostream>
using namespace std;

#ifndef __NODO__
#define __NODO__

#ifndef NULL
#define NULL 0
#endif

template<class T>
class NODO
{
	private:
		/* elemento almacenado */ 
        T dato;
        
        /* puntero al siguiente nodo */
        NODO<T>* psiguiente;
	public:
		/* Constructor */
		NODO(T dato);

		/* Destructor */
		~NODO(void);

		/* Obtiene el Puntero al Siguiente */
		NODO* ObtenerSiguiente();

		/* Setea el Puntero al Siguiente */
		void SetSiguiente(NODO* psig);

		/* Obtiene el Dato del Nodo */
		T ObtenerDato();

		/* Setea Dato del Nodo */
		void SetDato(T dato);
};

#endif

//////////////////////////////////////////////////////////////////////////////////
template<class T>
NODO<T>::NODO(T dato)
{
	this->dato = dato;
	this->psiguiente = NULL;
}

template<class T>
NODO<T>::~NODO(void) {}

template<class T>
void NODO<T>::SetSiguiente(NODO* psig)
{
	this->psiguiente = psig;
}

template<class T>
NODO<T>* NODO<T>::ObtenerSiguiente()
{
	return this->psiguiente;
}

template<class T>
void NODO<T>::SetDato(T dato)
{
	this->dato = dato;
}

template<class T>
T NODO<T>::ObtenerDato()
{
	return this->dato;
}