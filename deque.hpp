#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <cassert>


template<typename T>
class Deque
{

public:


	explicit Deque();
	Deque(const Deque<T>&);
	Deque& operator =(const Deque<T>&);

	bool empty();

	void push_front( const T&);
	void push_back(const T&);
	void pop_front();
	void pop_back();

	const T& front();
	const T& back();


	~Deque();


private:


	struct node
	{
		T elt;
		node* next;

		node(const T& e, node* n = 0):elt{e},next{n}{}

	};

	node *begin, *end ;

	void copy(const Deque<T>&);

};



template<typename T>
void Deque<T>::copy(const Deque<T>& D)
{
	if(D.begin)
	{
		begin == end == new node(D.begin->elt);

		for(node* p = D.begin->next; p; p = p->next)
		{
			end->next = new node(p->elt);
			end = end->next;
		}
	}

}

template<typename T>
inline Deque<T>::Deque(): 
begin{0},
end{0}
{}


template<typename T>
inline Deque<T>::Deque(const Deque<T>& D){copy(D);}

template<typename T>
inline Deque<T>& Deque<T>::operator =(const Deque<T>& D)
{
	if(this != &D)
	{
		this->~Deque();
		copy(D);
	}

	return *this;
}


template<typename T>
inline bool Deque<T>::empty()
{
	return begin == 0;
}


template<typename T>
void Deque<T>::push_front(const T& e)
{
	node* new_begin = new node(e);

	if(begin == 0)
		begin=end= new_begin;
	else
		begin = new_begin->next = begin;
}

template<typename T>
void Deque<T>::push_back(const T& e)
{
	node* new_end = new node(e);

	if(begin == 0)
		begin = end= new_end;
	else
		end = end->next= new_end;
}











#endif