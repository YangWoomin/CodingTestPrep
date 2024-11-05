
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

static std::vector<int> solution1(std::vector<std::vector<int>> edges) {

    std::unordered_map<int, int> targeted;
    std::unordered_map<int, std::vector<int>> graph;
    for (const auto& ele : edges)
    {
        graph[ele[0]].push_back(ele[1]);
        targeted[ele[1]]++;
    }

    int newNode = 0, stick = 0, doughnut = 0, eight = 0;
    for (const auto& [p, c] : graph)
    {
        if (0 == targeted[p] && 1 < c.size())
        {
            newNode = p;
            break;
        }
    }

    int total = graph[newNode].size();
    for (const auto& node : graph[newNode])
    {
        targeted[node]--;
    }

    for (const auto& [p, c] : graph)
    {
        if (2 == targeted[p] && 2 == c.size())
        {
            eight++;
        }
    }

    for (const auto& [t, c] : targeted)
    {
        if (0 == graph[t].size())
        {
            stick++;
        }
    }

    doughnut = total - stick - eight;

    return { newNode, doughnut, stick, eight };
}

void DoughnutAndStickGraphTest()
{
    //std::vector<std::vector<int>> edges = { {2, 3} ,{4, 3},{1, 1},{2, 1} }; // [2, 1, 1, 0]
    std::vector<std::vector<int>> edges = { {4, 11} ,{1, 12},{8, 3},{12, 7},{4, 2},{7, 11},{4, 8},{9, 6},{10, 11},{6, 10},{3, 5},{11, 1},{5, 3},{11, 9},{3, 8} }; // [4, 0, 1, 2]

    std::cout << "====================== Doughnut And Stick Graph Test Start ======================" << std::endl;

    std::cout << "Edges : [ ";
    for (const auto& ele : edges)
    {
        std::cout << "[ " << ele[0] << " " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(edges);

    std::cout << "Result : [ " << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << " ]" << std::endl;

    std::cout << "====================== Doughnut And Stick Graph Test End ======================" << std::endl;
}
