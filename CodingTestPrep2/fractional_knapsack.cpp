
#include	"greedy_test.h"

#include	<iostream>

#include	<string>
#include	<vector>
#include	<algorithm>

static double solution1(std::vector<std::vector<int>> items, int weight_limit)
{
    double answer = 0.f;

    std::vector<std::pair<double, int>> values;
    for (const auto& ele : items)
    {
        values.push_back({ (double)ele[1] / ele[0], ele[0] });
    }

    std::sort(values.begin(), values.end(), [](auto& lhs, auto& rhs) {
        return lhs.first > rhs.first;
    });

    for (const auto& [value, weight] : values)
    {
        if (0 < weight_limit)
        {
            int w = weight_limit >= weight ? weight : weight_limit;
            answer += value * w;
            weight_limit -= w;
        }
        else
        {
            break;
        }
    }

    return answer;
}

void FractionalKnapsackTest()
{
    std::vector<std::vector<int>> items = { {10, 19}, {7, 10}, {6, 10} };
    int weight_limit = 15;

    std::cout << "Items : [ ";
    for (const auto& ele : items)
    {
        std::cout << "[ " << ele[0] << " " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(items, weight_limit);

    std::cout << "Result : " << res << std::endl;
}
