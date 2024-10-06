
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(int n, std::vector<int> stations, int w)
{
    int answer = 0;

    int from = 1, to = -1;

    for (const auto& s : stations)
    {
        to = s - (w + 1);
        if (0 < to)
        {
            answer += std::ceil((double)(to - from + 1) / (w * 2 + 1));
        }

        from = s + w + 1;
    }

    if (n >= from)
    {
        to = n;
        answer += std::ceil((double)(to - from + 1) / (w * 2 + 1));
    }

    return answer;
}

void BaseStationTest()
{
    //int n = 11, w = 1;
    //std::vector<int> stations = { 4, 11 }; // 3

    int n = 16, w = 2;
    std::vector<int> stations = { 9 }; // 3

    std::cout << "====================== Base Station Test Start ======================" << std::endl;

    std::cout << "N : " << n << ", W : " << w << std::endl;
    std::cout << "Stations: [ ";
    for (const auto& ele : stations)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, stations, w);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Base Station Test End ======================" << std::endl;
}
