
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<int> people, int limit) {
    int answer = 0;

    std::sort(people.begin(), people.end());

    int i = 0, j = people.size() - 1;
    while (i <= j)
    {
        if (i != j && people[i] + people[j] <= limit)
        {
            i++, j--;
        }
        else
        {
            j--;
        }
        answer++;
    }

    return answer;
}

void LifeboatTest()
{
    //std::vector<int> people = { 70, 50, 80, 50 };
    //int limit = 100; // 3

    std::vector<int> people = { 70, 80, 50 };
    int limit = 100; // 3

    std::cout << "====================== Lifeboat Test Start ======================" << std::endl;

    std::cout << "People : [ ";
    for (const auto& ele : people)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(people, limit);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Lifeboat Test End ======================" << std::endl;
}
