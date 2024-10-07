
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(int n, std::vector<int> lost, std::vector<int> reserve) {
    int answer = 0;

    std::vector<int> students(n + 1, 1);
    students[0] = 0;

    for (const auto& ele : reserve)
    {
        students[ele]++;
    }

    for (const auto& ele : lost)
    {
        students[ele]--;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (0 < students[i])
        {
            answer++;
        }
        else
        {
            if (1 < students[i - 1])
            {
                answer++;
            }
            else if (i + 1 <= n && 1 < students[i + 1])
            {
                students[i + 1]--;
                answer++;
            }
        }
    }

    return answer;
}

void GymSuitTest()
{
    //int n = 5;
    //std::vector<int> lost = { 2, 4 };
    //std::vector<int> reserve = { 1, 3, 5 }; // 5

    //int n = 5;
    //std::vector<int> lost = { 2, 4 };
    //std::vector<int> reserve = { 3 }; // 4

    int n = 3;
    std::vector<int> lost = { 3 };
    std::vector<int> reserve = { 1 }; // 2

    std::cout << "====================== Gym Suit Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;
    std::cout << "Lost : [ ";
    for (const auto& ele : lost)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Reserve : [ ";
    for (const auto& ele : reserve)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, lost, reserve);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Gym Suit Test End ======================" << std::endl;
}
