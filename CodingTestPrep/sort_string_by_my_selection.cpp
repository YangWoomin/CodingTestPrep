
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

static std::vector<std::string> solution1(std::vector<std::string> strings, int n)
{
	std::sort(strings.begin(), strings.end(), [&](auto& lhs, auto& rhs)
		{
			if (lhs[n] == rhs[n])
			{
                return lhs < rhs;
			}
            return lhs[n] < rhs[n];
		});

    return strings;
}

static std::vector<std::string> solution2(std::vector<std::string> strings, int n)
{
    auto comparator = [&](std::string& lhs, std::string& rhs) {
        if (lhs[n] == rhs[n]) {
            return lhs < rhs;
        }
        return lhs[n] < rhs[n];
        };

    std::function<void(int, int)> qsort = [&](int start, int end) {

        if (start >= end)
        {
            return;
        }

        auto pivot = strings[end];
        int s = start, e = end - 1;
        while (s <= e)
        {
            while (s <= e && comparator(strings[s], pivot))
            {
                s++;
            }
            while (s <= e && !comparator(strings[e], pivot))
            {
                e--;
            }

            if (s <= e)
            {
                std::swap(strings[s], strings[e]);
                s++;
                e--;
            }
        }

        std::swap(strings[s], strings[end]);
        qsort(start, s - 1);
        qsort(s + 1, end);
        };

    qsort(0, strings.size() - 1);

    return strings;
}

void SortStringByMySelectionTest()
{
    //std::vector<std::string> strings = { "sun", "bed", "car" }; // [ car bed sun ]
    //int n = 1;

    std::vector<std::string> strings = { "abce", "abcd", "cdx" }; // [ abcd abce cdx ]
    int n = 2;

    std::cout << "====================== Sort String By My Selection Test Start ======================" << std::endl;

    std::cout << "Strings : [ ";
    for (const auto& ele : strings)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(strings, n);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Sort String By My Selection Test End ======================" << std::endl;
}
