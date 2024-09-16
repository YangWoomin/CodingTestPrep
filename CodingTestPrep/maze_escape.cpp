
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include	<tuple>
#include	<queue>

static int GetLen(const std::vector<std::string>& maps, int s_y, int s_x, int d_y, int d_x)
{
    const int max_x = maps[0].size();
    const int max_y = maps.size();
    std::vector<std::vector<int>> visit(max_y, std::vector<int>(max_x));

    std::queue<std::tuple<int, int, int>> q;
    int len = 0;
    visit[s_y][s_x] = 1;
    q.push({ s_y, s_x, len });

    while (false == q.empty())
    {
        auto [y, x, l] = q.front();
        q.pop();

        if (d_y == y && d_x == x)
        {
            return l;
        }

        if (0 < x && !visit[y][x - 1])
        {
            if ('X' != maps[y][x - 1])
            {
                visit[y][x - 1] = 1;
                q.push({ y, x - 1, l + 1 });
            }
        }
        if (max_x > x + 1 && !visit[y][x + 1])
        {
            if ('X' != maps[y][x + 1])
            {
                visit[y][x + 1] = 1;
                q.push({ y, x + 1, l + 1 });
            }
        }
        if (0 < y && !visit[y - 1][x])
        {
            if ('X' != maps[y - 1][x])
            {
                visit[y - 1][x] = 1;
                q.push({ y - 1, x, l + 1 });
            }
        }
        if (max_y > y + 1 && !visit[y + 1][x])
        {
            if ('X' != maps[y + 1][x])
            {
                visit[y + 1][x] = 1;
                q.push({ y + 1, x, l + 1 });
            }
        }
    }

    return -1;
}

static int solution1(std::vector<std::string>& maps) {

    int s_x = -1, s_y = -1, l_x = -1, l_y = -1, e_x = -1, e_y = -1;
    for (int i = 0; i < maps.size(); ++i)
    {
        auto idx = maps[i].find('S');
        if (std::string::npos != idx)
        {
            s_x = idx;
            s_y = i;
        }

        idx = maps[i].find('L');
        if (std::string::npos != idx)
        {
            l_x = idx;
            l_y = i;
        }

        idx = maps[i].find('E');
        if (std::string::npos != idx)
        {
            e_x = idx;
            e_y = i;
        }
    }

    int toLever = GetLen(maps, s_y, s_x, l_y, l_x);
    if (-1 == toLever)
    {
        return toLever;
    }

    int toExit = GetLen(maps, l_y, l_x, e_y, e_x);
    if (-1 == toExit)
    {
        return toExit;
    }

    return toLever + toExit;
}

void MazeEscapeTest()
{
    std::vector<std::string> maps = { "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" }; // 16
    //std::vector<std::string> maps = { "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" }; // -1

	std::cout << "====================== Maze Escape Test Start ======================" << std::endl;

	std::cout << "Maps : " << std::endl;
	for (const auto& ele : maps)
	{
        std::cout << "\t" << ele << std::endl;
	}
	std::cout << std::endl;

	auto res = solution1(maps);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Maze Escape Test Start ======================" << std::endl;
}
