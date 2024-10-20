
#include	"dp_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<functional>

static int solution1(std::string str1, std::string str2)
{
    std::vector<std::vector<int>> dp(str1.size() + 1, std::vector<int>(str2.size() + 1));

    for (int i = 1; i <= str1.size(); ++i)
    {
        for (int j = 1; j <= str2.size(); ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[str1.size()][str2.size()];
}

void LcsLengthTest()
{
    //std::string str1 = "ABCBDAB";
    //std::string str2 = "BDCAB"; // 4

    std::string str1 = "AGGTAB";
    std::string str2 = "GXTXAYB"; // 4

    std::cout << "String 1 : " << str1 << std::endl;
    std::cout << "String 2 : " << str2 << std::endl;

    auto res = solution1(str1, str2);

    std::cout << "Result : " << res << std::endl;
}
