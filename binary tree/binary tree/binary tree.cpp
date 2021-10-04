#include "BinaryNode.h"
#include <iostream>

int main(int argc, char *argv[])
{
    BinaryNode* h = new BinaryNode('d');
    BinaryNode* v = new BinaryNode('a');

    v = new BinaryNode('b', v, h);
    //peker h er ledig
    BinaryNode* bntree = new BinaryNode('g');
    h = new BinaryNode('p');
    bntree = new BinaryNode('i', bntree, h);
    bntree = new BinaryNode('f', v, bntree);

    bntree->intrav();


}

