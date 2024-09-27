
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

static std::vector<int> solution1(std::vector<int> arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
            else
            {
                break;
            }
        }
    }

    return arr;
}

void InsertionSortTest()
{
    //std::vector<int> arr = { 51, 11, 32, 60, 56, 9 }; // [9, 11, 32, 51, 56, 60]
    //std::vector<int> arr = { 56, 9 }; // [9, 56]
    std::vector<int> arr = { 9 }; // [9]

    std::cout << "====================== Insertion Sort Test Start ======================" << std::endl;

    std::cout << "Array : [ ";
    for (const auto& ele : arr)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(arr);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Insertion Sort Test Start ======================" << std::endl;
}
