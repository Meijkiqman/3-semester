
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <array>
#include <iterator>
#include <vector>
#include <string>


std::vector<long double> selection_sortTime;
std::vector<long double> sortTime;

//uses template to push multiple values into the selection sort. 
//write til file for easier conversion to geogebra

template<typename T,size_t N>
void Selection_sort(T (&a)[N], std::ofstream &write2File)
{
    for (int i = 0; i < N; i++)
    {
        a[i] = rand();
    }

    //starts timer
    auto start = std::chrono::high_resolution_clock::now();

    for (auto i = 0; i < N - 1; i++)
    { 
        for (auto j = i + 1; j < N; j++)
        {
            if (a[i] < a[j])
            {
                std::swap(a[i], a[j]);
            }     
        }
    }
    //ends clock and gets time
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> varighet = stop - start;
    std::chrono::nanoseconds varighet_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(varighet);
    varighet += varighet_nano;

    int time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "an array with: " << N << " elements, used a total time of: " << varighet.count() << " nanoseconds to sort the array with selection" << std::endl << std::endl;

    write2File << varighet.count() << std::endl << std::endl;
    selection_sortTime.push_back(varighet.count());

}

template<typename T, size_t N>
void stdSort(T(&a)[N], std::ofstream& write2File)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(std::begin(a), std::end(a));

    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> varighet = stop - start;
    std::chrono::nanoseconds varighet_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(varighet);
    varighet += varighet_nano;

    int time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    std::cout << "an array with: " << N << " elements, used a total time of: " << varighet.count() << " nanoseconds to sort the array with std::sort" << std::endl << std::endl;

    write2File << varighet.count() << std::endl << std::endl;
    sortTime.push_back(varighet.count());
    
}


int main()
{
    
    // used to write time and array size to txt file
 
    std::ofstream selection_sortFile("Selection_sort results.txt");
    std::ofstream stdsortFile("stdsort results.txt");

    int a[10];
    int b[100];
    int c[1000];
    int d[10000];
    int e[20000];

   //for loop size of 10 for mean for selection sort
    for (int i = 0; i < 10; i++)
    {
        Selection_sort(a, selection_sortFile);
        Selection_sort(b, selection_sortFile);
        Selection_sort(c, selection_sortFile);
        Selection_sort(d, selection_sortFile);
        Selection_sort(e, selection_sortFile);

    }
    //for loop size of 10 for mean for std::sort
    for (int i = 0; i < 10; i++)
    {
        stdSort(a, stdsortFile);
        stdSort(b, stdsortFile);
        stdSort(c, stdsortFile);
        stdSort(d, stdsortFile);
        stdSort(e, stdsortFile);

    }

    selection_sortFile.close();
    stdsortFile.close();

    std::cout << std::endl << "sorting finished" << std::endl;
    return 0;
}


