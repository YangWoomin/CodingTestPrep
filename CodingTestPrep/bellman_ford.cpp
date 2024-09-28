
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <climits>
#include	<tuple>
#include	<queue>
#include	<unordered_map>

static std::vector<int> solution1(int nodeNum, const std::vector<std::tuple<int, int, int>>& edges, int start)
{
	std::vector<int> res(nodeNum, INT_MAX);

	res[start] = 0;

	for (int i = 0; i < nodeNum - 1; ++i)
	{
		for (const auto& [from, to, weight] : edges)
		{
			if (INT_MAX != res[from])
			{
				int newCost = res[from] + weight;
				if (newCost < res[to])
				{
					res[to] = newCost;
				}
			}
		}
	}

	for (const auto& [from, to, weight] : edges)
	{
		if (INT_MAX != res[from])
		{
			int newCost = res[from] + weight;
			if (newCost < res[to])
			{
				return { -1 };
			}
		}
	}

	return res;
}

void BellmanFordTest()
{
	//int start = 0, nodeNum = 3;
	//std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 9 }, { 0, 2, 3 }, { 1, 0, 5 }, { 2, 1, 1 } }; // [0, 4, 3]

	//int start = 0, nodeNum= 4;
	//std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 1 }, { 1, 2, 5 }, { 2, 3, 1 } }; // [0, 1, 6, 7]

	//int start = 0, nodeNum = 5;
	//std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 4 }, { 0, 2, 4 }, { 0, 4, 1 }, { 1, 2, 6 }, { 2, 3, 8 }, { 3, 0, 5 }, { 3, 1, 2 }, { 4, 2, 2 } }; // [0, 4, 3, 11, 1]

	//int start = 0, nodeNum = 5;
	//std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 4 }, { 0, 2, 3 }, { 0, 4, -6 }, { 1, 3, 5 }, { 2, 1, 2 }, { 3, 0, 7 }, { 3, 2, 4 }, { 4, 2, 2 } }; // [0, -2, -4, 3, -6]

	int start = 0, nodeNum = 4;
	std::vector<std::tuple<int, int, int>> edges = { { 0, 1, 5 }, { 0, 2, -1 }, { 1, 2, 2 }, { 2, 3, -2 }, { 3, 0, 2 }, { 3, 1, 6 } }; // [-1]

	std::cout << "====================== Bellman Ford Test Start ======================" << std::endl;

	std::cout << "Start : " << start << ", Node Number : " << nodeNum << std::endl;
	std::cout << "Edges : [ ";
	for (const auto& ele : edges)
	{
		std::cout << "[ " << std::get<0>(ele) << ", " << std::get<1>(ele) << ", " << std::get<2>(ele) << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(nodeNum, edges, start);
	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "====================== Bellman Ford Test End ======================" << std::endl;
}
