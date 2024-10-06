
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

#include    <unordered_set>

static int solution1(int N, int number) {

    std::vector<std::unordered_set<int>> dp(9);

    for (int i = 1; i < 9; ++i)
    {
        dp[i].insert(std::stoi(std::string(i, '0' + N)));

        for (int j = 1; j < i; ++j)
        {
            for (int x : dp[j])
            {
                for (int y : dp[i - j])
                {
                    dp[i].insert(x + y);
                    dp[i].insert(x - y);
                    dp[i].insert(x * y);
                    if (0 < y)
                    {
                        dp[i].insert(x / y);
                    }
                }
            }
        }

        if (dp[i].count(number))
        {
            return i;
        }
    }

    return -1;
}

void NRepresentationTest()
{
    //int N = 5, number = 12; // 4
    int N = 2, number = 11; // 3

    std::cout << "====================== N Representation Test Start ======================" << std::endl;

    std::cout << "N : " << N << std::endl;
    std::cout << "Number : " << number << std::endl;

    auto res = solution1(N, number);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== N Representation Test End ======================" << std::endl;
}
