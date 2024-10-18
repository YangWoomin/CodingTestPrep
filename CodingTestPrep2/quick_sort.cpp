
#include	"sort_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<int> solution1(std::vector<int> arr)
{
	std::function<void(int, int)> sort = [&](int start, int end) {

		if (start >= end)
		{
			return;
		}

		int& pivot = arr[end];
		int s = start, e = end - 1;
		while (s <= e)
		{
			while (s < end && arr[s] <= pivot)
			{
				s++;
			}

			while (e >= start && arr[e] >= pivot)
			{
				e--;
			}

			if (s <= e)
			{
				std::swap(arr[s], arr[e]);
				s++; 
				e--;
			}
		}

		std::swap(arr[s], pivot);
		sort(start, s - 1);
		sort(s + 1, end);
	};

	sort(0, arr.size() - 1);

	return arr;
}

void QuickSortTest()
{
	//std::vector<int> arr = { 5, 2, 9, 23, 51, 33, 10, 1, 4 };
	//std::vector<int> arr = { 3, 6, 2, 8, 7, 1, 5 };
	//std::vector<int> arr = { 3, 6, 2, 4, 7, 1, 5 };
	std::vector<int> arr = { 3, 6, 2, 5, 5, 5, 7, 1, 5 };
	//std::vector<int> arr = { 1, 2, 3 };
	//std::vector<int> arr = { 3, 2, 1 };

	std::cout << "Array : [ ";
	for (const auto& ele : arr)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	auto res = solution1(arr);

	std::cout << "Result : [ ";
	for (const auto& ele : res)
	{
		std::cout << ele << " ";
	}
	std::cout << "]" << std::endl;

	std::sort(arr.begin(), arr.end());

	if (arr == res)
	{
		std::cout << "The result is same as std::sort" << std::endl;
	}
	else
	{
		std::cout << "The result is different with std::sort" << std::endl;
		std::cout << "Correct result : [ ";
		for (const auto& ele : arr)
		{
			std::cout << ele << " ";
		}
		std::cout << "]" << std::endl;
	}
}
