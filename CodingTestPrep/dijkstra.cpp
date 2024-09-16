
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <climits>
#include	<tuple>
#include	<queue>
#include	<unordered_map>

static std::vector<int> solution1(int start, int numNodes, const std::vector<std::tuple<int, int, int>>& edges)
{
	std::vector<int> res(numNodes, INT_MAX);

	std::vector<std::unordered_map<int, int>> graph(numNodes);
	for (const auto& [from, to, weight] : edges)
	{
		graph[from][to] = weight;
	}

	std::vector<bool> visited(numNodes, false);
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
	pq.push({ 0, start });
	res[start] = 0;

	while (false == pq.empty())
	{
		auto [cost, next] = pq.top();
		pq.pop();

		if (true == visited[next])
		{
			continue;
		}

		visited[next] = true;

		for (const auto& [to, weight] : graph[next])
		{
			int newCost = res[next] + weight;
			if (newCost < res[to])
			{
				res[to] = newCost;
				pq.push({ newCost, to });
			}
		}
	}

	return res;
}

void DijkstraTest()
{
	//int start = 0, numNodes = 3;
	//std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 9 }, { 0, 2, 3 }, { 1, 0, 5 }, { 2, 1, 1 } }; // [0, 4, 3]

	//int start = 0, numNodes = 4;
	//std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 1 }, { 1, 2, 5 }, { 2, 3, 1 } }; // [0, 1, 6, 7]

	int start = 0, numNodes = 5;
	std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 4 }, { 0, 2, 4 }, { 0, 4, 1 }, { 1, 2, 6 }, { 2, 3, 8 }, { 3, 0, 5 }, { 3, 1, 2 }, { 4, 2, 2 } }; // [0, 4, 3, 11, 1]

	std::cout << "====================== Dijkstra Test Start ======================" << std::endl;

	std::cout << "Start : " << start << ", Node Number : " << numNodes << std::endl;
	std::cout << "Edges : [ ";
	for (const auto& ele : edges)
	{
		std::cout << "[ " << std::get<0>(ele) << ", " << std::get<1>(ele) << ", " << std::get<2>(ele) << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(start, numNodes, edges);
	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "====================== Dijkstra Test Start ======================" << std::endl;
}
