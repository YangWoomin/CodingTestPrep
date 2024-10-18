
#include	"sort_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

#include	<functional>

static std::vector<int> solution1(std::vector<int> arr)
{
	std::function<void(int, const int)> heapify = [&](int idx, const int size) {
		
		int max = arr[idx];
		int next = idx;
		if (idx * 2 + 1 < size && max < arr[idx * 2 + 1])
		{
			max = arr[idx * 2 + 1];
			next = idx * 2 + 1;
		}
		if (idx * 2 + 2 < size && max < arr[idx * 2 + 2])
		{
			max = arr[idx * 2 + 2];
			next = idx * 2 + 2;
		}

		if (next != idx)
		{
			std::swap(arr[idx], arr[next]);
			heapify(next, size);
		}
	};

	for (int i = arr.size() / 2 - 1; i >= 0; --i)
	{
		heapify(i, arr.size());
	}

	for (int i = 1; i < arr.size(); ++i)
	{
		int next = arr.size() - i;
		std::swap(arr[0], arr[next]);
		heapify(0, next);
	}

	return arr;
}

void HeapSortTest()
{
	std::vector<int> arr = { 5, 2, 9, 23, 51, 33, 10, 1, 4 };

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
