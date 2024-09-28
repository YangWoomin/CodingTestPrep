
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <climits>
#include    <unordered_set>

static int solution1(int n, std::vector<std::vector<int>> edge) {
    int answer = 0;

    std::vector<std::unordered_set<int>> graph(n + 1);
    for (const auto& ele : edge)
    {
        graph[ele[0]].insert(ele[1]);
        graph[ele[1]].insert(ele[0]);
    }

    std::vector<int> visited(n + 1, INT_MAX);
    visited[0] = 0;
    std::function<void(int, int)> dfs;
    dfs = [&](int node, int count) {
        if (count < visited[node])
        {
            visited[node] = count;
        }
        else
        {
            return;
        }

        for (const auto& ele : graph[node])
        {
            dfs(ele, count + 1);
        }
        };
    dfs(1, 0);

    int max = 0;
    for (const auto& ele : visited)
    {
        if (max < ele)
        {
            max = ele;
            answer = 1;
        }
        else if (max == ele)
        {
            answer++;
        }
    }

    return answer;
}

void FarthestNodeTest()
{
    int n = 6;
    std::vector<std::vector<int>> vertex = { {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} }; // 3

    std::cout << "====================== Farthest Node Test Start ======================" << std::endl;

    std::cout << "Board : [ ";
    for (const auto& ele : vertex)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, vertex);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Farthest Node Test End ======================" << std::endl;
}
