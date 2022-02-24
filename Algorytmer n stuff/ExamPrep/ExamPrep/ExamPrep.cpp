#include <iostream>
#include "charnode.h"
#include <stack>
#include <array>
#include <chrono>
#include <queue>
#include <memory>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include "TStack.h"
#include "TQueue.h"
#include "BinaryNode.h"
#include "QuadTree.h"
#include "Hash.h"
#include "Graph.h"


void Task191to194();

template<typename T, size_t N>
void SelectionSort(T(&arr)[N]);

template<typename T, size_t N>
int binarySearch(T(&arr)[N], T x);
void Inorder(BinaryNode* root);
void postOrder(BinaryNode* root);
int AmountOfNodes(BinaryNode* root);
int AmountOfNodes(BinaryNode* root);
int AmountOfLevels(BinaryNode* root);
bool balanceCheck(BinaryNode* root);
int height(BinaryNode* root);


template<typename T, size_t N>
void StdSort(T(&arr)[N]);
template<typename T, size_t N>
void BubbleSort(T(&arr)[N]);
template<typename T, size_t N>
void UtvalgSort(T(&arr)[N]);
template<typename T, size_t N>
void insertionSort(T(&arr)[N]);
template<typename T, size_t N>
void MergeSort(T(&arr)[N]);
template<typename T, size_t N>
void HeapSort(T(&arr)[N]);
template<typename T, size_t N>
void Heapify(T(&arr)[N], int i);
template<typename T, size_t N>
void quickSort(T(&arr)[N], int low, int high);
template<typename T, size_t N>
void quickSortRecursive(T(&arr)[N], int low, int high);
template<typename T, size_t N>
int Partition(T(&arr)[N], int low, int high);
template<typename T, size_t N>
int BuildMaxHeap(T(&arr)[N]);

void subdivide(int amount);



void insertItem(int key);
void deleteItem(int key);
int hashFunction(int x);
void displayHash();

void testHash();
void TestUnorderedset();
void TestUnorderedMultiset();




int main()
{
    //declaration for sorting array
    int a[10];

    int sizeofa = sizeof(a) / sizeof(a[0]);

    //linked list, uses CharNode.h And CharNode.cpp
    CharNode* list = new CharNode('a', nullptr);
    list = new CharNode('b', list);
    list = new CharNode('c', list);
    delete list;
    //stack using template(see TStack.h)
    TStack<int>* ts = new TStack<int>();

    delete ts;

    
  
    Task191to194();

    //selection sort
    SelectionSort(a);

    //BinarySearch
    binarySearch(a, 10);

    //Syntax for using chrono requires chrono include
    auto start = std::chrono::high_resolution_clock::now();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> totalTime = end - start;
    std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

    totalTime += totalTimeNano;
    int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    //Binary Tree

    std::cout << " Binary Tree: " << std::endl << std::endl;

    BinaryNode* left = new BinaryNode(1);
    BinaryNode* right = new BinaryNode(4);

    right = new BinaryNode(2, left, right);

    BinaryNode* binarytree = new BinaryNode(8);

    left = new BinaryNode(16);
    
    binarytree = new BinaryNode(10, binarytree, left);
    binarytree = new BinaryNode(7, right, binarytree);

    //binarytree->intrav();
    //create a non recursive inorder travsersel of a binarytree
    Inorder(binarytree);
    std::cout << std::endl;

    //Create a non recursive postorder traversal of a binary tree
    postOrder(binarytree);
    std::cout << std::endl;
   // std::cout << "Non recrusive Preorder Traversal of binary tree: " << std::endl;
   //binarytree->NonRecursivePreorderTraversal();
    std::cout << std::endl;
    //Write a function that returns amount of nodes in a binary tree
    std::cout << std::endl << "Number of nodes: " << AmountOfNodes(binarytree) << std::endl;
    //Write a function that returns amount of levels in a binary tree
    std::cout << std::endl << "Number of levels: " << AmountOfLevels(binarytree) << std::endl;
    //Write a function that fins if a binary tree is balanced 
    std::cout << std::endl << "The binary tree is " << balanceCheck(binarytree) << " balanced" << std::endl << std::endl;
    //Sum av binært tre
    binarytree->sum();
    //Print stigende 
    binarytree->stigende();
    //Print avtakende
    binarytree->avtakende();


    //quadtree
    std::cout << std::endl << "Quadtree" << std::endl << std::endl;
    //write a quadtree where the blades lay in different levels
    Vector2D ne{ 100, 100 };
    Vector2D nw{ 0, 100 };
    Vector2D se{ 100, 0 };
    Vector2D sw{ 0, -0 };
    QuadTree* qtree = new QuadTree(ne, nw, se, sw);
    qtree->subdivide(1);
    Vector2D va;
    for (int i = 0; i < 18; i++)
    {
        va.x = rand() % 100;
        va.y = rand() % 100;
        qtree->insert(va);
    }
    //qtree->Print();
    //returns all corner, leafes
    std::cout << "find all leafs: " << std::endl << std::endl;
    qtree->findAllLeafs();
    std::cout << std::endl << std::endl;
    //Oppgaver 5.7.1-4

    //heap
    

    //stl priority queue
    std::cout << "max heap(descending)= default " << std::endl;
    std::priority_queue<double> max_heap;
    //pushes random chosen numbers(numbers from the exam)
    max_heap.push(3.14);
    max_heap.push(9.81);
    max_heap.push(2.71828);
    auto rot = max_heap.top();
    std::cout << " Før pop : heap rot = heap top = " << rot << std::endl;
    max_heap.pop();
    rot = max_heap.top();
    std::cout << " Etter pop : heap rot = heap top = " << rot << std::endl;
    std::cout << "min heap(ascending) " << std::endl;
    std::priority_queue<double, std::vector<double>, std::greater<double>> min_heap;
    min_heap.push(3.14);
    min_heap.push(9.81);
    min_heap.push(2.71828);
    auto min_rot = min_heap.top();
    std::cout << " Før pop : heap r o t = heap top = " << min_rot << std::endl;
    min_heap.pop();
    min_rot = min_heap.top();
    std::cout << " Etter pop : heap rot = heap top = " << min_rot << std::endl;
    std::cout << " Etter pop : heap size = " << min_heap.size() << std::endl;
    std::cout << " Etter pop : heap empty ? " << std::boolalpha << min_heap.empty() << std::endl;

    std::cout << "displaying HashTable..." << std::endl;

    Hash h(7);

    for (int i = 0; i < sizeofa; i++)
    {
        h.insertItem(a[i]);
    }
    h.deleteItem(1);
    h.displayHash();
    std::cout << "ended hashing" << std::endl;

    //sorting 0(n) notasjon, hvordan måle effektiivtet
    std::cout << "started sorting" << std::endl;
    //BobbleSort, utvalgsort, BinaryTree sorting, insertion sort:
    BubbleSort(a);
    
    UtvalgSort(a);

    insertionSort(a);

    //mergesort
    MergeSort(a);

    //quicksort
    quickSort(a, 0, sizeofa -1);
    std::cout << "ended sorting" << std::endl;

    //Hashing

    std::hash<Test> hashtabbel;
    std::unordered_set<Test> us;
    Test t;
    t.key = 12;
    t.s = "tolv";
    us.insert(t);
    t.key = 13;
    t.s = "tretten";
    us.insert(t);
    t.key = 20;
    t.s = "tjuesju";
    us.insert(t);
    t.key = 21;
    t.s = "tjueen";
    us.insert(t);
    for (int i = 1; i < 7; i++) {
        t.key = i;
        t.s = "blabla";
        us.insert(t);
    }

    Hash* hash = new Hash();
    std::cout << std::endl << "tester hash for int" << std::endl;
    hash->testHash();
    std::cout << " Test unordered set: " << std::endl;
    hash->TestUnorderedset();
    std::cout << "test undordered multiset";
    hash->TestUnorderedMultiset();

   //graphing
  Graph* g = new Graph();
  g->insertNode('A');
  g->insertNode('B');
  g->insertNode('C');
  g->insertNode('D');
  g->insertNode('E');
  g->insertNode('F');
  g->insertNode('G');
  g->insertEdge('A', 'B', 2);
  g->insertEdge('A', 'C', 17);
  g->insertEdge('C', 'B', 2);
  g->insertEdge('B', 'E', 3);
  g->insertEdge('B', 'F', 7);
  g->insertEdge('E', 'C', 4);
  g->insertEdge('E', 'F', 3);
  g->insertEdge('F', 'C', 2);
  g->insertEdge('C', 'G', 5);
  g->insertEdge('F', 'G', 3);
  g->insertEdge('G', 'D', 2);
  g->insertEdge('D', 'G', 4);
  g->insertEdge('D', 'C', 2);

  //Mst
  std::cout << "Graphs minimum spanning tree: " << g->minSpanningTree() << std::endl;
    
}

//task 1.9.1 to 1.9.4
void Task191to194()
{
    //oppg 1.9.1 Implementer en char stakk ved å bruke CharNode klassen og lenket liste. Lag
    //et testeksempel.
    std::cout << "oppg 1.9.1" << std::endl;

    TStack<CharNode>* stack = new TStack<CharNode>();
    CharNode* c = new CharNode('a', nullptr);
    c = new CharNode('b', c);
    c = new CharNode('c', c);
    c = new CharNode('d', c);
    c = new CharNode('e', c);

    stack->Push(*c);
    //prints the top of the stack and pops it until the stack is empty.
    while (stack->Size() != 0)
    {
        stack->Top().Print();
        stack->Pop();
        std::cout << "Stack size after pop: " << stack->Size() << std::endl;
    }
    //oppg 1.9.2
    std::cout << "oppgave 1.9.2" << std::endl;
    TStack<CharNode>* tstack = new TStack<CharNode>();
    CharNode* tc = new CharNode('a', nullptr);
    tc = new CharNode('b', tc);
    tc = new CharNode('c', tc);
    tc = new CharNode('d', tc);
    tc = new CharNode('e', tc);
    
    tstack-> Push(*tc);

    while (tstack->Size() != 0)
    {
        tstack->Top().Print();
        tstack->Pop();
        std::cout << "stack size after pop: " << stack->Size() << std::endl;
    }
    delete tstack;

    //oppg 1.9.3
    std::cout << "oppg 1.9.3" << std::endl;
    TQueue<char>* tq = new TQueue<char>();
    tq->Push('b');
    tq->Push('c');
    tq->Push('d');
    tq->Push('a');

    std::cout << "the front of the queue is " << tq->Front() << std::endl << "back of the queue is: " << tq->Back() << std::endl;
    //print each front of queue then pops it
    while (tq->Size() != 0)
    {
        std::cout << tq->Front() << std::endl;
        tq->Pop();
    }
    std::cout << std::endl;

}

template <class T, size_t N>
void SelectionSort(T(&arr)[N])
{
    //selection sort algo
    for (auto i = 0; i < N; i++)
    {
        for (auto j = i + 1; j < N; j++)
        {
            if (arr[j] > arr[i])
            {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

template<typename T, size_t N>
int binarySearch(T(&arr)[N], T x)
{
    int index = -1;
    int n = N;
    int v{ 0 };
    int h{ N - 1 };
    while (v <= h && index == -1)
    {
        auto mid = (v + h) / 2;
            if (x == arr[mid])
            {
                index = mid;
            }
            else if (x < arr[mid])
            {
                h = mid - 1;
            }
            else//x > a [mid]
            {
                v = mid + 1;
            }
    }
    return index;
}

//inorder tree trevarsal
void Inorder(BinaryNode* root)
{
    BinaryNode* current, * previous;
    current = root;

    while (current != nullptr)
    {
        //goes down left, until there so more nodes to the left, then goes right until there are more nodes.
        if (current->getLeft() != nullptr)
        {
            previous = current->getLeft();
            //gets the bottom right and stores it in previous
            while (previous->getRight() != nullptr && previous->getRight() != current)
            {
                previous = previous->getRight();
            }
            //here it has gotten to the bottom right, without a left
            //Stores this in previous
            if (previous->getRight() == nullptr)
            {
                //stores current as previous->right
                previous->right = current;
                //then go down the left until the end of tree
                current = current->getLeft();
            }
            else 
            {
                //if the previous has to node to the right, then print it
                std::cout << current->getData() << " ";
                previous->right = nullptr;
                //gets the new current to check as this ones right
                current = current->getRight();
                //then returns to check if it has a left, then it prints it
            }
        }
        else
        {
            //gets the right instead of the left

            std::cout << current->getData() << " ";
            current = current->getRight();
        }
    }
}

void postOrder(BinaryNode* root)
{
    TStack<BinaryNode*> Bstack;
    Bstack.Push(root);

    while (!Bstack.Empty())
    {
        BinaryNode* current = Bstack.Top();
        Bstack.Pop();

        std::cout << current->getData() << " ";

        if (current->getLeft())
        {
            Bstack.Push(current->getLeft());
        }

        if (current->getRight())
        {
            Bstack.Push(current->getRight());
        }
    }
}

int AmountOfNodes(BinaryNode* root)
{
    TStack<BinaryNode*> Bstack;
    Bstack.Push(root);

    int count = 0;

    while (!Bstack.Empty())
    {
        BinaryNode* current = Bstack.Top();
        Bstack.Pop();
        count++;


        if (current->getLeft())
        {
            Bstack.Push(current->getLeft());
        }

        if (current->getRight())
        {
            Bstack.Push(current->getRight());
        }
    }

    return count;
}


int AmountOfLevels(BinaryNode* root)
{
    TStack<BinaryNode*> Bstack;
    Bstack.Push(root);

    int count = 0;

    while (!Bstack.Empty())
    {
        BinaryNode* current = Bstack.Top();
        Bstack.Pop();
        bool hasCounted = false;

        //only add count of it hasnt done it allready
        if (current->getLeft())
        {
            Bstack.Push(current->getLeft());
            count++;
            hasCounted = true;
        }

        if (current->getRight())
        {
            Bstack.Push(current->getRight());
            if (!hasCounted)
            {
                count++;
                hasCounted = true;
            }
        }
    }
    return count;
}

int height(BinaryNode* root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        //goes down the tree
        int a = height(root->getLeft());
        int b = height(root->getRight());

        //returns the highest of the two
        if (a > b)
        {
            return 1 + a;
        }
        else
        {
            return 1 + b;
        }
    }
}

bool balanceCheck(BinaryNode* root)
{
    //returns true if this is null
    if (!root)
    {
        return true;
    }
    //find how many levels there is down from here, both left and right.
    int leftHeight = height(root->getLeft());
    int rightHeight = height(root->getRight());
    //the heights must be either 0, then check this for every level of tree
    //if any level is not balanced the whole loop returns false
    if ((leftHeight - rightHeight) <= 0 && balanceCheck(root->getLeft()) && balanceCheck(root->getRight()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T, size_t N>
void stdSort(T(&arr)[N])
{
    std::sort(std::begin(arr), std::end(arr));
}

template<typename T, size_t N>
void BubbleSort(T(&arr)[N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        //last i elemnta are already in place
        for ( j = 0; j < N - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T, size_t N>
void UtvalgSort(T(&arr)[N])
{
    for (auto i = 0; i < N; i++)
    {
        for (auto j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
            {
                auto hjelp = arr[i];
                arr[i] = arr[j];
                arr[j] = hjelp;
            }
        }
    }
}

template<typename T, size_t N>
void insertionSort(T(&arr)[N])
{
    for (auto i = 1; i < sizeof(arr) / sizeof(*arr); i++)
    {
        //gets current
        auto hjelp = arr[i];
        //if the previous element is larger, move it behind
        for (auto j = i- 1; j >= 0 && arr[j] > hjelp; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = hjelp;
        }
    }
}

template<typename T, size_t N>
void MergeSort(T(&arr)[N])
{
    int i, j, k, lower1, lower2, size, upper1, upper2;
    std::array<int, N> hjelp;
    size = 1;
    while (size < N) {
        lower1 = 0;
        k = 0;
        while (lower1 + size < N) {
            upper1 = lower1 + size - 1;
            lower2 = upper1 + 1;
            upper2 = (lower2 + size - 1 < N) ? lower2 + size - 1 : N - 1;
            for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++)
            {
                if (arr[i] < arr[j]) {
                    hjelp[k] = arr[i++];
                }
                else {
                    hjelp[k] = arr[j++];
                }
            }
            for (; i <= upper1; k++) {
                hjelp[k] = arr[i++];
            }
            for (; j <= upper2; k++) {
                hjelp[k] = arr[j++];
            }
            lower1 = upper2 + 1;

        }
        for (i = lower1; k < N; i++) {
            hjelp[k++] = arr[i];
        }
        for (i = 0; i < N; i++) {
            arr[i] = hjelp[i];
        }
        size = size * 2;
    }
}

template<typename T, size_t N>
void Heapify(T(&arr)[N], int i)
{
    int largest = i; //initlaize the largest root
    int l = 2 * i + 1; //left = 2*i +1
    int r = 2 * i + 2; //right = 2*i + 2

    //if left child is larger than root
    if (i < N && arr[l] > arr[largest])
    {
        largest = l;
    }

    //if right child is larger than largest so far
    if (r < N && arr[l] > arr[largest])
    {
        largest = r;
    }

    //if largest is not root
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        //recursify heapify the affected sub-tree
        Heapify(arr, largest);
    }

  

    
}

template<typename T, size_t N>
void HeapSort(T(&arr)[N])
{
    //build heap(rearange array)
    for (int i = N / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i);
    }

    //one by one extract an element from heap
    for (int i = N - 1; i > 0; i--)
    {
        //move current root to end
        std::swap(arr[0], arr[i]);

        //call max heapify on the reduced heap
        Heapify(arr, 0);
    }
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */

template<typename T, size_t N>
void quickSort(T(&arr)[N], int low, int high)
{
    if (low < high)
    {
        //pi is partitioning index, arr[p] is now at right place
        int pi = Partition(arr, low, high);

        //separarely sort elemnts before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template<typename T, size_t N>
int quickSortRecursive(T(&arr)[N], int low, int high)
{
    if (low < high) // left+10 <= right i boka
    {
        int pivot = arr[(low + high) / 2]; //enklere pivoteringvalg
        int i = low, j = high;
        for (;;)
        {
            while (arr[i] < pivot)
            {
                i++; // funnet 1. fra venstre >= pivot
            }
            while (pivot < arr[j])
            {
                j--;
            }
            if (i < j)
            {
                std::swap(arr[i], arr[j]); // på riktig side av pivot
            }
            else
            {
                break;
            }
            
        }
          quickSortRecursive(arr, low, i - 1);
          quickSortRecursive(arr, i + 1, high);
    }
}

template<typename T, size_t N>
int Partition(T(&arr)[N], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);//index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            //if current element is smaller than or queal to pivot
            if (arr[j] <= pivot)
            {
                i++; // incriment index of smaller element
                std::swap(arr[i], arr[j]);
            }
        }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
//oppgave i tidligere eksamen
template<typename T, size_t N>
int buildMaxHeap(T(&arr)[N])
{
    double a[]{ 2.71828, 1.732, 1.414, 3.1416, 9.81 };
    std::priority_queue<double> pq;
    for (int i = 0; i < 5; i++)
    {
        pq.push(a[i]);
    }
    pq.pop();
    std::cout << pq.top();
    return 0;
}