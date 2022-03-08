#include "CharNode.h"
#include <iostream>
#include "TStack.h"

int main()
{
    TStack<CharNode>* stack = new TStack<CharNode>();
    CharNode* list = new CharNode('a', nullptr);
    list = new CharNode('b', list);
    list = new CharNode('c', list);
    list = new CharNode('d', list);


    stack->Push(list);

    while (stack->Size() != 0)
    {
        std::cout << stack->Top()->getData();
        stack->Pop();

    }

    
}
