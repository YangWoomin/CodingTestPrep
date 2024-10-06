
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(int k, std::vector<int> tangerine) {
    int answer = 0;

    std::unordered_map<int, int> count1;
    for (const auto& ele : tangerine)
    {
        count1[ele]++;
    }

    std::vector<int> count2;
    for (const auto& [type, count] : count1)
    {
        count2.push_back(count);
    }

    std::sort(count2.begin(), count2.end(), std::greater<int>());

    for (const auto& ele : count2)
    {
        if (0 >= k)
        {
            break;
        }
        answer++;
        k -= ele;
    }

    return answer;
}

void TangerineSelectionTest()
{
    //int k = 6;
    //std::vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 }; // 3

    //int k = 4;
    //std::vector<int> tangerine = { 1, 3, 2, 5, 4, 5, 2, 3 }; // 2

    int k = 2;
    std::vector<int> tangerine = { 1, 1, 1, 1, 2, 2, 2, 3 }; // 1

    std::cout << "====================== Tangerine Selection Test Start ======================" << std::endl;

    std::cout << "Tangerine : [ ";
    for (const auto& ele : tangerine)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(k, tangerine);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Tangerine Selection Test End ======================" << std::endl;
}
