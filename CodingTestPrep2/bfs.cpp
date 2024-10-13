
#include	"graph_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<queue>
#include	<unordered_map>
#include	<unordered_set>

static std::vector<int> solution1(std::vector<std::pair<int, int>> graph, int start)
{
	std::vector<int> res;

	std::unordered_map<int, std::vector<int>> g;
	for (const auto& ele : graph)
	{
		g[ele.first].push_back(ele.second);
	}

	std::unordered_set<int> visit;
	std::queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		if (visit.end() != visit.find(node))
		{
			continue;
		}

		res.push_back(node);
		visit.insert(node);

		for (const auto& ele : g[node])
		{
			q.push(ele);
		}
	}

	return res;
}

void BFSTest()
{
	//std::vector<std::pair<int, int>> graph = { {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9} };
	//int start = 1; // [1, 2, 3, 4, 5, 6, 7, 8, 9]

	std::vector<std::pair<int, int>> graph = { {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0} };
	int start = 1; // [1, 2, 3, 4, 5, 0]

	std::cout << "Graph : [ ";
	for (const auto& ele : graph)
	{
		std::cout << "[ " << ele.first << " " << ele.second << " ] ";
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
}
