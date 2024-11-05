
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <queue>
#include    <tuple>
#include    <unordered_map>
#include    <unordered_set>

static int solution1(std::vector<std::vector<int>> land) {
    int answer = 0;

    auto isValid = [&](int y, int x) {
        return 0 <= y && y < land.size() && 0 <= x && x < land[0].size() && 1 == land[y][x];
        };

    const std::vector<int> dirY = { 0, 0, 1, -1 };
    const std::vector<int> dirX = { 1, -1, 0, 0 };

    std::unordered_map<int, std::unordered_set<int>> cols;
    std::unordered_map<int, int> oil;
    int num = 2;
    for (int i = 0; i < land.size(); ++i)
    {
        for (int j = 0; j < land[i].size(); ++j)
        {
            if (1 == land[i][j])
            {
                std::queue<std::tuple<int, int, int>> q;
                q.push({ i, j, num++ });

                while (!q.empty())
                {
                    auto [y, x, num] = q.front();
                    q.pop();

                    if (1 != land[y][x])
                    {
                        continue;
                    }

                    land[y][x] = num;
                    oil[num]++;

                    for (int k = 0; k < 4; ++k)
                    {
                        int ny = y + dirY[k];
                        int nx = x + dirX[k];
                        if (isValid(ny, nx))
                        {
                            q.push({ ny, nx, num });
                        }
                    }
                }
            }
            if (1 < land[i][j])
            {
                cols[j].insert(land[i][j]);
            }
        }
    }

    for (const auto& [col, nums] : cols)
    {
        int sum = 0;
        for (const auto& ele : nums)
        {
            sum += oil[ele];
        }

        answer = std::max(answer, sum);
    }

    return answer;
}

void OilDrillingTest()
{
    //std::vector<std::vector<int>> land = { 
    //    {0, 0, 0, 1, 1, 1, 0, 0} ,
    //    {0, 0, 0, 0, 1, 1, 0, 0},
    //    {1, 1, 0, 0, 0, 1, 1, 0},
    //    {1, 1, 1, 0, 0, 0, 0, 0},
    //    {1, 1, 1, 0, 0, 0, 1, 1}
    //}; // 9

    std::vector<std::vector<int>> land = {
        {1, 0, 1, 0, 1, 1} ,
        {1, 0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1}
    }; // 16

    std::cout << "====================== Oil Drilling Test Start ======================" << std::endl;

    std::cout << "Land : " << std::endl;
    for (const auto& ele : land)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "] " << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(land);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Oil Drilling Test End ======================" << std::endl;
}
