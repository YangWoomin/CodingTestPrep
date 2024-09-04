
#include	"tests.h"

#include	<iostream>
#include	<vector>
#include	<map>
#include	<algorithm>

static std::vector<std::vector<int>> solution1(const std::vector<std::vector<int>>& arr1, const std::vector<std::vector<int>>& arr2)
{
	std::vector<std::vector<int>> res(arr1.size(), std::vector<int>(arr2[0].size()));

	for (auto i = 0; i < arr1.size(); ++i)
	{
		for (auto j = 0; j < arr2[0].size(); ++j)
		{
			for (auto k = 0; k < arr2.size(); ++k)
			{
				res[i][j] += (arr1[i][k] * arr2[k][j]);
			}
		}
	}

	return res;
}

void ArrayMultiplyTest()
{
	/*std::vector<std::vector<int>> arr1 = { {1, 4}, {3, 2}, {4, 1} };
	std::vector<std::vector<int>> arr2 = { {3, 3}, {3, 3} };*/

	std::vector<std::vector<int>> arr1 = { {2, 3, 2}, {4, 2, 4}, {3, 1, 4} };
	std::vector<std::vector<int>> arr2 = { {5, 4, 3}, {2, 4, 1}, {3, 1, 1} };
	
	std::cout << "====================== Array Multiply Test Start ======================" << std::endl;

	std::cout << "Test Matrix 1 : [ ";
	for (auto i = 0; i < arr1.size(); ++i)
	{
		std::cout << "[ ";
		for (auto j = 0; j < arr1[i].size(); ++j)
		{
			std::cout << arr1[i][j];

			if (j < arr1[i].size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << " ]";

		if (i < arr1.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;

	std::cout << "Test Matrix 2 : [ ";
	for (auto i = 0; i < arr2.size(); ++i)
	{
		std::cout << "[ ";
		for (auto j = 0; j < arr2[i].size(); ++j)
		{
			std::cout << arr2[i][j];

			if (j < arr2[i].size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << " ]";

		if (i < arr2.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;

	std::vector<std::vector<int>> res = solution1(arr1, arr2);
	std::cout << "Result Matrix : [ ";
	for (auto i = 0; i < res.size(); ++i)
	{
		std::cout << "[ ";
		for (auto j = 0; j < res[i].size(); ++j)
		{
			std::cout << res[i][j];

			if (j < res[i].size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << " ]";

		if (i < res.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;

	std::cout << "====================== Array Multiply Test End ======================" << std::endl;
}
