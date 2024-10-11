
#include	"tree_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

struct BT
{
	int _value = 0;
	BT* _left = nullptr;
	BT* _right = nullptr;

	~BT()
	{
		if (nullptr != _left)
		{
			delete _left;
			_left = nullptr;
		}

		if (nullptr != _right)
		{
			delete _right;
			_right = nullptr;
		}
	}

	void insert(int val)
	{
		if (0 == _value)
		{
			_value = val;
			return;
		}

		if (val < _value)
		{
			if (nullptr == _left)
			{
				_left = new BT();
			}
			_left->insert(val);
		}
		else
		{
			if (nullptr == _right)
			{
				_right = new BT();
			}
			_right->insert(val);
		}
	}

	bool search(int val)
	{
		if (_value == val)
		{
			return true;
		}

		if (val < _value && nullptr != _left)
		{
			return _left->search(val);
		}
		else if (_value < val && nullptr != _right)
		{
			return _right->search(val);
		}

		return false;
	}
};

static std::vector<bool> solution1(std::vector<int> lst, std::vector<int> search_lst)
{
	std::vector<bool> res;

	BT* root = new BT();
	
	for (const auto& ele : lst)
	{
		root->insert(ele);
	}

	for (const auto& ele : search_lst)
	{
		res.push_back(root->search(ele));
	}

	delete root;

	return res;
}

void BinarySearchImplTest()
{
	//std::vector<int> lst = { 5, 3, 8, 4, 2, 1, 7, 10 };
	//std::vector<int> search_lst = { 1, 2, 5, 6 }; // [1, 1, 1, 0]

	std::vector<int> lst = { 1, 3, 5, 7, 9 };
	std::vector<int> search_lst = { 2, 4, 6, 8, 10 }; // [0, 0, 0, 0, 0]

	std::cout << "List : [ ";
	for (const auto& ele : lst)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Search List : [ ";
	for (const auto& ele : search_lst)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(lst, search_lst);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;
}
