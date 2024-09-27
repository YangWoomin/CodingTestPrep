
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static std::vector<int> solution1(std::vector<int> arr)
{

    std::function<void(int, int)> heapify = [&](int idx, int size)
        {
            if (idx > size / 2 - 1)
            {
                return;
            }

            int* left = idx * 2 + 1 < size ? &(arr[idx * 2 + 1]) : nullptr;
            int* right = idx * 2 + 2 < size ? &(arr[idx * 2 + 2]) : nullptr;
            int* max = left;
            int nidx = idx * 2 + 1;
            if (max && right)
            {
                max = *max > *right ? max : right;
                nidx = max == left ? idx * 2 + 1 : idx * 2 + 2;
            }
            if (max && *max > arr[idx])
            {
                std::swap(arr[idx], *max);
                heapify(nidx, size);
            }
        };

    for (int i = arr.size() / 2 - 1; i >= 0; --i)
    {
        heapify(i, arr.size());
    }

    int i = arr.size() - 1;
    while (0 < i)
    {
        std::swap(arr[0], arr[i]);
        heapify(0, i);
        i--;
    }

    return arr;
}

void HeapSortTest()
{
    std::vector<int> arr = { 51, 11, 32, 60, 56, 9 }; // [9 11 32 51 56 60]
    //std::vector<int> arr = { 56, 9 }; // [9, 56]
    //std::vector<int> arr = { 9 }; // [9]

    std::cout << "====================== Heap Sort Test Start ======================" << std::endl;

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

    std::cout << "====================== Heap Sort Test Start ======================" << std::endl;
}
