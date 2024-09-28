
#include	"backtracking_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static int solution1(int n, std::vector<int> weak, std::vector<int> dist) {
    int answer = 0;

    std::sort(dist.begin(), dist.end(), std::greater<int>());

    std::vector<bool> visited(n, false);
    std::function<void(int, int)> dfs = [&](int idx, int count) {

        if (weak.size() == count)
        {
            if (0 == answer || idx < answer)
            {
                answer = idx;
            }
            return;
        }

        if (dist.size() == idx)
        {
            return;
        }

        for (int i = 0; i < weak.size(); ++i)
        {
            if (visited[weak[i]])
            {
                continue;
            }

            int max = dist[idx], move = 0;
            int cur = i, pre = i;
            std::vector<int> lv;
            while (0 <= max - move && !visited[weak[cur]])
            {
                visited[weak[cur]] = true;
                lv.push_back(weak[cur]);
                pre = cur;
                cur = (cur + 1) % weak.size();
                int tmp = weak[cur] - weak[pre];
                move += tmp > 0 ? tmp : n + tmp;
            }

            dfs(idx + 1, count + lv.size());

            for (const auto& ele : lv)
            {
                visited[ele] = false;
            }
        }
        };

    dfs(0, 0);

    return answer ? answer : -1;
}

void ExteriorInspectionTest()
{
    //int n = 12;
    //std::vector<int> weak = { 1, 5, 6, 10 };
    //std::vector<int> dist = { 1, 2, 3, 4 }; // 2

    //int n = 12;
    //std::vector<int> weak = { 1, 3, 4, 9, 10 };
    //std::vector<int> dist = { 3, 5, 7 }; // 1

    int n = 6;
    std::vector<int> weak = { 1, 2, 4, 5 };
    std::vector<int> dist = { 1, 1 }; // 2

    std::cout << "====================== Exterior Inspection Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;
    std::cout << "Weak : [ ";
    for (const auto& ele : weak)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Dist : [ ";
    for (const auto& ele : dist)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, weak, dist);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Exterior Inspection Test End ======================" << std::endl;
}

