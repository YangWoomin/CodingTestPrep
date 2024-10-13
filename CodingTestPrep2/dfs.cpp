
#include	"graph_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>
#include	<unordered_map>
#include	<unordered_set>

static std::vector<char> solution1(std::vector<std::pair<char, char>> graph, char start)
{
	std::vector<char> res;

	std::unordered_map<char, std::vector<char>> g;
	for (const auto& ele : graph)
	{
		g[ele.first].push_back(ele.second);
	}

	std::unordered_set<char> visit;
	std::function<void(char)> dfs = [&](char node) {

		if (visit.end() != visit.find(node))
		{
			return;
		}

		visit.insert(node);

		res.push_back(node);

		for (const auto& ele : g[node])
		{
			dfs(ele);
		}
	};

	dfs(start);

	return res;
}

void DFSTest()
{
	//std::vector<std::pair<char, char>> graph = { {'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'} };
	//char start = 'A'; // ['A' 'B' 'C' 'D' 'E']

	std::vector<std::pair<char, char>> graph = { {'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'} };
	char start = 'A'; // ['A' 'B' 'D' 'E' 'F' 'C']

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
