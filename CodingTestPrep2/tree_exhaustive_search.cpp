
#include	"tree_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<std::string> solution1(std::vector<int> nodes)
{
	std::string pre;
	std::function<void(int)> preorder = [&](int idx) {
		if (pre.size())
		{
			pre += " ";
		}
		pre += std::to_string(nodes[idx]);

		if (idx * 2 + 1 < nodes.size())
		{
			preorder(idx * 2 + 1);
		}

		if (idx * 2 + 2 < nodes.size())
		{
			preorder(idx * 2 + 2);
		}
	};
	preorder(0);

	std::string in;
	std::function<void(int)> inorder = [&](int idx) {
		if (idx * 2 + 1 < nodes.size())
		{
			inorder(idx * 2 + 1);
		}
		
		if (in.size())
		{
			in += " ";
		}
		in += std::to_string(nodes[idx]);

		if (idx * 2 + 2 < nodes.size())
		{
			inorder(idx * 2 + 2);
		}
	};
	inorder(0);

	std::string post;
	std::function<void(int)> postorder = [&](int idx) {
		if (idx * 2 + 1 < nodes.size())
		{
			postorder(idx * 2 + 1);
		}

		if (idx * 2 + 2 < nodes.size())
		{
			postorder(idx * 2 + 2);
		}

		if (post.size())
		{
			post += " ";
		}
		post += std::to_string(nodes[idx]);
	};
	postorder(0);

	return { pre, in, post };
}

void TreeExhaustiveSearchTest()
{
	std::vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 }; // ["1 2 4 5 3 6 7", "4 2 5 1 6 3 7", "4 5 2 6 7 3 1"]

	std::cout << "Nodes : [ ";
	for (const auto& ele : nodes)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(nodes);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << "[ " << ele << " ] ";
	}
	std::cout << "]" << std::endl;
}
