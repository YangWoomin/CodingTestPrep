
#include	"greedy_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>


// dp
static int solution1(std::vector<std::vector<int>> items, int weight_limit)
{
    std::vector<int> dp(weight_limit + 1);

    for (int i = 1; i <= items.size(); ++i)
    {
        int weight = items[i - 1][0], value = items[i - 1][1];
        for (int j = weight_limit; j > 0; --j)
        {
            if (j >= weight)
            {
                dp[j] = std::max(dp[j], dp[j - weight] + value);
            }
        }
    }

    return dp[weight_limit];
}

void _0_1_KnapsackTest()
{
    std::vector<std::vector<int>> items = { {10, 19}, {7, 10}, {6, 10} }; // 20
    int weight_limit = 15;

    std::cout << "Items : [ ";
    for (const auto& ele : items)
    {
        std::cout << "[ " << ele[0] << " " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Weight Limit : " << weight_limit << std::endl;

    auto res = solution1(items, weight_limit);

    std::cout << "Result : " << res << std::endl;
}
