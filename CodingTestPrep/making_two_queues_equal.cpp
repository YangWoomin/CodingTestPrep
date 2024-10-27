
#include	"test4.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <functional>

static int solution1(std::vector<int> queue1, std::vector<int> queue2) {
    int answer = 0;

    const int size = queue1.size();

    std::vector<int> q1 = queue1, q2 = queue2;
    long long sum1 = 0;
    for (const auto& ele : queue1)
    {
        sum1 += ele;
        q2.push_back(ele);
    }

    long long sum2 = 0;
    for (const auto& ele : queue2)
    {
        sum2 += ele;
        q1.push_back(ele);
    }

    int idx1 = 0, idx2 = 0;
    while (sum1 != sum2 && size > std::abs(idx1 - idx2) && idx1 < q1.size() && idx2 < q2.size())
    {
        if (sum1 > sum2)
        {
            sum1 -= q1[idx1];
            sum2 += q1[idx1];
            idx1++;
        }
        else
        {
            sum1 += q2[idx2];
            sum2 -= q2[idx2];
            idx2++;
        }
        answer++;
    }

    return sum1 == sum2 ? answer : -1;
}

void MakingTwoQueuesEqualTest()
{
    //std::vector<int> queue1 = { 3, 2, 7, 2 };
    //std::vector<int> queue2 = { 4, 6, 5, 1 }; // 2

    //std::vector<int> queue1 = { 1, 2, 1, 2 };
    //std::vector<int> queue2 = { 1, 10, 1, 2 }; // 7

    std::vector<int> queue1 = { 1, 1 };
    std::vector<int> queue2 = { 1, 5 }; // -1

    std::cout << "====================== Making Two Queues Equal Test Start ======================" << std::endl;

    std::cout << "Queue 1 : [ " ;
    for (const auto& ele : queue1)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Queue 2 : [ ";
    for (const auto& ele : queue2)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(queue1, queue2);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Making Two Queues Equal Test End ======================" << std::endl;
}
