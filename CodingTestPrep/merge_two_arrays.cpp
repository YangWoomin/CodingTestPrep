
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>

static std::vector<int> solution1(std::vector<int> arr1, std::vector<int> arr2)
{
    int i = 0, j = 0;
    std::vector<int> res;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
        }
        else
        {
            res.push_back(arr2[j]);
            j++;
        }
    }

    if (i < arr1.size())
    {
        res.insert(res.end(), arr1.begin() + i, arr1.end());
    }
    else if (j < arr2.size())
    {
        res.insert(res.end(), arr2.begin() + j, arr2.end());
    }

    return res;
}

void MergeTwoArraysTest()
{
    //std::vector<int> arr1 = { 1, 3, 5 };
    //std::vector<int> arr2 = { 2, 4, 6 }; // [1, 2, 3, 4, 5, 6]

    //std::vector<int> arr1 = { 1, 2, 3 };
    //std::vector<int> arr2 = { 4, 5, 6 }; // [1, 2, 3, 4, 5, 6]

    std::vector<int> arr1 = { 9, 11, 32, 51, 56, 60 };
    std::vector<int> arr2 = { 1, 10, 11, 12, 71, 88 }; // [1, 9, 10, 11, 11, 12, 32, 51, 56, 60, 71, 88]

    std::cout << "====================== Merge Two Arrays Test Start ======================" << std::endl;

    std::cout << "Array 1 : [ ";
    for (const auto& ele : arr1)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Array 2 : [ ";
    for (const auto& ele : arr2)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(arr1, arr2);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Merge Two Arrays Test End ======================" << std::endl;
}
