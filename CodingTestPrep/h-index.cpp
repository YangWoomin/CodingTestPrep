
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static int solution1(std::vector<int> citations) {
    int answer = 0;

    for (const auto& ele : citations)
    {
        int count = 0;
        for (const auto& ele2 : citations)
        {
            if (ele <= ele2)
            {
                count++;
            }
        }
        int refs = std::min(ele, count);
        if (answer < refs)
        {
            answer = refs;
        }
    }

    return answer;
}

static int solution2(std::vector<int> citations) {

    std::sort(citations.begin(), citations.end(), std::greater<int>());
    for (int i = 0; i < citations.size(); ++i)
    {
        if (citations[i] < i + 1)
        {
            return i;
        }
    }

    return citations.size();
}

void HIndexTest()
{
    std::vector<int> citations = { 3, 0, 6, 1, 5 }; // 3
    //std::vector<int> citations = { 10, 8, 5, 4, 3 }; // 4
    //std::vector<int> citations = { 9, 7, 6, 2, 1 }; // 3
    //std::vector<int> citations = { 5, 5, 5, 5, 5 }; // 5

    std::cout << "====================== H-Index Test Start ======================" << std::endl;

    std::cout << "Citations : [ ";
    for (const auto& ele : citations)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(citations);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== H-Index Test End ======================" << std::endl;
}
