
#include	"set_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<bool> solution1(int k, std::vector<std::vector<char>> operations)
{
	std::vector<bool> res;

	std::vector<int> p(k + 1);
	for (int i = 1; i <= k; ++i)
	{
		p[i] = i;
	}

	std::function<int(int)> getParent = [&](int idx) -> int {
		if (p[idx] == idx)
		{
			return idx;
		}

		return p[idx] = getParent(p[idx]);
	};

	std::vector<int> rank(k + 1);
	std::function<void(int, int)> merge = [&](int node1, int node2) {
		int root1 = getParent(node1);
		int root2 = getParent(node2);

		if (root1 != root2)
		{
			if (rank[root1] > rank[root2])
			{
				p[root2] = root1;
			}
			else
			{
				if (rank[root1] == rank[root2])
				{
					rank[root2]++;
				}
				p[root1] = root2;
			}
		}
	};

	for (const auto& ele : operations)
	{
		char cmd = ele[0];
		int node1 = ele[1] - '0';
		int node2 = ele[2] - '0';

		if ('u' == cmd)
		{
			merge(node1, node2);
		}
		else // 'f'
		{
			res.push_back(getParent(node1) == getParent(node2));
		}
	}

	return res;
}

void SimpleUnionFindTest()
{
	//int k = 3;
	//std::vector<std::vector<char>> operations = { {'u', '0', '1'}, {'u', '1', '2'},{'f', '0', '2'} }; // [1]

	int k = 4;
	std::vector<std::vector<char>> operations = { {'u', '0', '1'}, {'u', '2', '3'}, {'f', '0', '1'}, {'f', '0', '2'} }; // [1, 0]

	std::cout << "Operations : [ ";
	for (const auto& ele : operations)
	{
		std::cout << "[ " << ele[0] << " " << ele[1] << " " << ele[2] << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(k, operations);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
