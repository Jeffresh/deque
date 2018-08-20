#include "deque.hpp"
#include<iostream>

int main()
{

	Deque<int> D{};

	if(D.empty())
		std::cout<<"Deque empty"<<std::endl;
	else
		std::cout<<"Fail in empty"<<std::endl;

	for(int i = 5; i<10; i++)
		D.push_back(i);

	for(int i = 4; i>0; i--)
		D.push_front(i);

	for(int i = 10; i<16; i++)
		D.push_back(i);


	Deque<int> R = D;

	while(!R.empty())
	{
		std::cout<<R.front()<<"-";
		R.pop_front();
	}



	if(R.empty())
		std::cout<<"Deque R is empty"<<std::endl;
	else
		std::cout<<"Fail in pop_back and pop_front "<<std::endl;


	Deque<int> V = D;
	V = D;


	if(!V.empty())
		std::cout<<"Deque V is not empty"<<std::endl;
	else
		std::cout<<"Fail in copy or operator ="<<std::endl;



	for(int i = 0; i<5; i++)
	{
		std::cout<<V.front()<<"-";
		V.pop_front();
	}

	std::cout<<'\n';

	for(int i = 0; i<5; i++)
	{
		std::cout<<V.back()<<"-";
		V.pop_back();
	}





}