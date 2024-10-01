
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> arr, int n)
{
    const int size = arr.size();

    for (int i = 0; i < n % 4; ++i)
    {
        for (int j = 0; j < size/2; ++j)
        {
            for (int k = j; k < size - j - 1; ++k)
            {
                int tmp = arr[j][k];
                arr[j][k] = arr[size - 1 - k][j];
                arr[size - 1 - k][j] = arr[size - 1 - j][size - 1 - k];
                arr[size - 1 - j][size - 1 - k] = arr[k][size - 1 - j];
                arr[k][size - 1 - j] = tmp;
            }
        }
    }

    return arr;
}

void RotateMatrixTest()
{
    //std::vector<std::vector<int>> arr = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} }; 
    ////int n = 1; // [[13,9,5,1], [14,10,6,2], [15,11,7,3], [16,12,8,4]]
    //int n = 2; // [[16,15,14,13], [12,11,10,9], [8,7,6,5], [4,3,2,1]]

    std::vector<std::vector<int>> arr = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
    //int n = 1; // [21 16 11 6 1], [22 17 12 7 2], [23 18 13 8 3], [24 19 14 9 4], [25 20 15 10 5]]
    int n = 2; // [[25 24 23 22 21], [20 19 18 17 16], [15 14 13 12 11], [10 9 8 7 6], [5 4 3 2 1]]

    std::cout << "====================== Rotate Matrix Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;
    std::cout << "Arr : " << std::endl;
    for (const auto& ele : arr)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(arr, n);
    std::cout << "Result : "<< std::endl;
    for (const auto& ele : res)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====================== Rotate Matrix Test End ======================" << std::endl;
}
