
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <queue>
#include    <cmath>
#include    <unordered_set>
#include    <tuple>

static int solution1(std::vector<std::vector<int>> land, int height) {
    int answer = 0;

    const int size = land.size();
    std::vector<std::vector<int>> visit(size, std::vector<int>(size, 0));

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int setNum = size * y + x + 1;
            std::queue<std::pair<int, int>> q;
            q.push({ y, x });

            while (!q.empty())
            {
                auto [y, x] = q.front();
                q.pop();

                if (visit[y][x])
                {
                    continue;
                }

                visit[y][x] = setNum;

                if (0 < y && !visit[y - 1][x] && height >= std::abs(land[y][x] - land[y - 1][x]))
                {
                    q.push({ y - 1, x });
                }
                if (size > y + 1 && !visit[y + 1][x] && height >= std::abs(land[y][x] - land[y + 1][x]))
                {
                    q.push({ y + 1, x });
                }
                if (0 < x && !visit[y][x - 1] && height >= std::abs(land[y][x] - land[y][x - 1]))
                {
                    q.push({ y, x - 1 });
                }
                if (size > x + 1 && !visit[y][x + 1] && height >= std::abs(land[y][x] - land[y][x + 1]))
                {
                    q.push({ y, x + 1 });
                }
            }
        }
    }

    std::vector<int> parent(size * size + 1);
    std::function<int(int)> getParent = [&](int setNum) {
        if (setNum == parent[setNum])
        {
            return setNum;
        }

        return parent[setNum] = getParent(parent[setNum]);
        };

    std::unordered_set<int> setNums;
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> ladder;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int setNum = visit[y][x];
            setNums.insert(setNum);
            parent[setNum] = setNum;
            if (0 < y && setNum != visit[y - 1][x])
            {
                ladder.push({ std::abs(land[y][x] - land[y - 1][x]), setNum, visit[y - 1][x] });
            }
            if (size > y + 1 && setNum != visit[y + 1][x])
            {
                ladder.push({ std::abs(land[y][x] - land[y + 1][x]), setNum, visit[y + 1][x] });
            }
            if (0 < x && setNum != visit[y][x - 1])
            {
                ladder.push({ std::abs(land[y][x] - land[y][x - 1]), setNum, visit[y][x - 1] });
            }
            if (size > x + 1 && setNum != visit[y][x + 1])
            {
                ladder.push({ std::abs(land[y][x] - land[y][x + 1]), setNum, visit[y][x + 1] });
            }
        }
    }

    int totalLadderNums = 0;
    while (!ladder.empty())
    {
        auto [diff, setNum1, setNum2] = ladder.top();
        ladder.pop();

        if (getParent(setNum1) != getParent(setNum2))
        {
            answer += diff;
            parent[getParent(setNum1)] = setNum2;
            totalLadderNums++;
        }

        if (setNums.size() - 1 == totalLadderNums)
        {
            break;
        }
    }

    return answer;
}

static int solution2(std::vector<std::vector<int>> land, int height) {
    int answer = 0;

    const int size = land.size();
    std::vector<int> dir_y = { 0, 0, 1, -1 };
    std::vector<int> dir_x = { 1, -1, 0, 0 };
    std::vector<std::vector<bool>> visit(size, std::vector<bool>(size, false));
    auto isValid = [&](int y, int x) {
        return 0 <= y && size > y && 0 <= x && size > x && !visit[y][x];
        };

    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
    pq.push({ 0, 0, 0 });

    while (!pq.empty())
    {
        auto [cost, y, x] = pq.top();
        pq.pop();

        if (visit[y][x])
        {
            continue;
        }

        visit[y][x] = true;
        answer += cost;

        for (int i = 0; i < 4; ++i)
        {
            if (isValid(y + dir_y[i], x + dir_x[i]))
            {
                int diff = std::abs(land[y][x] - land[y + dir_y[i]][x + dir_x[i]]);
                if (height < diff)
                {
                    pq.push({ diff, y + dir_y[i], x + dir_x[i] });
                }
                else
                {
                    pq.push({ 0, y + dir_y[i], x + dir_x[i] });
                }
            }
        }
    }

    return answer;
}

void TopographyMovementTest()
{
    //std::vector<std::vector<int>> land = { {1, 4, 8, 10} ,{5, 5, 5, 5},{10, 10, 10, 10},{10, 10, 10, 20} };
    //int height = 3; // 15

    std::vector<std::vector<int>> land = { {10, 11, 10, 11} ,{2, 21, 20, 10},{1, 20, 21, 11},{2, 1, 2, 1} };
    int height = 1; // 18

    std::cout << "====================== Topography Movement Test Start ======================" << std::endl;

    std::cout << "Land : " << std::endl;
    for (const auto& ele : land)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "] " << std::endl;
    }
    std::cout << std::endl;

    auto res = solution2(land, height);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Topography Movement Test End ======================" << std::endl;
}
