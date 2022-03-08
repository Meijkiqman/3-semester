#include<chrono>
#include <iostream>
#include <iomanip>
#include<cmath>
#include <algorithm>
#include <array>

//taken form adameske github and course PDF
//global constant for arrays
const unsigned long N{ 1000 };
const unsigned long LOOPS{ 10000 };



//for arrays with large numbers
unsigned long binary_search(std::array<unsigned long, N>& a, unsigned long x)
{
    unsigned long index = -1;
    unsigned long n = static_cast<unsigned long>(a.size());
    unsigned long v{ 0 }; unsigned long h{ n - 1 };
    while (v <= h && index == -1)
    {
        auto mid = (v + h) / 2;
        if (x == a[mid])
            index = mid;
        else if (x < a[mid])
            h = mid - 1;
        else
            v = mid + 1;       
    }
    return index;
}

//implementering av selection sort
/*void selection_sort(std::array<int, 20>& a)
{
    auto n = a.size();
    for (auto i = 0; i < n-1; i++)
        for (auto j = i + 1; j < n; j++)
            if (a[i] > a[j])
                std::swap(a[i], a[j]);

}*/

void SelectionSort(int sort)
{
    int array[1];
    for (int i = 0; i < sort; i++)
    {
        array[i] = rand();
    }
    std::chrono::nanoseconds time{ 0 };

    auto start = std::chrono::high_resolution_clock::now();
    //1 selection sort
    for (auto i = 0; i < sort-1; i++)
    {
        for (auto k = i + 1; k < sort; k++)
        {
            if (array[k] > array[i])
            {
                std::swap(array[k], array[i]);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now(); //starts clock
    std::chrono::duration<double> duration = start - end;
    
    std::chrono::nanoseconds totalTimeNano = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    duration += totalTimeNano;

    std::cout << "wtih " << sort << "elements, ot took: " << duration.count() << " senconds to sort" << std::endl;
}

int main()
{
    std::array<unsigned long, N> a;
    for (unsigned long i = 0; i < N; i++) 
    {
        a.at(i) = i;
    }

    auto start = std::chrono::high_resolution_clock::now(); //starts cclock

    for (auto i = 0; i < LOOPS; i++)
    {
        unsigned long nmr = std::rand() % N;
        auto index = binary_search(a, nmr);
    }
    auto end = std::chrono::high_resolution_clock::now(); //starts clock

    std::chrono::duration<double> duration = start - end;
    std::chrono::nanoseconds duration_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

    //print
    std::cout << "n = " << N << " , times = " << LOOPS << std::endl;
    std::cout << "duration in nanoseconds: " << duration_nano.count() / LOOPS << std::endl;

    SelectionSort(1000);
    SelectionSort(100);
    SelectionSort(500);
    return 0;

}