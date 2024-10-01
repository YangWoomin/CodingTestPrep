
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> mtx1, std::vector<std::vector<int>> mtx2)
{
    const int rowMax = mtx1.size(), colMax = mtx2.size();
    std::vector<std::vector<int>> res(rowMax, std::vector<int>(colMax, 0));

    for (int i = 0; i < rowMax; ++i)
    {
        for (int j = 0; j < colMax; ++j)
        {
            for (int k = 0; k < rowMax; ++k)
            {
                res[i][j] += mtx1[i][k] * mtx2[k][j];
            }
        }
    }

    for (int i = 0; i < rowMax; ++i)
    {
        for (int j = i; j < colMax; ++j)
        {
            if (i == j)
            {
                continue;
            }

            std::swap(res[i][j], res[j][i]);
        }
    }

    return res;
}

void MultiplyMatrixAndMakeTransposedTest()
{
    //std::vector<std::vector<int>> mtx1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    //std::vector<std::vector<int>> mtx2 = { {9,8,7}, {6,5,4}, {3,2,1} };
    ///*
    //    [30, 84, 138]
    //    [24, 69, 114]
    //    [18, 54, 90]
    //*/

    std::vector<std::vector<int>> mtx1 = { {2,4,6}, {1,3,5}, {7,8,9} };
    std::vector<std::vector<int>> mtx2 = { {9,1,2}, {4,5,6}, {7,3,8} };
    /*
        [76, 56, 158]
        [40, 31, 74]
        [76, 60, 134]
    */

    std::cout << "====================== Multiply Matrix And Make Transposed Test Start ======================" << std::endl;

    std::cout << "Matrix 1 : " << std::endl;
    for (const auto& ele : mtx1)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Matrix 2 : " << std::endl;
    for (const auto& ele : mtx2)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(mtx1, mtx2);
    std::cout << "Result : " << std::endl;
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

    std::cout << "====================== Multiply Matrix And Make Transposed Test End ======================" << std::endl;
}
