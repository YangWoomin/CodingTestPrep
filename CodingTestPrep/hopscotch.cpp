
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<std::vector<int> > land)
{
    for (int i = 1; i < land.size(); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int max = 0;
            for (int k = 0; k < 4; ++k)
            {
                if (k == j)
                {
                    continue;
                }
                max = std::max(max, land[i - 1][k]);
            }
            land[i][j] = land[i][j] + max;
        }
    }

    return *std::max_element(land.back().begin(), land.back().end());
}

void HopscotchTest()
{
    std::vector<std::vector<int>> land = { {1,2,3,5} ,{5,6,7,8},{4,3,2,1} }; // 16

    std::cout << "====================== Hopscotch Test Start ======================" << std::endl;

    std::cout << "Land : " << std::endl;
    for (const auto& ele : land)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(land);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Hopscotch Test End ======================" << std::endl;
}
