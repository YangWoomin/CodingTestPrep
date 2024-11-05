
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static int solution1(int n) {

    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    return dp[n];
}

void CorrectBracketCountTest()
{
    //int n = 2; // 2
    int n = 3; // 5

    std::cout << "====================== Correct Bracket Count Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Correct Bracket Count Test End ======================" << std::endl;
}
