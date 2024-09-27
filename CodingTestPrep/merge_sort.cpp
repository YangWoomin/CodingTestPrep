
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static std::vector<int> solution1(std::vector<int> arr)
{
    std::function<void(int, int)> sort = [&](int start, int end)
        {
            if (start >= end)
            {
                return;
            }

            int mid = start + (end - start) / 2;
            sort(start, mid);
            sort(mid + 1, end);

            std::vector<int> tmp;
            int i = start, j = mid + 1;
            while (i <= mid && j <= end)
            {
                if (arr[i] < arr[j])
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

            for (i = 0; i < tmp.size(); ++i)
            {
                arr[start + i] = tmp[i];
            }
        };

    sort(0, arr.size() - 1);

    return arr;
}

void MergeSortTest()
{
    std::vector<int> arr = { 51, 11, 32, 60, 56, 9 }; // [9 11 32 51 56 60]
    //std::vector<int> arr = { 56, 9 }; // [9, 56]
    //std::vector<int> arr = { 9 }; // [9]

    std::cout << "====================== Merge Sort Test Start ======================" << std::endl;

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

    std::cout << "====================== Merge Sort Test Start ======================" << std::endl;
}

