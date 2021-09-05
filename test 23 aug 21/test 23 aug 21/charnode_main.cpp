#include<iostream>
#include "CharNode.h"
#include<stack>
#include <memory>

int main()
{
	ADS101::CharNode* list = new ADS101::CharNode('a');
	list = new ADS101::CharNode('b', list);
	list = new ADS101::CharNode('c', list);
	list = new ADS101::CharNode('d', list);


	//smart pointers

	for (ADS101::CharNode* p = list; p != nullptr; p = p->getNext())
		std::cout << p->getData();

	std::cout << std::endl << "static_amountl: " << list -> getAmount();
	std::cout << std::endl;

	std::cout << "writeBackwards: ";
	list->writeBackwards();

	//deletes first item in list

	ADS101::CharNode* out = list;
	list = list->getNext();
	delete out;

	std::cout << std::endl << "static_amount: " << list -> getAmount() << std::endl;
	return 0;
}
