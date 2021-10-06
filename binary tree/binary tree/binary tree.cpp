#include "BinaryNode.h"
#include <iostream>
#include "stack.h"




void InOrder(BinaryNode* root);
void postOrder(BinaryNode* root);

int main(int argc, int *argv[])
{
    BinaryNode* right = new BinaryNode(1);
    BinaryNode* left = new BinaryNode(4);

    left = new BinaryNode(2, left, right);
    //peker right er ledig
    BinaryNode* bntree = new BinaryNode(8);
    right = new BinaryNode(12);
    bntree = new BinaryNode(10, bntree, right);
    bntree = new BinaryNode(6, left, bntree);

    //bntree->intrav();
    std::cout << "inorder traversal without recursion" << std::endl;
    InOrder(bntree);

    std::cout << std::endl << "postorder traversal without recursion" << std::endl;
    
    postOrder(bntree);

}

void InOrder(BinaryNode* root)
{
    BinaryNode* curr, *prev;
    curr = root;

    while (curr != nullptr)
    {
        //finds to left most node of the current check in BinaryNode until it hits the end
        if (curr ->getLeft() != nullptr)
        {
            prev = curr->getLeft();
            //finds the right node in current left search
            while (prev->getRight() != nullptr && prev->getRight() != curr )
            {
                prev=prev->getRight();
            }
            //when it has reached the right most node in current node 
            if (prev->getRight () == nullptr)
            {
                prev->m_right = curr;
                curr = curr->getLeft();
            }
            else
            {
                prev->m_right = nullptr;
                std::cout << curr->getData() << " ";
                curr = curr->getRight();
            }
        }
        else
        {
            //does the right side
            std::cout << curr->getData() << " ";
            curr = curr->getRight();
        }
    }
}


void postOrder(BinaryNode* root)
{
    Stack<BinaryNode*> stack;
    BinaryNode* curr = root;
    BinaryNode* prev = nullptr;
    
    while (curr != nullptr || !stack.Empty())
    {
        if (curr != nullptr)
        {
            stack.Push(curr);
            curr = curr->m_left;
        }
        else
        {
            curr = stack.Top();
            if (curr->m_right == nullptr || curr->m_right == prev)
            {
                std::cout << curr->getData() << " ";
                stack.Pop();
                prev = curr;
                curr = nullptr;
            }
            else
            {
                curr = curr->m_right;
            }
        }
        
    }


    
}

