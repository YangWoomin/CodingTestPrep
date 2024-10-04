
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<int> money) {
    int answer = 0;

    const int size = money.size();

    std::vector<int> dp = money;
    // the first house is not included
    dp[0] = 0;
    for (int i = 1; i < size; ++i)
    {
        dp[i] += i - 2 >= 0 ? dp[i - 2] : 0;
        dp[i] = std::max(dp[i - 1], dp[i]);
    }

    answer = dp[size - 1];

    // the first house is included
    dp = money;
    for (int i = 1; i < size - 1; ++i)
    {
        dp[i] += i - 2 >= 0 ? dp[i - 2] : 0;
        dp[i] = std::max(dp[i - 1], dp[i]);
    }

    answer = std::max(answer, dp[size - 2]);

    return answer;
}

void TheftTest()
{
    std::vector<int> money = { 1, 2, 3, 1 }; // 4

    std::cout << "====================== Theft Test Start ======================" << std::endl;

    std::cout << "Money : [ ";
    for (const auto& ele : money)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(money);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Theft Test End ======================" << std::endl;
}
