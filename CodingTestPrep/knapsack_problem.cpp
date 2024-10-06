
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

#include    <queue>

// greedy
static double solution1(std::vector<std::vector<int>> items, int limit)
{
    double answer = 0;

    std::priority_queue<std::pair<double, int>> pq;
    for (const auto& ele : items)
    {
        pq.push({ (double)ele[1] / ele[0], ele[0] });
    }

    while (0 < limit && !pq.empty())
    {
        auto [value, weight] = pq.top();
        pq.pop();

        if (limit < weight)
        {
            weight = limit;
        }

        answer += weight * value;
        limit -= weight;
    }

    return answer;
}

// dp 1
static int solution2(std::vector<std::vector<int>> items, int limit)
{
    int answer = 0;

    const int size = items.size();

    std::vector<std::vector<int>> dp(size + 1, std::vector<int>(limit + 1));

    for (int i = 1; i <= size; ++i)
    {
        int w = items[i - 1][0], v = items[i - 1][1];
        for (int j = w; j <= limit; ++j)
        {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
    }

    return dp[size][limit];
}

// dp 2
static int solution3(std::vector<std::vector<int>> items, int limit)
{
    int answer = 0;

    const int size = items.size();

    std::vector<int> dp(limit + 1);

    for (int i = 1; i <= size; ++i)
    {
        int w = items[i - 1][0], v = items[i - 1][1];
        for (int j = limit; j >= w; --j)
        {
            dp[j] = std::max(dp[j], dp[j - w] + v);
        }
    }

    return dp[limit];
}

void KnapsackProblemTest()
{
    //std::vector<std::vector<int>> items = { {10,19}, {7,10}, {6,10} };
    //int limit = 15; // 27.33 (partial knapsack), 20 (0/1 kapsack)

    std::vector<std::vector<int>> items = { {10,60}, {20,100}, {30,120} };
    int limit = 50; // 240 (partial knapsack), 220 (0/1 kapsack)

    std::cout << "====================== Kapsack Problem Test Start ======================" << std::endl;

    std::cout << "Items: [ ";
    for (const auto& ele : items)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Weigth Limit : " << limit << std::endl;

    auto res = solution3(items, limit);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Kapsack Problem Test End ======================" << std::endl;
}
