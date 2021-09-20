#include "CharNode.h"
#include <iostream>
#include "stack.h"


int main()
{
    Stack* stack = new Stack();

    CharNode* list = new CharNode('a', nullptr);
    list = new CharNode('b', list);
    list = new CharNode('c', list);
    list = new CharNode('d', list);

    
    //stack->Push(list);

    while (stack->Size() != 0)
    {
        std::cout << stack->Top()->getData();
        stack->Pop();
    }
       
}
