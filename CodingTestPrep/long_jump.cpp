
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static long long solution1(int n) {

    std::vector<long long> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        dp[i] += dp[i - 2];
        dp[i] %= 1234567;
    }

    return dp[n];
}

void LongJumpTest()
{
    //int n = 4; // 5
    int n = 3; // 3

    std::cout << "====================== Long Jump Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Long Jump Test End ======================" << std::endl;
}
