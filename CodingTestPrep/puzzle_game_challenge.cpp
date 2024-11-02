
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>



static int solution1(std::vector<int> diffs, std::vector<int> times, long long limit) {

    const int size = diffs.size();

    int max = *std::max_element(diffs.begin(), diffs.end());

    int min = 1, level = (max + min) / 2;
    while (min < max)
    {
        long long duration = diffs[0] * times[0];

        for (int j = 1; j < size; ++j)
        {
            int diff = diffs[j];
            int time = times[j];

            if (diff <= level)
            {
                duration += time;
            }
            else
            {
                duration += (diff - level) * (time + times[j - 1]) + time;
            }
        }

        if (limit < duration)
        {
            min = level + 1;
        }
        else
        {
            max = level;
        }
        level = (max + min) / 2;
    }

    return max;
}

void PuzzleGameChallengeTest()
{
    //std::vector<int> diffs = { 1, 5, 3 };
    //std::vector<int> times = { 2, 4, 7 };
    //long long limit = 30; // 3

    //std::vector<int> diffs = { 1, 4, 4, 2 };
    //std::vector<int> times = { 6, 3, 8, 2 };
    //long long limit = 59; // 2

    //std::vector<int> diffs = { 1, 328, 467, 209, 54 };
    //std::vector<int> times = { 2, 7, 1, 4, 3 };
    //long long limit = 1723; // 294

    std::vector<int> diffs = { 1, 99999, 100000, 99995 };
    std::vector<int> times = { 9999, 9001, 9999, 9001 };
    long long limit = 3456789012; // 39354

    std::cout << "====================== Puzzle Game Challenge Test Start ======================" << std::endl;

    std::cout << "Diffs : [ ";
    for (const auto& ele : diffs)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Times : [ ";
    for (const auto& ele : times)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(diffs, times, limit);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Puzzle Game Challenge Test End ======================" << std::endl;
}
