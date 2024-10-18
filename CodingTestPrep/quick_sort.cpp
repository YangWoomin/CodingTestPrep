
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

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
    std::vector<int> arr = { 51, 11, 32, 60, 56, 9 }; // [9 11 32 51 56 60]
    //std::vector<int> arr = { 56, 9 }; // [9, 56]
    //std::vector<int> arr = { 9 }; // [9]

    std::cout << "====================== Quick Sort Test Start ======================" << std::endl;

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

    std::cout << "====================== Quick Sort Test End ======================" << std::endl;
}
