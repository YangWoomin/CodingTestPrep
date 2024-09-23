
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static int solution1(int k, std::vector<std::vector<int>> dungeons) {
    int answer = 0;

    std::sort(dungeons.begin(), dungeons.end(), [](auto& lhs, auto& rhs) {
        if (lhs[0] == rhs[0])
        {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
        });

    std::vector<bool> visited(dungeons.size(), false);
    std::function<void(int, int)> dfs = [&](int depth, int fatigue) {
        if (answer < depth)
        {
            answer = depth;
        }

        for (int i = 0; i < dungeons.size(); ++i)
        {
            if (!visited[i])
            {
                if (dungeons[i][0] <= fatigue)
                {
                    visited[i] = true;
                    dfs(depth + 1, fatigue - dungeons[i][1]);
                    visited[i] = false;
                }
                else
                {
                    break; // backtracking
                }
            }
        }
        };

    dfs(0, k);

    return answer;
}

void DungeonFatigueTest()
{
    int k = 80;
    std::vector<std::vector<int>> dungeons = { {80,20},{50,40},{30,10} }; // 3

    std::cout << "====================== Dungeon Fatigue Test Start ======================" << std::endl;

    std::cout << "Dungeons : [ ";
    for (const auto& ele : dungeons)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(k, dungeons);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Dungeon Fatigue Test Start ======================" << std::endl;
}
