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

	bool vacia();

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















#endif