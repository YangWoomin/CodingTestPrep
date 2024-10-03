
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<std::vector<int>>& arr)
{
    std::vector<std::vector<int>> dp(4, std::vector<int>(arr[0].size() + 1));

    for (int i = 0; i < arr[0].size(); ++i)
    {
        dp[0][i + 1] = std::max(dp[1][i], dp[2][i]) + arr[0][i];
        dp[1][i + 1] = std::max({ dp[0][i], dp[2][i], dp[3][i] }) + arr[1][i];
        dp[2][i + 1] = std::max(dp[0][i], dp[1][i]) + arr[2][i];
        dp[3][i + 1] = dp[1][i] + arr[0][i] + arr[2][i];
    }

    return std::max({ dp[0][arr[0].size()], dp[1][arr[0].size()], dp[2][arr[0].size()], dp[3][arr[0].size()]});
}

void CobblestoneProblemTest()
{
    //std::vector<std::vector<int>> arr = { {1,3,3,2}, {2,1,4,1}, {1,5,2,3} }; // 19
    //std::vector<std::vector<int>> arr = { {1,7,13,2,6}, {2,-4,2,5,4}, {5,3,5,-3,1} }; // 36
    std::vector<std::vector<int>> arr = { {1}, {2}, {5} }; // 6

    std::cout << "====================== Cobblestone Problem Test Start ======================" << std::endl;

    std::cout << "Array : " << std::endl;
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

    std::cout << "====================== Cobblestone Problem Test End ======================" << std::endl;
}
