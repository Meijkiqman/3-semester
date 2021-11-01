
#include <iostream>


void insertionSort(int arr[], int n)
{
    int i, k, j;
	for (i = 1; i < n; i++)
	{
		k = arr[i];
		j = i - 1;
	

		//moves current element that are larger than k ahead of k.
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
}

int main()
{
    std::cout << "Hello World!\n";
}

