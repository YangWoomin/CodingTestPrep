
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

		int mid = (start + end) / 2;
		sort(start, mid);
		sort(mid + 1, end);

		std::vector<int> tmp;
		int i = start, j = mid + 1;
		while (i <= mid && j <= end)
		{
			if (arr[i] <= arr[j])
			{
				tmp.push_back(arr[i]);
				i++;
			}
			else
			{
				tmp.push_back(arr[j]);
				j++;
			}
		}

		while (i <= mid)
		{
			tmp.push_back(arr[i]);
			i++;
		}

		while (j <= end)
		{
			tmp.push_back(arr[j]);
			j++;
		}

		for (int i = 0; i < tmp.size(); ++i)
		{
			arr[start + i] = tmp[i];
		}
	};

	sort(0, arr.size() - 1);

	return arr;
}

void MergeSortTest()
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
