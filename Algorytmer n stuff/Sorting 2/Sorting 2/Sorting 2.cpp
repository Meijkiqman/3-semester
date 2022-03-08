#include <iomanip>
#include <iostream>
#include<cmath>
#include<array>
#include<algorithm>
#include<chrono> //for timing

//

const unsigned long N{ 1000 };
const unsigned long LOOPS{ 10000 };

std::array<int, 10>tens{ 0 };
std::array<int, 100>hundos{ 0 };
std::array<int, 1000>thosos{ 0 };
std::array<int, 10000>tenthos{ 0 };
std::array<int, 100000>hundthos{ 0 };



unsigned long binarySearch(std::array<unsigned long, N>& a, unsigned long x)
{
    unsigned long index = -1;
    unsigned long n = static_cast<unsigned long>(a.size());
    unsigned long v{ 0 };
    unsigned long h{ n - 1 };
    while (v<=h && index ==-1)
    {
        auto mid = (v + h) / 2;
        if (x == a[mid])
        {
            index = mid;
        }
        else if (x < a[mid])
            h = mid - 1;
        else
            v = mid + 1;
    }
    return index;
}
int main()
{
    std::array<unsigned long, N>a;
    for (unsigned long i = 0; i < N; i++) 
        
        a.at(i) = i;
        auto start = std::chrono::high_resolution_clock::now(); // starts clock
    
    for (auto i = 0; i < LOOPS; i++)
    {
        unsigned long number = std::rand() % N;
        auto index = binarySearch(a, number);
    }
    auto stop = std::chrono::high_resolution_clock::now(); // stops the clock

    std::chrono::duration<double> varighet = stop - start;
    std::chrono::nanoseconds varighet_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(varighet);

    //print
    std::cout << "n_" << N << ", repetitions= " << LOOPS << std::endl;
    std::cout << "duration in nanoseconds: " << varighet_nano.count() / LOOPS << std::endl;
}
