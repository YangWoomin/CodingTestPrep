
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <queue>

static int solution1(int n, std::vector<std::vector<int>> results) {
    int answer = 0;

    std::vector<std::vector<int>> wg(n + 1);
    std::vector<std::vector<int>> dg(n + 1);
    for (const auto& ele : results)
    {
        wg[ele[0]].push_back(ele[1]);
        dg[ele[1]].push_back(ele[0]);
    }

    std::vector<int> count(n + 1);
    for (int j = 0; j < 2; ++j)
    {
        std::vector<std::vector<int>>* graph = 0 == j ? &wg : &dg;
        for (int i = 1; i <= n; ++i)
        {
            std::queue<int> q;
            std::vector<bool> visited(n + 1, false);
            q.push(i);

            while (false == q.empty())
            {
                auto num = q.front();
                q.pop();

                if (visited[num])
                {
                    continue;
                }

                visited[num] = true;

                if (i != num)
                {
                    count[num]++;
                }

                for (const auto& ele : (*graph)[num])
                {
                    if (!visited[ele])
                    {
                        q.push(ele);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (count[i] == n - 1)
        {
            answer++;
        }
    }

    return answer;
}

void RankingTest()
{
    int n = 5;
    std::vector<std::vector<int>> results = { {4, 3} ,{4, 2},{3, 2},{1, 2},{2, 5} }; // 2

    std::cout << "====================== Ranking Test Start ======================" << std::endl;

    std::cout << "Results : [ ";
    for (const auto& ele : results)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, results);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Ranking Test Start ======================" << std::endl;
}
