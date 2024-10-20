
#include	"dp_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<functional>

static int solution1(std::vector<std::vector<int>> arr)
{
    const int size = arr[0].size();

    std::vector<std::vector<int>> dp(4, std::vector<int>(size + 1));

    for (int i = 1; i <= size; ++i)
    {
        dp[0][i] = std::max(dp[1][i - 1], dp[2][i - 1]) + arr[0][i - 1];
        dp[1][i] = std::max(dp[0][i - 1], std::max(dp[2][i - 1], dp[3][i - 1])) + arr[1][i - 1];
        dp[2][i] = std::max(dp[0][i - 1], dp[1][i - 1]) + arr[2][i - 1];
        dp[3][i] = dp[1][i - 1] + arr[0][i - 1] + arr[2][i - 1];
    }

    auto res = { dp[0][size], dp[1][size], dp[2][size], dp[3][size] };
    return *std::max_element(res.begin(), res.end());
}

void CobblestoneTest()
{
    //std::vector<std::vector<int>> arr = { {1, 3, 3, 2}, {2, 1, 4, 1}, {1, 5, 2, 3} }; // 19
    std::vector<std::vector<int>> arr = { {1, 7, 13, 2, 6}, {2, -4, 2, 5, 4}, {5, 3, 5, -3, 1} }; // 32

    std::cout << "Arrays : " << std::endl;
    for (const auto& ele : arr)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(arr);

    std::cout << "Result : " << res << std::endl;
}
