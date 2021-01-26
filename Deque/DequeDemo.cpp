#include<iostream>
#include"Deque.h"

int main() 
{
	Deque d;

	d.push_front(1);
	d.push_front(2);
	d.push_front(3);
	d.push_front(4);

	d.push_back(21);

	std::cout << "Before pop operartion." << std::endl;

	std::cout << "Element at 0 position is: " << d.at(0) << std::endl;
	std::cout << "Element at 4 position is: " << d.at(4) << std::endl;

	std::cout << "First element: " << d.front() << std::endl;
	std::cout << "Last element: " << d.back() << std::endl;

	std::cout << "Size: " << d.size() << std::endl;

	d.pop_front();
	d.pop_back();

	std::cout << "After pop operartion." << std::endl;

	std::cout << "First element: " << d.front() << std::endl;
	std::cout << "Last element: " << d.back() << std::endl;

	std::cout << "Size: " << d.size() << std::endl;
}