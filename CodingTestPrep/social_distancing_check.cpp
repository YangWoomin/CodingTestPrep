
#include	"test3.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <functional>

static std::vector<int> solution1(std::vector<std::vector<std::string>> places) {
    std::vector<int> answer;

    const std::vector<int> checkY = { 0, 0, -1, -1, -2, -1 };
    const std::vector<int> checkX = { -2, -1, -1, 0, 0, 1 };
    const std::vector<std::vector<std::pair<int, int>>> checkP = { {{0, -1}}, {}, {{0, -1},{-1, 0}}, {}, {{-1, 0}}, {{-1, 0},{0, 1}} };

    auto check = [&](int num, int y, int x) {
        for (int i = 0; i < checkY.size(); ++i)
        {
            int cy = y + checkY[i];
            int cx = x + checkX[i];
            if (0 <= cy && 0 <= cx && 'P' == places[num][cy][cx])
            {
                if (checkP[i].empty())
                {
                    return false;
                }

                for (int j = 0; j < checkP[i].size(); ++j)
                {
                    if ('X' != places[num][y + checkP[i][j].first][x + checkP[i][j].second])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
        };

    for (int num = 0; num < places.size(); ++num)
    {
        bool chk = true;
        for (int y = 0; y < places[num].size() && chk; ++y)
        {
            for (int x = 0; x < places[num][y].size() && chk; ++x)
            {
                if ('P' == places[num][y][x])
                {
                    if (!check(num, y, x))
                    {
                        chk = false;
                    }
                }
            }
        }
        if (chk)
        {
            answer.push_back(1);
        }
        else
        {
            answer.push_back(0);
        }
    }

    return answer;
}

void SocialDistancingCheckTest()
{
    std::vector<std::vector<std::string>> places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"} ,
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    }; // [1, 0, 1, 1, 1]

    std::cout << "====================== Social Distancing Check Test Start ======================" << std::endl;

    std::cout << "Places : " << std::endl;
    for (const auto& ele : places)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(places);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Social Distancing Check Test End ======================" << std::endl;
}
