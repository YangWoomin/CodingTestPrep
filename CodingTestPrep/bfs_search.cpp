
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <queue>
#include	<unordered_set>
#include	<unordered_map>


static std::vector<int> solution1(std::vector <std::pair<int, int>>& graph, int start)
{
	std::vector<int> res;

	std::unordered_map<int, std::vector<int>> graph2;
	for (const auto& ele : graph)
	{
		graph2[ele.first].push_back(ele.second);
	}

	std::queue<int> q;
	std::unordered_set<int> visited;
	q.push(start);
	visited.insert(start);
	res.push_back(start);

	while (false == q.empty())
	{
		auto node = q.front();
		q.pop();
		for (const auto& ele : graph2[node])
		{
			if (true == visited.insert(ele).second)
			{
				q.push(ele);
				res.push_back(ele);
			}
		}
	}

	return res;
}

void BfsSearchTest()
{
	//std::vector<std::pair<int, int>> graph = { { 1, 2 }, { 1, 3 }, { 2, 4 }, { 2, 5 }, { 3, 6 }, { 3, 7 }, { 4, 8 }, { 5, 8 }, { 6, 9 }, { 7, 9 } };
	//int start = 1; // [1, 2, 3, 4, 5, 6, 7, 8, 9]

	std::vector<std::pair<int, int>> graph = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 0 } };
	int start = 1; // [1, 2, 3, 4, 5, 0]

	std::cout << "====================== BFS Search Test Start ======================" << std::endl;

	std::cout << "Graph : [ ";
	for (const auto& ele : graph)
	{
		std::cout << "[ " << ele.first << ", " << ele.second << " ] ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Start : " << start << std::endl;

	auto res = solution1(graph, start);
	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "====================== BFS Search Test End ======================" << std::endl;
}
