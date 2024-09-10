
#include	"tree_test.h"

#include	<iostream>
#include	<vector>
#include	<string>
#include	<stack>

void genPreorder(const std::vector<int>& nodes, int i, std::string& output)
{
	if (nodes.size() > i)
	{
		output += std::to_string(nodes[i]) + " ";
	}

	if (i * 2 + 1 < nodes.size())
	{
		genPreorder(nodes, i * 2 + 1, output);
	}

	if (i * 2 + 2 < nodes.size())
	{
		genPreorder(nodes, i * 2 + 2, output);
	}
}

void genInorder(const std::vector<int>& nodes, int i, std::string& output)
{
	if (i * 2 + 1 < nodes.size())
	{
		genInorder(nodes, i * 2 + 1, output);
	}

	if (nodes.size() > i)
	{
		output += std::to_string(nodes[i]) + " ";
	}

	if (i * 2 + 2 < nodes.size())
	{
		genInorder(nodes, i * 2 + 2, output);
	}
}

void genPostorder(const std::vector<int>& nodes, int i, std::string& output)
{
	if (i * 2 + 1 < nodes.size())
	{
		genPostorder(nodes, i * 2 + 1, output);
	}

	if (i * 2 + 2 < nodes.size())
	{
		genPostorder(nodes, i * 2 + 2, output);
	}

	if (nodes.size() > i)
	{
		output += std::to_string(nodes[i]) + " ";
	}
}

static std::vector<std::string> solution1(std::vector<int> nodes)
{
	std::stack<int> st;
	std::string preorder;
	
	//genPreorder(nodes, 0, preorder);
	
	int i = 0;
	while (nodes.size() > i)
	{
		preorder += std::to_string(nodes[i]) + " ";
		if (i * 2 + 2 < nodes.size())
		{
			st.push(i * 2 + 2);
		}
		if (i * 2 + 1 < nodes.size())
		{
			i = i * 2 + 1;
		}
		else
		{
			if (st.empty())
			{
				break;
			}
			else
			{
				i = st.top();
				st.pop();
			}
		}
	}

	std::string inorder;
	genInorder(nodes, 0, inorder);

	std::string postorder;
	genPostorder(nodes, 0, postorder);

	return { preorder, inorder, postorder };
}

void TreeSearchTest()
{
	std::vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 };

	std::cout << "====================== Tree Search Test Start ======================" << std::endl;

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
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "====================== Tree Search Test End ======================" << std::endl;
}
