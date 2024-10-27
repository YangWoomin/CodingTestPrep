
#include	"test1.h"

#include	<iostream>
#include	<vector>
#include	<stack>

static long long solution1(int cap, int n, std::vector<int> deliveries, std::vector<int> pickups) {
    long long answer = 0;

    int i = -1, j = -1;

    for (int k = n - 1; k >= 0; --k)
    {
        if (deliveries[k])
        {
            i = k;
            break;
        }
    }

    for (int k = n - 1; k >= 0; --k)
    {
        if (pickups[k])
        {
            j = k;
            break;
        }
    }

    while (0 <= i || 0 <= j)
    {
        int max = std::max(i, j);
        answer += (max + 1) * 2;

        int count = 0;
        while (0 <= i && count + deliveries[i] <= cap)
        {
            count += deliveries[i];
            i--;
        }
        if (0 <= i)
        {
            int rest = cap - count;
            deliveries[i] -= rest;
        }

        count = 0;
        while (0 <= j && count + pickups[j] <= cap)
        {
            count += pickups[j];
            j--;
        }
        if (0 <= j)
        {
            int rest = cap - count;
            pickups[j] -= rest;
        }
    }

    return answer;
}

void DeliverAndRecallParcelTest()
{
    //int cap = 4, n = 5;
    //std::vector<int> deliveries = { 1, 0, 3, 1, 2 };
    //std::vector<int> pickups = { 0, 3, 0, 4, 0 }; // 16

    int cap = 2, n = 7;
    std::vector<int> deliveries = { 1, 0, 2, 0, 1, 0, 2 };
    std::vector<int> pickups = { 0, 2, 0, 1, 0, 2, 0 }; // 30

    std::cout << "====================== Deliver And Recall Parcel Test Start ======================" << std::endl;

    std::cout << "Capacity : " << cap << ", N : " << n << std::endl;
    std::cout << "Deliveries : [ ";
    for (const auto& ele : deliveries)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Pickups : [ ";
    for (const auto& ele : pickups)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(cap, n, deliveries, pickups);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Deliver And Recall Parcel Test End ======================" << std::endl;
}
