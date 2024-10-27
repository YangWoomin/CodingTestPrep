
#include	"test4.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <functional>

static int solution1(int alp, int cop, std::vector<std::vector<int>> problems) {

    int alpMax = alp, copMax = cop;
    for (const auto& ele : problems)
    {
        alpMax = std::max(alpMax, ele[0]);
        copMax = std::max(copMax, ele[1]);
    }

    if (alpMax <= alp && copMax <= cop)
    {
        return 0;
    }

    std::vector<std::vector<int>> dp(alpMax + 1, std::vector<int>(copMax + 1, INT_MAX));
    dp[alp][cop] = 0;

    for (int i = alp; i <= alpMax; ++i)
    {
        for (int j = cop; j <= copMax; ++j)
        {
            if (i + 1 <= alpMax)
            {
                dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j] + 1);
            }

            if (j + 1 <= copMax)
            {
                dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + 1);
            }

            for (const auto& ele : problems)
            {
                int alpReq = ele[0], alpRwd = ele[2];
                int copReq = ele[1], copRwd = ele[3];
                int cost = ele[4];

                if (alpReq <= i && copReq <= j)
                {
                    int nextAlp = std::min(i + alpRwd, alpMax);
                    int nextCop = std::min(j + copRwd, copMax);
                    dp[nextAlp][nextCop] = std::min(dp[nextAlp][nextCop], dp[i][j] + cost);
                }
            }
        }
    }

    return dp[alpMax][copMax];
}

void CodingTestStudyTest()
{
    //int alp = 10, cop = 10;
    //std::vector<std::vector<int>> problems = { {10,15,2,1,2} ,{20,20,3,3,4} }; // 15

    int alp = 0, cop = 0;
    std::vector<std::vector<int>> problems = { {0,0,2,1,2} ,{4,5,3,1,2},{4,11,4,0,2},{10,4,0,4,2} }; // 13

    std::cout << "====================== Coding Test Study Test Start ======================" << std::endl;

    std::cout << "Alp : " << alp << ", Cop : " << cop << std::endl;
    std::cout << "Problems : " << std::endl;
    for (const auto& ele : problems)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(alp, cop, problems);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Coding Test Study Test End ======================" << std::endl;
}
