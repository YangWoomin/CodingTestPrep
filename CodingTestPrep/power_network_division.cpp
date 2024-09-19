
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <cstring>
#include    <algorithm>
#include    <functional>
#include    <unordered_set>

// union-find
static int solution1(int n, std::vector<std::vector<int>> wires) {
    int answer = n;

    int origin[101] = { 0, };
    for (int i = 0; i <= n; ++i)
    {
        origin[i] = i;
    }

    for (int i = 0; i < wires.size(); ++i)
    {
        std::vector<std::vector<int>> tmp = wires;
        tmp.erase(tmp.begin() + i);

        int parent[101];
        std::memcpy(parent, origin, sizeof(parent));

        int count[101];
        std::fill(count, count + 101, 1);

        std::function<int(int)> getParent;
        getParent = [&](int node) {
            if (parent[node] == node)
            {
                return node;
            }

            return parent[node] = getParent(parent[node]);
            };

        auto merge = [&](int node1, int node2) {
            int root1 = getParent(node1);
            int root2 = getParent(node2);
            if (root1 != root2)
            {
                parent[root1] = root2;
                count[root2] += count[root1];
            }
            };

        for (const auto& ele : tmp)
        {
            merge(ele[0], ele[1]);
        }

        int* max = std::max_element(count, count + 101);
        int diff = *max - (n - *max);
        if (diff < answer)
        {
            answer = diff;
        }
    }

    return answer;
}

// dfs
static int solution2(int n, std::vector<std::vector<int>> wires) {
    int answer = n;

    std::vector<std::unordered_set<int>> graph(n + 1);
    for (const auto& ele : wires)
    {
        graph[ele[0]].insert(ele[1]);
        graph[ele[1]].insert(ele[0]);
    }

    std::vector<int> visited(n + 1, 0);
    std::function<int(int)> dfs = [&](int node) {
        visited[node] = 1;
        for (const auto& ele : graph[node])
        {
            if (0 == visited[ele])
            {
                visited[node] += dfs(ele);
            }
        }

        return visited[node];
        };

    dfs(1);

    for (int i = 1; i < visited.size(); ++i)
    {
        int rest = n - visited[i];
        answer = std::min(answer, std::abs(visited[i] - rest));
    }

    return answer;
}

void PowerNetworkDivisionTest()
{
    int n = 9;
    std::vector<std::vector<int>> wires = { {1,3} ,{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} }; // 3

    //int n = 4;
    //std::vector<std::vector<int>> wires = { {1,2} ,{2,3},{3,4} }; // 0

    //int n = 7;
    //std::vector<std::vector<int>> wires = { {1,2} ,{2,7},{3,7},{3,4},{4,5},{6,7} }; // 1

    std::cout << "====================== Power Network Division Test Start ======================" << std::endl;

    std::cout << "Board : [ ";
    for (const auto& ele : wires)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(n, wires);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Power Network Division Test Start ======================" << std::endl;
}
