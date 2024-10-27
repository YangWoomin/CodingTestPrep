
#include	"test5.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <algorithm>

static std::vector<int> solution1(std::vector<int> lottos, std::vector<int> win_nums) {

    std::sort(win_nums.begin(), win_nums.end());

    int zeros = std::count(lottos.begin(), lottos.end(), 0);

    int count = 0;
    for (const auto& ele : lottos)
    {
        if (0 != ele)
        {
            auto it = std::find(win_nums.begin(), win_nums.end(), ele);
            if (win_nums.end() != it)
            {
                count++;
            }
        }
    }

    int max = count + zeros, min = count;
    auto getRank = [](int match) {
        switch (match)
        {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        }
        return 6;
        };

    return { getRank(max), getRank(min) };
}

void LottoMaxAndMinRankTest()
{
    //std::vector<int> lottos = { 44, 1, 0, 0, 31, 25 };
    //std::vector<int> win_nums = { 31, 10, 45, 1, 6, 19 }; // [3, 5]

    //std::vector<int> lottos = { 0, 0, 0, 0, 0, 0 };
    //std::vector<int> win_nums = { 38, 19, 20, 40, 15, 25 }; // [1, 6]

    std::vector<int> lottos = { 45, 4, 35, 20, 3, 9 };
    std::vector<int> win_nums = { 20, 9, 3, 45, 4, 35 }; // [1, 1]

    std::cout << "====================== Lotto Max And Min Rank Test Start ======================" << std::endl;

    std::cout << "Lottos : [ ";
    for (const auto& ele : lottos)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Win Numbers : [ ";
    for (const auto& ele : win_nums)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(lottos, win_nums);

    std::cout << "Result : " << res[0] << ", " << res[1] << std::endl;

    std::cout << "====================== Lotto Max And Min Rank Test End ======================" << std::endl;
}
