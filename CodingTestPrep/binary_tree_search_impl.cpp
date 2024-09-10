
#include	"tree_test.h"

#include	<iostream>
#include	<vector>
#include	<string>
#include	<cmath>

struct Node
{
	int		_value = 0;
	Node*	_left = nullptr;
	Node*	_right = nullptr;

	void Insert(int value)
	{
		if (0 == _value)
		{
			_value = value;
			return;
		}

		if (value < _value)
		{
			if (nullptr == _left)
			{
				_left = new Node();
			}
			_left->Insert(value);
		}
		else
		{
			if (nullptr == _right)
			{
				_right = new Node();
			}
			_right->Insert(value);
		}
	}

	bool Search(int value)
	{
		if (_value == value)
		{
			return true;
		}

		if (value < _value && nullptr != _left)
		{
			return _left->Search(value);
		}
		else if (value >= _value && nullptr != _right)
		{
			return _right->Search(value);
		}

		return false;
	}

	void Delete()
	{
		if (nullptr != _left)
		{
			_left->Delete();
			delete _left;
			_left = nullptr;
		}

		if (nullptr != _right)
		{
			_right->Delete();
			delete _right;
			_right = nullptr;
		}
	}
};

static std::vector<bool> solution1(std::vector<int> lst, std::vector<int> search_lst)
{
	std::vector<bool> res;

	Node* root = new Node();

	for (const auto& ele : lst)
	{
		root->Insert(ele);
	}

	for (const auto& ele : search_lst)
	{
		res.push_back(root->Search(ele));
	}

	root->Delete();
	delete root;

	return res;
}

void BinaryTreeSearchImplTest()
{
	std::vector<int> nodes = { 5, 3, 8, 4, 2, 1, 7, 10 };
	std::vector<int> search = { 1, 2, 5, 6 }; // [1, 1, 1, 0]

	//std::vector<int> nodes = { 1, 3, 5, 7, 9 };
	//std::vector<int> search = { 2, 4, 6, 8, 10 }; // [0, 0, 0, 0, 0]

	std::cout << "====================== Binary Tree Search Impl Test Start ======================" << std::endl;

	std::cout << "Nodes : [ ";
	for (const auto& ele : nodes)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Search : [ ";
	for (const auto& ele : search)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(nodes, search);
	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "====================== Binary Tree Search Impl Test End ======================" << std::endl;
}
