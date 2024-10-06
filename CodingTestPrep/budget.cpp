
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<int> d, int budget) {
    int answer = 0;

    std::sort(d.begin(), d.end());

    for (const auto& ele : d)
    {
        if (budget < ele)
        {
            break;
        }

        answer++;
        budget -= ele;
    }

    return answer;
}

void BudgetTest()
{
    //std::vector<int> d = { 1,3,2,5,4 };
    //int budget = 9; // 3

    std::vector<int> d = { 2,2,3,3 };
    int budget = 10; // 4

    std::cout << "====================== Budget Test Start ======================" << std::endl;

    std::cout << "Departments : [ ";
    for (const auto& ele : d)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(d, budget);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Budget Test End ======================" << std::endl;
}
