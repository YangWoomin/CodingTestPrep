
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<std::vector<int>> triangle) {
    int answer = 0;

    for (int i = triangle.size() - 2; 0 <= i; --i)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            triangle[i][j] += std::max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    return triangle[0][0];
}

void IntegerTriangleTest()
{
    std::vector<std::vector<int>> triangle = { {7} ,{3, 8},{8, 1, 0},{2, 7, 4, 4},{4, 5, 2, 6, 5} }; // 30

    std::cout << "====================== Integer Triangle Test Start ======================" << std::endl;

    std::cout << "Triangle : " << std::endl;
    for (const auto& ele : triangle)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(triangle);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Integer Triangle Test End ======================" << std::endl;
}
