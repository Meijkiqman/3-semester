#include "BinaryNode.h"
#include <iostream>
#include "stack.h"




void InOrder(BinaryNode* root);
void postOrder(BinaryNode* root);
int NumberofNodes(BinaryNode* root);
int NumberofLevels(BinaryNode* root);
bool Balance(BinaryNode* root);


//test funksjon
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

    std::cout << std::endl << "amount of nodes in BNtree: " <<  NumberofNodes(bntree) << std::endl;

    std::cout << std::endl << "amount of nodes in BNtree: " << NumberofLevels(bntree) << std::endl;

   
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
//returns the amount of nodes in a tree.
int NumberofNodes(BinaryNode* root)
{
    Stack<BinaryNode*> stack;
    stack.Push(root);

    int nodes = 0;

    while (!stack.Empty())
    {
        BinaryNode* curr = stack.Top();
        stack.Pop();

        nodes++;

        if (curr->getLeft())
        {
            stack.Push(curr->getLeft());
        }
        if (curr->getRight())
        {
            stack.Push(curr->getRight());
        }

    }
    return nodes;
}

int NumberofLevels(BinaryNode* root)
{
    Stack<BinaryNode*> stack;
    stack.Push(root);

    int levels = 0;
    
    while (!stack.Empty())
    {
        BinaryNode* curr = stack.Top();
        stack.Pop();
        bool visited = false;

        //only add to levels if it hasnt visted the level:
        if (curr->getLeft())
        {
            stack.Push(curr->getLeft());
            levels++;
            visited = true;
        }
        if (curr->getRight())
        {
            stack.Push(curr->getRight());
            if(visited == false)
            levels++;
            visited = true;
        }
    }
    return levels;
}


bool Balance(BinaryNode* root)
{
    if (root == false)
    {
        return true;
    }

    //check how many levels there are, both left and right
    int leftHeight = Height(root->getLeft());
    int rightHeight = Height(root->getRight());

    //if the tree is not balanced then return false
    if ((leftHeight - rightHeight) <= 0 && Balance(root->getLeft()) && Balance(root->getRight()))
    {
        return true;
    }
    else
    {
        return false;
    }

}

//height function to put into balance function.
int Height(BinaryNode* root)
{
    if (root == false)
    {
        return 0;
    }
    else
    {
        int L = Height(root->getLeft());
        int R = Height(root->getRight());

        //returns the highest 
        if (L > R)
        {
            return 1 + L;
        }
        else
        {
            return 1 + R;
        }
    }
}
