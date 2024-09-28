
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <stack>
#include	<unordered_set>

static std::vector<char> solution1(std::vector<std::pair<char, char>>& graph, char start)
{
	std::vector<char> res;

	std::vector<std::vector<int>> graph2(26);
	for (const auto& ele : graph)
	{
		graph2[ele.first - 'A'].push_back(ele.second - 'A');
	}

	std::stack<int> st;
	st.push(start - 'A');
	std::unordered_set<int> visited;

	while (false == st.empty())
	{
		auto node = st.top();
		st.pop();
		visited.insert(node);
		res.push_back(node + 'A');
		for (const auto& ele : graph2[node])
		{
			if (visited.end() == visited.find(ele))
			{
				st.push(ele);
			}
		}
	}

	return res;
}

void DfsSearchTest()
{
	//std::vector<std::pair<char, char>> graph = { { 'A', 'B' }, { 'B', 'C' }, { 'C', 'D' }, { 'D', 'E' } };
	//char start = 'A'; // ['A', 'B', 'C', 'D', 'E']

	std::vector<std::pair<char, char>> graph = { { 'A', 'B' }, { 'A', 'C' }, { 'B', 'D' }, { 'B', 'E' }, { 'C', 'F' }, { 'E', 'F' } };
	char start = 'A'; // ['A', 'B', 'D', 'E', 'F', 'C']

	std::cout << "====================== DFS Search Test Start ======================" << std::endl;

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

	std::cout << "====================== DFS Search Test End ======================" << std::endl;
}
