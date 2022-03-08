
#include <iostream>
#include <iomanip>
#include <array>
#include <cmath>
#include <algorithm>


void Selection_sort(std::array<int, 20>& a)
{
    auto n = a.size();
    for (auto i = 0; i < n - 1; i++)
        for (auto j = i + 1; j < n; j++)
            if (a[i] < a[j])
                std::swap(a[i], a[j]);

}

//implimentation of Binary search for std::array
int BinarySearch(std::array<int, 20>& a, int x)
{
    int index = -1;
    int n = static_cast<int>(a.size());
    int v{ 0 };
    int h{ n - 1 };
    while (v <= h && index == -1)
    {
        auto mid = (v + h) / 2;
        if (x == a[mid])
        {
            index = mid;
        }
        else if (x < a[mid])
            h = mid - 1;
        else // x > a[mid]
            v = mid+1;
    }
    return index;
}
//example for binary search
int main()
{
    //creates a object with 20 elements
    std::array<int, 20> c;
    for (auto i = 0; i < 20; i++)
    {
        c[i] = std::rand() % 20;
    }
    //print unsorted array
    std::cout << std::endl << "unsorted array" << std::endl;
    for (auto i = 0; i < c.size(); i++)
        std::cout << c[i] << "-";
    Selection_sort(c);

    //print of sortet array
    
    std::cout << std::endl << "sorted array" << std::endl;
    for (auto i = 0; i < c.size(); i++)
        std::cout << c[i] << "-";
    std::cout << std::endl;

    //test 

    for (;;)
    {
        std::cout << " search for:..";
        int number;
        std::cin >> number;
        int index = BinarySearch(c, number);
        std::cout << index << std::endl;
        if (index ==-1)
        {
            break;
        }   
    }
    return 0;
}
