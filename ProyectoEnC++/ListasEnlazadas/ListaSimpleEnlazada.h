#ifndef __ListaSimpleEnlazada__
#define __ListaSimpleEnlazada__

#include"NODO.h"

template<class T>
class ListaSimpleEnlazada
{
	private:
		NODO<T>* psiguiente;
		int tamanio;

	public:
		ListaSimpleEnlazada();

		~ListaSimpleEnlazada(void);

		void AgregarDato(T dato);

		bool EstaVacia();

		void RecorrerLista();

		int GetTamanio();

		T ObtenerDato(int posicion);

		void AgregarDatoPosicion(int posicion, T dato);

		T BorrarDatoPosicion(int posicion);

		void MostrarLista();

		NODO<T>* obtenerNodo(int posicion);
};

#endif

//////////////////////////////////////////////////////////////////////////////////

template<class T>
ListaSimpleEnlazada<T>::ListaSimpleEnlazada()
{
	this->psiguiente = NULL;
	this->tamanio = 0;
}

template<class T>
ListaSimpleEnlazada<T>::~ListaSimpleEnlazada()
{
	if (this->psiguiente)
	{
		NODO<T>* paux = this->psiguiente;
		while (paux)
		{
			paux = paux->ObtenerSiguiente();
			delete paux;
			paux = this->psiguiente;
		}
	}
}

template<class T>
void ListaSimpleEnlazada<T>::AgregarDato(T dato)
{
	NODO<T>* nuevo = new NODO<T>(dato);
	NODO<T>* paux = this->psiguiente;
	if (this->psiguiente == NULL)
		this->psiguiente = nuevo;
	else
	{
		while (paux->ObtenerSiguiente())
		{
			paux = paux->ObtenerSiguiente();
		}
		paux->SetSiguiente(nuevo);
	}
	this->tamanio++;

}

template<class T>
bool ListaSimpleEnlazada<T>::EstaVacia()
{
	return (this->tamanio == 0);
}

template<class T>
int ListaSimpleEnlazada<T>::GetTamanio()
{
	return this->tamanio;
}

template<class T>
T ListaSimpleEnlazada<T>::ObtenerDato(int posicion)
{
	NODO<T>* paux = this->psiguiente;
	T dato = NULL;
	if (posicion > this->GetTamanio() || this->EstaVacia())
	{
		dato = NULL;
		return dato;
	}
	else
	{
		int pos = 1;
		while ((paux->ObtenerSiguiente()) && (pos < posicion))
		{
			pos++;
			paux = paux->ObtenerSiguiente();
		}
		dato = paux->ObtenerDato();
	}
	return dato;
}

template<class T>
void ListaSimpleEnlazada<T>::AgregarDatoPosicion(int posicion, T dato)
{
	if (posicion > 0 && posicion < this->tamanio)
    {
        NODO<T>* insertar = new NODO<T>(dato);
        if (posicion == 1)
        {
            insertar->SetSiguiente(this->psiguiente);
            this->psiguiente = insertar;
        }
        else
        {
            NODO<T>* anterior = this->obtenerNodo(posicion - 1);
            insertar->SetSiguiente(anterior->ObtenerSiguiente());
            anterior->SetSiguiente(insertar);
        }
        this->tamanio++;
    }
}

template<class T>
NODO<T>* ListaSimpleEnlazada<T>::obtenerNodo(int posicion)
{
    NODO<T>* actual = this->psiguiente;
    if (posicion > 0 && posicion <= this->tamanio)
    {
        int contador = 1;
        while (contador < posicion)
        {
            actual = actual->ObtenerSiguiente();
        }
    }
    return actual;
}

template<class T>
T ListaSimpleEnlazada<T>::BorrarDatoPosicion(int posicion)
{
    T dato = NULL;
	if (!this->EstaVacia() && posicion > 0 && posicion < this->tamanio)
    {
        NODO<T>* nodoRecorrer = this->psiguiente;
        if (posicion == 1)
        {
            dato = nodoRecorrer->ObtenerDato();
            this->psiguiente = nodoRecorrer->ObtenerSiguiente();
        }
        else
        {
            int contador = 1;
            while (contador < posicion && nodoRecorrer->ObtenerSiguiente())
            {
                nodoRecorrer = nodoRecorrer->ObtenerSiguiente();
                contador++;
            }
            nodoRecorrer->SetSiguiente(nodoRecorrer->ObtenerSiguiente());
        }
        NODO<T>* eliminar = nodoRecorrer;
        dato = eliminar->ObtenerDato();
        delete eliminar;
        this->tamanio--;
    }
    return dato;
}

template<class T>
void ListaSimpleEnlazada<T>::MostrarLista()
{
    if (!this->EstaVacia())
    {
        NODO<T>* nodo = this->psiguiente;
        while (nodo)
        {
            cout << "El dato es: " << nodo->ObtenerDato() << endl;
            nodo = nodo->ObtenerSiguiente();
        }
    }
}
