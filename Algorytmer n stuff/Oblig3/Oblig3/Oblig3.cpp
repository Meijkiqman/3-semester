#include <iostream>
#include <chrono>
#include <list>
#include <queue>
#include <string>
#include <array>
#include <unordered_map>
#include <unordered_set>

struct Edge;

struct Node
{
	char m_name;
	bool m_visited;
	std::list<Edge>
		m_edges;
	Node(char name) : m_name(name), m_visited(false) { }
	void setIn_edge(const Edge& edge);
};

struct Path
{
public:
	std::vector<Edge*> edges;
	double cost;
	bool operator > (const Path& OtherPath) const { return cost > OtherPath.cost; }

};

struct Edge
{
	float m_weight;
	Node* m_toNode;
	Edge(float weight, Node* toNode) : m_weight(weight), m_toNode(toNode) { };
	bool operator > (const Edge& e) const { return m_weight > e.m_weight; };
};

struct graph
{
	std::list<Node*> nodes;
	graph() {};
	Node* find_node(char name);
	void setIn_node(char name);
	void setIn_edge(char from_name, char to_name, float weight);
	float mst;
};

void Node::setIn_edge(const Edge& edge)
{
	for (auto& e : m_edges)
	{
		if (e.m_toNode = edge.m_toNode)
		{
			//returns if edge already exists
			return;
		}
	}
	m_edges.push_back(edge);
}

void graph::setIn_node(char name)
{
	Node* n = new Node(name);
		for (auto& node : nodes)
		{
			if (node->m_name == name)
			{
				return;
			}
		}
		nodes.push_back(n);	
}

Node* graph::find_node(char name)
{
	for (auto& node : nodes)
	{
		if (node->m_name == name)
		{
			return node;
		}
	}
	return nullptr;
}

void graph::setIn_edge(char from_name, char to_name, float weight)
{
	Node* n = find_node(from_name);

	if (!n)
	{
		setIn_node(from_name);
	}
	n = find_node(from_name);

	Node* n2 = find_node(to_name);

	if (!n2)
	{
		setIn_node(to_name);
	}
	n2 = find_node(to_name);

	Edge* e = new Edge(weight, n2);
	n->setIn_edge(*e);
}

void graphFunc()
{
	graph* g = new graph();
	g->setIn_node('a');
	g->setIn_node('b');
	g->setIn_node('c');
	g->setIn_node('d');
	g->setIn_node('e');
	g->setIn_edge('a', 'b', 1);
	g->setIn_edge('a', 'c', 2);
	g->setIn_edge('b', 'c', 2);
	g->setIn_edge('c', 'd', 3);
	g->setIn_edge('d', 'e', 1);
	g->setIn_edge('a', 'e', 5);
	g->setIn_edge('c', 'e', 4);
}

//oppg3
struct test
{
	int key;
	std::string s;
	bool operator == (const test& t2) const { return key == t2.key; }
};

template<>
class std::hash<test> 
{
	size_t operator() (const test& t) const {
		return t.key % 7;
	}
	bool operator() (const test& t1, const test& t2) {
		return t1.key == t2.key;
	}
};

void insertIntoUnorderSet(std::unordered_set<test>& set, int key, std::string s)
{
	test t;
	t.key = key;
	t.s = s;

	//set.insert(t);
}

void hashfunc()
{
	std::hash<test> hashTabell;

	std::unordered_set<test> uordnet_sett;

	insertIntoUnorderSet(uordnet_sett, 12, "twelve");
	insertIntoUnorderSet(uordnet_sett, 13, "thirteen");
	insertIntoUnorderSet(uordnet_sett, 20, "twenty");
	insertIntoUnorderSet(uordnet_sett, 21, "twenty-one");
	insertIntoUnorderSet(uordnet_sett, 1, "one");
	insertIntoUnorderSet(uordnet_sett, 2, "two");
	insertIntoUnorderSet(uordnet_sett, 3, "three");
	insertIntoUnorderSet(uordnet_sett, 4, "four");
	insertIntoUnorderSet(uordnet_sett, 5, "five");
	insertIntoUnorderSet(uordnet_sett, 6, "six");
}




template<typename T, size_t n>
void MergeSort(T(&arr)[n])
{
	 auto start = std::chrono::high_resolution_clock::now();

	 int i, j, k, lower1, lower2, size, upper1, upper2;
	 std::array<int, n> hjelp;
	 size = 1;
	 while (size < n)
	 {
		 lower1 = 0;
		 k = 0;
		 while (lower1 + size < n)
		 {
			 upper1 = lower1 + size - 1;
			 lower2 = upper1 + 1;
			 upper2 = (lower2 + size - 1 < n) ? lower2 + size - 1 : n - 1;
			 for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++)
			 {
				 if (arr[i] < arr[j]) 
				 {
					 hjelp[k] = arr[i++];
				 }
				 else 
				 {
					 hjelp[k] = arr[j++];
				 }
			 }
			 for (; i <= upper1; k++) 
			 {
				 hjelp[k] = arr[i++];
			 }
			 for (; j <= upper2; k++) 
			 {
				 hjelp[k] = arr[j++];
			 }
			 lower1 = upper2 + 1;

		 }
		 for (i = lower1; k < n; i++) 
		 {
			 hjelp[k++] = arr[i];
		 }
		 for (i = 0; i < n; i++) 
		 {
			 arr[i] = hjelp[i];
		 }

		 size = size * 2;
	 }

	 auto end = std::chrono::high_resolution_clock::now();
	 std::chrono::duration<double> totalTime = end - start;
	 std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

	 totalTime += totalTimeNano;
	 int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	 std::cout << "With " << n << " elements, it took " << totalTime.count() << " seconds to sort them doing the Mergesort." << std::endl << std::endl;

}
	 


template<typename T, size_t n>
void insertionSort(T(&arr)[n])
{
	auto start = std::chrono::high_resolution_clock::now();

	for (auto i = 1; i < sizeof(arr) / sizeof(*arr); i++)
	{
		//Gets the current
		auto hjelp = arr[i];
		//If the the prevois element is larger, move it behind
		for (auto j = i - 1; j >= 0 && arr[j] > hjelp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = hjelp;
		}
	}


	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> totalTime = end - start;
	std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);


	totalTime += totalTimeNano;
	int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "With " << n << " elements, it took " << totalTime.count() << " seconds to sort them doing insertSort." << std::endl << std::endl;



}


	



int main()
{

	int a[10];
	int b[100];
	int c[1000];
	int d[10000];
	for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
	{
		a[i] = rand() % 100;
	}
	for (int i = 0; i < sizeof(b) / sizeof(*b); i++)
	{
		b[i] = rand() % 1000;
	}
	for (int i = 0; i < sizeof(c) / sizeof(*c); i++)
	{
		c[i] = rand() % 10000;
	}
	for (int i = 0; i < sizeof(d) / sizeof(*d); i++)
	{
		d[i] = rand() % 100000;
	}

	std::cout << "oppg 1" << std::endl << std::endl;

	insertionSort(a);
	insertionSort(b);
	insertionSort(c);
	insertionSort(d);

	std::cout << "_________________________" << std::endl << std::endl;

	MergeSort(a);
	MergeSort(b);
	MergeSort(c);
	MergeSort(d);
	for (int i = 0; i < sizeof(a) / sizeof(*a); i++)
		{
			std::cout << a[i] << ", ";
		}
	std::cout << std::endl;

	std::cout << "_________________________" << std::endl << std::endl;

	std::cout << "oppg 2" << std::endl << std::endl;

	int array1[] = { 17, 14, 5, 7, 12, 1, 16, 29, 13, 4, 8, 18, 22, 2 };
	MergeSort(array1);
	for (int i = 0; i < sizeof(array1) / sizeof(*array1); i++)
	{
		std::cout << array1[i] << ", ";
	}
	std::cout << std::endl;
	

	//PrintArray(arr, n);
	hashfunc();

	//graphFunc();

	return 0;
}

/*
void Merge(int arr[], int const left, int const mid, int const right)
{
	auto const subArray1 = mid - left + 1;
	auto const subArray2 = right - right;

	//creates a temp array
	auto* leftArray = new int[subArray1], * rightArray = new int[subArray2];

	//copy data to the temp arrays
	for (auto i = 0; i < subArray1; i++)
	{
		leftArray[i] = arr[left + 1];
	}
	for (auto j = 0; j < subArray2; j++)
	{
		rightArray[j] = arr[mid + 1 + j];
	}

	auto indexOfSubArray1 = 0, indexOfSubArray2 = 0;
	int indexOfMergedArray = left;

	//merge the temp arrays into left/right arrays
	while (indexOfSubArray1 < subArray1 && indexOfSubArray2 < subArray2)
	{
		if (leftArray[indexOfSubArray1] <=  rightArray[indexOfSubArray2])
		{
			arr[indexOfMergedArray] = leftArray[indexOfSubArray1];
			indexOfSubArray1++;
		}
		else
		{
			arr[indexOfMergedArray] = rightArray[indexOfSubArray2];
			indexOfSubArray2++;
		}
		indexOfMergedArray++;
	}
	//copies the remaining elements of left[]
	while (indexOfSubArray1 < subArray1)
	{
		arr[indexOfMergedArray] = leftArray[indexOfSubArray1];
		indexOfSubArray1++;
		indexOfMergedArray++;
	}
	//does the same as last while but with the right array
	while (indexOfSubArray2 < subArray2)
	{
		arr[indexOfMergedArray] = rightArray[indexOfSubArray2];
		indexOfSubArray2++;
		indexOfMergedArray++;
	}
}

void MergeSort(int arr[], int const begin, int const end)
{
	if (begin >= end)
	{
		return; //returns recursively,
	}
	auto mid = begin + (end - begin) / 2;
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid + 1, end);
	Merge(arr, begin, mid, end);
}

void PrintArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		std::cout << arr[i] << " " << std::endl;
	}
}
*/