
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

std::vector<int> changes = { 1, 10, 50, 100 };

// dp
static std::vector<int> solution1(int amount)
{
    std::vector<int> res;

    std::vector<int> p(amount + 1);
    p[0] = -1;

    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < changes.size(); ++j)
        {
            if (i < changes[j])
            {
                continue;
            }

            if (dp[i] > dp[i - changes[j]] + 1)
            {
                p[i] = i - changes[j];
                dp[i] = dp[i - changes[j]] + 1;
            }
        }
    }

    int idx = amount;
    while (0 <= p[idx])
    {
        res.push_back(idx - p[idx]);
        idx = p[idx];
    }
    std::sort(res.begin(), res.end(), std::greater<>());

    return res;
}

// greedy
static std::vector<int> solution2(int amount)
{
    std::vector<int> res;

    std::sort(changes.begin(), changes.end(), std::greater<int>());

    for (const auto& change : changes)
    {
        if (0 == amount)
        {
            break;
        }

        if (change > amount)
        {
            continue;
        }

        while (change <= amount)
        {
            res.push_back(change);
            amount -= change;
        }
    }

    return res;
}

void TakingChangeTest()
{
    int amount = 123; // [100, 10, 10, 1, 1, 1]
    //int amount = 350; // [100, 100, 100, 50]

    std::cout << "====================== Taking Change Test Start ======================" << std::endl;

    std::cout << "Amount : " << amount << std::endl;
    

    auto res = solution1(amount);

    std::cout << "Result: [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Taking Change Test End ======================" << std::endl;
}
