
#include	"tree_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

static long long solution1(int n, std::vector<int> times) {
    long long answer = 0;

    std::sort(times.begin(), times.end());

    const int size = times.size();
    long long min = (long long)times[0] * 1;
    long long max = (long long)times[size - 1] * n;

    while (min <= max)
    {
        long long pivot = (min + max) / 2;
        long long total = 0;
        for (const auto& ele : times)
        {
            total += pivot / ele;
        }
        if (total >= n)
        {
            answer = pivot;
            max = pivot - 1;
        }
        else
        {
            min = pivot + 1;
        }
    }

    return answer;
}

void ImmigrationInspectionTest()
{
    int n = 6;
    std::vector<int> times = { 7, 10 }; // 28

    std::cout << "====================== Immigration Inspection Test Start ======================" << std::endl;

    std::cout << "Number : " << n << std::endl;
    std::cout << "Times : [ ";
    for (const auto& ele : times)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, times);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Immigration Inspection Test End ======================" << std::endl;
}
