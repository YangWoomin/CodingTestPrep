
#include	"heap_test.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <sstream>
#include    <set>

static std::vector<int> solution1(std::vector<std::string> operations) {
    std::vector<int> answer;

    std::multiset<int> q;

    for (const auto& ele : operations)
    {
        std::istringstream iss(ele);
        std::string cmd;
        int num = 0;
        iss >> cmd >> num;

        if ("I" == cmd)
        {
            q.insert(num);
        }
        else if (!q.empty())
        {
            if (1 == num)
            {
                q.erase(std::prev(q.end()));
            }
            else
            {
                q.erase(q.begin());
            }
        }
    }

    if (!q.empty())
    {
        answer = { *std::prev(q.end()), *q.begin() };
    }
    else
    {
        answer = { 0, 0 };
    }

    return answer;
}

void DoublePriorityQueueTest()
{
    //std::vector<std::string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" }; // [0, 0]
    std::vector<std::string> operations = { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" }; // [333, -45]

    std::cout << "====================== Double Priority Queue Test Start ======================" << std::endl;

    std::cout << "Operations : [ ";
    for (const auto& ele : operations)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(operations);

    std::cout << "Result : " << res[0] << ", " << res[1] << std::endl;

    std::cout << "====================== Double Priority Queue Test End ======================" << std::endl;
}
