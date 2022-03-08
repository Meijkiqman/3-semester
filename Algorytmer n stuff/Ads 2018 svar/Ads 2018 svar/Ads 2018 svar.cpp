#include <iostream>
#include <chrono>
#include <array>
#include <string>




struct Vector3d {
	double x, y, z;
	Vector3d operator + (const Vector3d& v2) {
		return Vector3d{ x + v2.x,y + v2.y,z + v2.z };
	}
};
struct Binary_tree {
	std::string name;
	Vector3d position;
	Binary_tree* left;
	Binary_tree* right;

	void skriv(const Vector3d& pos);
	static Binary_tree* test_scene();

};

Binary_tree* Binary_tree::test_scene()
{
	Binary_tree* star = new Binary_tree{ "star", Vector3d{0.5, 0.5, 0.5}, nullptr, nullptr };
	Binary_tree* window = new Binary_tree{ "window", Vector3d{2.0, 0.0, 1.0}, star, nullptr };
	Binary_tree* toilets = new Binary_tree{ "toilets", Vector3d{1.0, 0.0, 0.0}, nullptr, window };
	Binary_tree* house = new Binary_tree{ "house", Vector3d{2.0, 2.0, 0.0}, toilets, nullptr };
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

template<typename T, size_t n>
void MergeSort(T(&arr)[n])
{
	//starts timer for timing
	auto start = std::chrono::high_resolution_clock::now();

	//initializes ints to sort
	int i, j, k, lower1, lower2, size, upper1, upper2;
	//creates an array where where the ints are put in transition for mergesort
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

	//ends timer
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> totalTime = end - start;
	std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(totalTime);

	totalTime += totalTimeNano;
	int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	std::cout << "With " << n << " elements, it took " << totalTime.count() << " seconds to sort them doing the Mergesort." << std::endl << std::endl;

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

}
