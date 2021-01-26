#include<iostream>
#include"DynamicArray.h"

int main() 
{
	DynamicArray d;

	d.push_back(1.4);
	d.push_back(2.4);
	d.push_back(3.4);
	d.push_back(4.4);
	d.push_back(5.4);
	d.push_back(6.4);
	d.push_back(7.4);
	d.push_back(8.4);

	std::cout << d.size() << std::endl;

	std::cout << d.capacity() << std::endl;

	std::cout << d.empty() << std::endl;

	std::cout << d.at(7) << std::endl;

	d.push_front(9.7);
	std::cout << d.at(0) << std::endl;

	d.pop_front();
	std::cout << d.at(0) << std::endl;

	d.pop_back();
	//std::cout << d.at(7) << std::endl;
	std::cout << d.at(6) << std::endl;
}