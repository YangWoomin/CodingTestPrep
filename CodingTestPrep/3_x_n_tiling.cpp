
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static int solution1(int n) {

    std::vector<long long> dp(n + 1);
    dp[0] = 1;

    for (int i = 2; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        int tmp = i - 4;
        while (0 <= tmp)
        {
            dp[i] += dp[tmp] * 2;
            tmp -= 2;
        }
        dp[i] %= 1000000007;
    }

    return dp[n];
}

void _3XNTilingTest()
{
    //int n = 4; // 11
    int n = 6; // 41

    std::cout << "====================== 3 x N Tiling Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== 3 x N Tiling Test End ======================" << std::endl;
}
