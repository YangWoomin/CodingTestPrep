
#include	"graph_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<queue>
#include	<unordered_map>
#include	<tuple>
#include	<climits>

// using edges
static std::vector<int> solution1(int numVertices, std::vector<std::tuple<int, int, int>> edges, int source)
{
	std::vector<int> res(numVertices, INT_MAX);
	res[source] = 0;

	for (int i = 0; i < numVertices - 1; ++i)
	{
		for (const auto& [from, to, weight] : edges)
		{
			if (INT_MAX != res[from] && res[from] + weight < res[to])
			{
				res[to] = res[from] + weight;
			}
		}
	}

	for (const auto& [from, to, weight] : edges)
	{
		if (INT_MAX != res[from] && res[from] + weight < res[to])
		{
			return { -1 };
		}
	}

	return res;
}

// using vertices
static std::vector<int> solution2(int numVertices, std::vector<std::tuple<int, int, int>> edges, int source)
{
	std::vector<int> res(numVertices, INT_MAX);
	res[source] = 0;

	std::vector<std::vector<std::pair<int, int>>> graph(numVertices);
	for (const auto& [from, to, weight] : edges)
	{
		graph[from].push_back({ to, weight });
	}

	for (int i = 0; i < numVertices - 1; ++i)
	{
		for (int j = 0; j < numVertices; ++j)
		{
			for (const auto& [node, weight] : graph[j])
			{
				if (INT_MAX != res[j] && res[j] + weight < res[node])
				{
					res[node] = res[j] + weight;
				}
			}
		}
	}

	for (int j = 0; j < numVertices; ++j)
	{
		for (const auto& [node, weight] : graph[j])
		{
			if (INT_MAX != res[j] && res[j] + weight < res[node])
			{
				return { -1 };
			}
		}
	}

	return res;
}

void BellmanFordTest()
{
	//std::vector<std::tuple<int, int, int>> edges = { {0, 1, 4}, {0, 2, 3}, {0, 4, -6}, {1, 3, 5}, {2, 1, 2}, {3, 0, 7}, {3, 2, 4}, {4, 2, 2} };
	//int numVerticies = 5, source = 0; // [0 -2 -4 3 -6]

	std::vector<std::tuple<int, int, int>> edges = { {0, 1, 5}, {0, 2, -1}, {1, 2, 2}, {2, 3, -2}, {3, 0, 2}, {3, 1, 6} };
	int numVerticies = 4, source = 0; // []

	std::cout << "Vertices Number : " << numVerticies << ", Source : " << source << std::endl;
	std::cout << "Edges : [ ";
	for (const auto& [from, to, weight] : edges)
	{
		std::cout << "[ " << from << " " << to << " " << weight << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution2(numVerticies, edges, source);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
