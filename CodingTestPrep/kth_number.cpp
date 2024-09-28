
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

static std::vector<int> solution1(std::vector<int> array, std::vector<std::vector<int>> commands) {
    std::vector<int> answer;

    std::vector<int> origin = array;
    for (const auto& ele : commands)
    {
        array = origin;
        int i = ele[0] - 1, j = ele[1], k = ele[2] - 1;
        std::sort(array.begin() + i, array.begin() + j);
        answer.push_back(array[i + k]);
    }

    return answer;
}

void KthNumberTest()
{
    std::vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    std::vector<std::vector<int>> commands = { {2, 5, 3} ,{4, 4, 1},{1, 7, 3} }; // [5, 6, 3]

    std::cout << "====================== Kth Number Test Start ======================" << std::endl;

    std::cout << "Array : [ ";
    for (const auto& ele : array)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Commands : [ ";
    for (const auto& ele : commands)
    {
        std::cout << "[ i : " << ele[0] << ", j : " << ele[1] << ", k : " << ele[2] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(array, commands);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Kth Number Test End ======================" << std::endl;
}
