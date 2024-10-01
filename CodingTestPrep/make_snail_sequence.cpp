
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

static std::vector<std::vector<int>> solution1(int n)
{
    std::vector<std::vector<int>> res(n, std::vector<int>(n));

    int row = 0, col = 0, num = 1;
    
    while (n * n >= num)
    {
        while (n > col && 0 == res[row][col])
        {
            res[row][col] = num++;
            col++;
        }
        col--, row++;

        while (n > row && 0 == res[row][col])
        {
            res[row][col] = num++;
            row++;
        }
        row--, col--;

        while (0 <= col && 0 == res[row][col])
        {
            res[row][col] = num++;
            col--;
        }
        col++, row--;

        while (0 <= row && 0 == res[row][col])
        {
            res[row][col] = num++;
            row--;
        }
        row++, col++;
    }

    return res;
}

void MakeSnailSequenceTest()
{
    //int n = 3;
    ///*
    //    [1, 2, 3]
    //    [8, 9, 4]
    //    [7, 6, 5]
    //*/

    int n = 4;
    /*
        [1, 2, 3, 4]
        [12, 13, 14, 5]
        [11, 16, 15, 6]
        [10, 9, 8, 7]
    */

    std::cout << "====================== Make Snail Sequence Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);
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

    std::cout << "====================== Make Snail Sequence Test End ======================" << std::endl;
}
