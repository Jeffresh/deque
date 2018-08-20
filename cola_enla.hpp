#ifndef COLA_ENLA_HPP
#define COLA_ENLA_HPP
#include <cassert>

template<typename T>
class Cola
{

public:

	explicit Cola();
	Cola(const Cola<T>& c);
	Cola<T>& operator =(const Cola<T>& c);

	bool vacia();

	const T& frente();
	void pop();
	void push(const T& x);

	~Cola();

private:

	struct nodo
	{
		T elto;
		nodo* sig;

		nodo(const T& e, nodo* p=0): elto{e}, sig{p}{}
	};

	nodo *inicio, *fin;

	void copiar(const Cola<T>& C);

};

template<typename T>
void Cola<T>::copiar(const Cola<T>& C)
{
	if(C.inicio) // no está vacía
	{

		// copiar el primer elemento

		inicio = fin = new nodo(C.inicio->elto);


		for(nodo* p = C.inicio->sig ; p; p=p->sig)
		{	
			fin->sig = new nodo(p->elto);
			fin= fin->sig;
		}

	}

}

template<typename T>
Cola<T>::Cola():
inicio{0},
fin{0}
{}

template<typename T>
inline Cola<T>::Cola(const Cola& C){ copiar(C);}

template<typename T>
inline Cola<T>& Cola<T>::operator=(const Cola& C)
{
	if(this != &C) // evitar autoasignación
	{
		this->~Cola();
		copiar(C);
	}

	return *this;
}

template<typename T>
inline bool Cola<T>::vacia(){ return inicio == 0;}

template<typename T>
inline const T& Cola<T>::frente()
{
	return inicio->elto;

}

template<typename T>
void Cola<T>::pop()
{
	assert(!vacia());
	nodo* p = inicio;
	inicio = inicio->sig;
	if(!inicio) fin =0;

	delete p;
}

template<typename T>
void Cola<T>::push(const T& x)
{
	nodo* p = new nodo(x);

	if(inicio==0)
		inicio = fin = p;
	else
		fin = fin->sig =p;

}

template<typename T>
Cola<T>::~Cola()
{
	nodo* p;

	while(inicio)
	{
		p = inicio;
		inicio = inicio->sig;
		delete p;
	}

	fin = 0;

}






#endif