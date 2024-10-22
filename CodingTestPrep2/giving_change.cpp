
#include	"greedy_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<functional>

static std::vector<int> units = { 100, 50, 10, 1 };

// dp
static std::vector<int> solution1(int amount)
{
    std::vector<int> answer;

    std::vector<int> dp(amount + 1, amount);
    dp[0] = 0;

    std::vector<int> p(amount + 1);

    for (int i = 1; i <= amount; ++i)
    {
        for (const auto& unit : units)
        {
            if (i >= unit && dp[i - unit] + 1 < dp[i])
            {
                dp[i] = dp[i - unit] + 1;
                p[i] = unit;
            }
        }
    }

    int i = amount;
    while (0 < i)
    {
        answer.push_back(p[i]);
        i -= p[i];
    }

    return answer;
}

// greedy
static std::vector<int> solution2(int amount)
{
    std::vector<int> answer;

    for (const auto& unit : units)
    {
        while (unit <= amount)
        {
            answer.push_back(unit);
            amount -= unit;
        }

        if (0 == amount)
        {
            break;
        }
    }

    return answer;
}

void GivingChangeTest()
{
    int amount = 123; // [100, 10, 10, 1, 1, 1]
    //int amount = 350; // [100, 100, 100, 50]

    std::cout << "Amount : " << amount << std::endl;

    auto res = solution1(amount);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
}
