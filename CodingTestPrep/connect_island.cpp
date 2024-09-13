
#include	"set_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <unordered_set>
#include    <map>

// prim
static int solution1(int n, std::vector<std::vector<int>> costs) {
    int answer = 0;

    std::vector<std::vector<std::pair<int, int>>> graph(n);

    for (const auto& ele : costs)
    {
        int node1 = ele[0];
        int node2 = ele[1];
        int cost = ele[2];

        graph[node1].push_back(std::make_pair(node2, cost));
        graph[node2].push_back(std::make_pair(node1, cost));
    }

    int count = 0;
    int target = 0;
    std::unordered_set<int> connected;
    connected.insert(target);
    std::multimap<int, int> edges;
    while (count < n - 1)
    {
        for (const auto& ele : graph[target])
        {
            if (connected.end() == connected.find(ele.first))
            {
                edges.insert(std::make_pair(ele.second, ele.first));
            }
        }

        auto finder = connected.find(edges.begin()->second);
        while (connected.end() != finder)
        {
            edges.erase(edges.begin());
            finder = connected.find(edges.begin()->second);
        }
        answer += edges.begin()->first;
        target = edges.begin()->second;
        edges.erase(edges.begin());
        connected.insert(target);
        count++;
    }

    return answer;
}

int getRoot(std::vector<int>& set, int node)
{
    if (set[node] == node)
    {
        return node;
    }

    set[node] = getRoot(set, set[node]);

    return set[node];
}

// kruskal
static int solution2(int n, std::vector<std::vector<int>> costs) {
    int answer = 0;

    std::sort(costs.begin(), costs.end(), [](auto lhs, auto rhs) {
        return lhs[2] < rhs[2];
        });

    std::vector<int> set(n);
    for (int i = 0; i < n; ++i)
    {
        set[i] = i;
    }

    int count = 0;
    for (const auto& ele : costs)
    {
        int root1 = getRoot(set, ele[0]);
        int root2 = getRoot(set, ele[1]);

        if (root1 != root2)
        {
            set[root1] = root2;
            answer += ele[2];
            count++;
        }

        if (count == n - 1)
        {
            break;
        }
    }

    return answer;
}

void ConnectIslandTest()
{
    int n = 4;
    std::vector<std::vector<int>> costs = { { 0, 1, 1 }, { 0, 2, 2 }, { 1, 2, 5 }, { 1, 3, 1 }, { 2, 3, 8 } }; // 4

    std::cout << "====================== Connect Island Test Start ======================" << std::endl;

    std::cout << "Node Count : " << n << std::endl;
    std::cout << "Costs : [ ";
    for (const auto& ele : costs)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << ", " << ele[2] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(n, costs);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Connect Island Test End ======================" << std::endl;
}
