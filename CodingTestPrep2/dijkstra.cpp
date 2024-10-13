
#include	"graph_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<queue>
#include	<unordered_map>
#include	<tuple>

static std::vector<int> solution1(int start, int numNodes, std::vector<std::tuple<int, int, int>> edges)
{
	std::vector<int> res(numNodes, -1);

	std::unordered_map<int, std::vector<std::pair<int, int>>> graph;
	for (const auto& [from, to, weight] : edges)
	{
		graph[from].push_back({ to, weight });
	}

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		auto [weight, node] = pq.top();
		pq.pop();

		if (-1 != res[node])
		{
			continue;
		}

		res[node] = weight;

		for (const auto& [next, w] : graph[node])
		{
			if (-1 == res[next])
			{
				pq.push({ w + weight, next });
			}
		}
	}

	return res;
}

void DijkstraTest()
{
	//int start = 0, numNodes = 3;
	//std::vector<std::tuple<int, int, int>> edges = { {0, 1, 9}, {0, 2, 3}, {1, 0, 5}, {2, 1, 1} }; // [0, 4, 3]

	int start = 0, numNodes = 4;
	std::vector<std::tuple<int, int, int>> edges = { {0, 1, 1}, {1, 2, 5}, {2, 3, 1} }; // [0, 1, 6, 7]

	std::cout << "Start : " << start << ", Node Number : " << numNodes << std::endl;
	std::cout << "Edges : [ ";
	for (const auto& [from, to, weight] : edges)
	{
		std::cout << "[ " << from << " " << to << " " << weight << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(start, numNodes, edges);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
