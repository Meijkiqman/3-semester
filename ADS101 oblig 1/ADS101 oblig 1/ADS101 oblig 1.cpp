#include "CharNode.h"
#include <iostream>
#include "stack.h"


int main()
{

    //Stack* list = new Stack;
    CharNode* list = new CharNode('a');
    list = new CharNode('b', list);
    list = new CharNode('c', list);
    list = new CharNode('d', list);

    //list->Push(ch);

    for (CharNode* p = list; p != nullptr; p = p->getNext())
        std::cout << p->getData();

    std::cout << std::endl << "length of list: " << list->getAmount() << std::endl;




   /*while (list->Top() != nullptr)
    {
        list->Top()->print();
        list->Pop();
        std::cout << "static amount: " << list->Size()
    }*/



    
}
