
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include <tuple>
#include <unordered_map>

static int solution1(std::vector<std::vector<int>> points, std::vector<std::vector<int>> routes) {
    int answer = 0;

    const int size = routes.size();

    std::vector<std::tuple<int, int, int, int>> current;
    for (int i = 0; i < size; ++i)
    {
        int point = routes[i][0] - 1;
        int y = points[point][0];
        int x = points[point][1];
        current.push_back({ y, x, i, 1 });
    }

    int complete = 0;
    while (complete < size)
    {
        std::unordered_map<int, std::unordered_map<int, int>> map;
        for (auto cit = current.begin(); cit != current.end();)
        {
            int cy = std::get<0>(*cit);
            int cx = std::get<1>(*cit);
            map[cy][cx]++;
            if (2 == map[cy][cx])
            {
                answer++;
            }

            int me = std::get<2>(*cit);
            int& dest = std::get<3>(*cit);
            int point = routes[me][dest] - 1;
            int dy = points[point][0];
            int dx = points[point][1];
            if (dy == cy && dx == cx)
            {
                dest++;
                if (routes[me].size() == dest)
                {
                    cit = current.erase(cit);
                    complete++;
                    continue;
                }
            }
            cit++;
        }

        for (auto cit = current.begin(); cit != current.end(); ++cit)
        {
            int& cy = std::get<0>(*cit);
            int& cx = std::get<1>(*cit);
            int me = std::get<2>(*cit);
            int dest = std::get<3>(*cit);
            int point = routes[me][dest] - 1;
            int dy = points[point][0];
            int dx = points[point][1];

            if (dy > cy)
            {
                cy++;
            }
            else if (dy < cy)
            {
                cy--;
            }
            else if (dx > cx)
            {
                cx++;
            }
            else if (dx < cx)
            {
                cx--;
            }
        }
    }

    return answer;
}

void FindingCollisionRiskTest()
{
    //std::vector<std::vector<int>> points = { {3, 2} ,{6, 4},{4, 7},{1, 4} };
    //std::vector<std::vector<int>> routes = { {4, 2} ,{1, 3},{2, 4} }; // 1

    //std::vector<std::vector<int>> points = { {3, 2} ,{6, 4},{4, 7},{1, 4} };
    //std::vector<std::vector<int>> routes = { {4, 2} ,{1, 3},{4, 2},{4, 3} }; // 9

    std::vector<std::vector<int>> points = { {2, 2} ,{2, 3},{2, 7},{6, 6},{5, 2 } };
    std::vector<std::vector<int>> routes = { {2, 3, 4, 5} ,{1, 3, 4, 5} }; // 0

    std::cout << "====================== Finding Collision Risk Test Start ======================" << std::endl;

    std::cout << "Points : [ ";
    for (const auto& ele : points)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Routes : " << std::endl;
    for (const auto& ele : routes)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(points, routes);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Finding Collision Risk Test End ======================" << std::endl;
}
