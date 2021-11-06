#include <iostream>
#include <chrono>


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
	
void PrintArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		std::cout << arr[i] << " " << std::endl;
	}
}


int main()
{
	int arr[] = { 10, 100, 1000, 10000 };
	int n = sizeof(arr) / sizeof(arr[0]);

	auto start = std::chrono::high_resolution_clock::now();

	insertionSort(arr, n);

	auto stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> Insertvarighet = stop - start;
	std::chrono::nanoseconds Insertvarighet_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(Insertvarighet);
	Insertvarighet += Insertvarighet_nano;


	int time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
	std::cout << Insertvarighet.count() << " nanoseconds to sort the array" << std::endl;

	PrintArray(arr, n);


	return 0;
}

