
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

#include    <queue>

// bfs (time over)
static int solution1(int m, int n, std::vector<std::vector<int>> puddles) {

    std::vector<std::vector<int>> trap(m + 1, std::vector<int>(n + 1));
    for (const auto& ele : puddles)
    {
        trap[ele[0]][ele[1]] = 1;
    }

    std::vector<std::vector<int>> visit(m + 1, std::vector<int>(n + 1));
    std::queue<std::pair<int, int>> q;
    q.push({ 1, 1 });

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        visit[x][y]++;

        if (x < m && !trap[x + 1][y])
        {
            q.push({ x + 1, y });
        }
        if (y < n && !trap[x][y + 1])
        {
            q.push({ x, y + 1 });
        }
    }

    return visit[m][n];
}

// dp
static int solution2(int m, int n, std::vector<std::vector<int>> puddles) {

    std::vector<std::vector<int>> trap(m + 1, std::vector<int>(n + 1));
    for (const auto& ele : puddles)
    {
        trap[ele[0]][ele[1]] = 1;
    }

    std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1));
    dp[1][1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (trap[j][i])
            {
                continue;
            }

            if (1 < i)
            {
                dp[j][i] = (dp[j][i] + dp[j][i - 1]) % 1000000007;
            }
            if (1 < j)
            {
                dp[j][i] = (dp[j][i] + dp[j - 1][i]) % 1000000007;
            }
        }
    }

    return dp[m][n];
}

void WayToSchoolTest()
{
    int m = 4, n = 3;
    std::vector<std::vector<int>> puddles = { {2,2} }; // 4

    std::cout << "====================== Way To School Test Start ======================" << std::endl;

    std::cout << "M : " << m << ", N : " << n << std::endl;
    std::cout << "Puddles: [ ";
    for (const auto& ele : puddles)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(m, n, puddles);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Way To School Test End ======================" << std::endl;
}
