
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <unordered_set>
#include    <functional>

static int solution1(std::vector<int> info, std::vector<std::vector<int>> edges) {
    std::vector<std::unordered_set<int>> graph(info.size());
    for (const auto& ele : edges)
    {
        graph[ele[0]].insert(ele[1]);
    }

    std::function<void(std::unordered_set<int>, int, int)> findMax;
    int max = 0;
    findMax = [&](std::unordered_set<int> candidates, int rest, int count) {
        for (const auto& ele : candidates)
        {
            int rst = rest, cnt = count;
            if (0 == info[ele])
            {
                rst++;
                cnt++;
            }
            else
            {
                rst--;
            }
            if (0 == rst)
            {
                continue;
            }

            std::unordered_set<int> cd = candidates;
            cd.erase(ele);
            for (const auto& ele2 : graph[ele])
            {
                cd.insert(ele2);
            }
            findMax(cd, rst, cnt);
        }

        if (max < count)
        {
            max = count;
        }
    };

    std::unordered_set<int> candidates;
    candidates.insert(0);
    findMax(candidates, 0, 0);
    return max;
}

void SheepAndWolfTest()
{
	std::vector<int> info = { 0,0,1,1,1,0,1,0,1,0,1,1 };
	std::vector<std::vector<int>> edges = { { 0, 1 }, { 1, 2 }, { 1, 4 }, { 0, 8 }, { 8, 7 }, { 9, 10 }, { 9, 11 }, { 4, 3 }, { 6, 5 }, { 4, 6 }, { 8, 9 } }; // 5

    //std::vector<int> info = { 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0 };
    //std::vector<std::vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 }, { 3, 7 }, { 4, 8 }, { 6, 9 }, { 9, 10 } }; // 5

	std::cout << "====================== Sheep And Wolf Test Start ======================" << std::endl;

	std::cout << "Info : [ ";
	for (const auto& ele : info)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Edges : [ ";
	for (const auto& ele : edges)
	{
		std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(info, edges);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Sheep And Wolf Test Start ======================" << std::endl;
}
