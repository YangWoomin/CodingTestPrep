
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <climits>
#include    <queue>

// dfs, timeout
static int solution1(std::vector<std::vector<int>> board) {
    int answer = INT_MAX;

    std::vector<std::vector<bool>> visited(board.size(), std::vector<bool>(board.size(), false));
    std::function<void(const int, int, int, int, int, int, std::vector<std::vector<bool>>)> dfs;
    dfs = [&board, &answer, &dfs](const int max, int p_y, int p_x, int y, int x, int total, std::vector<std::vector<bool>> visited) {
        if (max == y && max == x)
        {
            if (total < answer)
            {
                answer = total;
            }
            return;
        }

        if (max < y || max < x || 0 > y || 0 > x
            || 1 == board[y][x] || true == visited[y][x])
        {
            return;
        }

        if (answer <= total)
        {
            return;
        }

        visited[y][x] = true;

        dfs(max, y, x, y + 1, x, total + ((p_x + 1 == x || p_x - 1 == x) ? 600 : 100), visited);
        dfs(max, y, x, y, x + 1, total + ((p_y + 1 == y || p_y - 1 == y) ? 600 : 100), visited);
        dfs(max, y, x, y - 1, x, total + ((p_x + 1 == x || p_x - 1 == x) ? 600 : 100), visited);
        dfs(max, y, x, y, x - 1, total + ((p_y + 1 == y || p_y - 1 == y) ? 600 : 100), visited);
        };

    dfs(board.size() - 1, 0, 0, 0, 0, 0, visited);

    return answer;
}

// bfs, this solution can be passed correctly within the problem's all test cases but I think this way is tricky
static int solution2(std::vector<std::vector<int>> board) {

    const int size = board.size();
    std::vector<std::vector<int>> cost(size, std::vector<int>(size, INT_MAX));

    std::queue<std::tuple<int, int, int, int, int>> q;
    q.push({ 0, 0, 0, 0, 0 });

    while (false == q.empty())
    {
        auto [p_y, p_x, y, x, total] = q.front();
        q.pop();

        if (INT_MAX == cost[y][x])
        {
            cost[y][x] = total;
        }
        else
        {
            // allow up to just one cornering cost(500)
            if (total > cost[y][x] + 500)
            {
                continue;
            }
            else
            {
                if (total < cost[y][x])
                {
                    cost[y][x] = total;
                }
            }
        }

        if (y == size - 1 && x == size - 1)
        {
            continue;
        }

        if (0 < y && 1 != board[y - 1][x])
        {
            int sum = total + (p_x + 1 == x || p_x - 1 == x ? 600 : 100);
            q.push({ y, x, y - 1, x, sum });
        }

        if (y + 1 < size && 1 != board[y + 1][x])
        {
            int sum = total + (p_x + 1 == x || p_x - 1 == x ? 600 : 100);
            q.push({ y, x, y + 1, x, sum });
        }

        if (0 < x && 1 != board[y][x - 1])
        {
            int sum = total + (p_y + 1 == y || p_y - 1 == y ? 600 : 100);
            q.push({ y, x, y, x - 1, sum });
        }

        if (x + 1 < size && 1 != board[y][x + 1])
        {
            int sum = total + (p_y + 1 == y || p_y - 1 == y ? 600 : 100);
            q.push({ y, x, y, x + 1, sum });
        }
    }

    return cost[size - 1][size - 1];
}

// bfs, correct way with direction
static int solution3(std::vector<std::vector<int>> board) {

    const int size = board.size();
    std::vector<std::vector<std::vector<int>>> cost(size, std::vector<std::vector<int>>(size, std::vector<int>(4, INT_MAX)));
    cost[0][0] = { 0, 0, 0, 0 };

    std::queue<std::tuple<int, int, int, int>> q;
    q.push({ 0, 0, -1, 0 });

    while (false == q.empty())
    {
        auto [y, x, dir, total] = q.front();
        q.pop();

        if (0 <= dir)
        {
            if (total <= cost[y][x][dir])
            {
                cost[y][x][dir] = total;
            }
            else
            {
                continue;
            }
        }

        if (y == size - 1 && x == size - 1)
        {
            continue;
        }

        if (0 < y && 1 != board[y - 1][x])
        {
            int sum = total + (dir == -1 || dir == 0 ? 100 : 600);
            if (1 != dir && sum <= cost[y - 1][x][0])
            {
                q.push({ y - 1, x, 0, sum });
            }
        }

        if (y + 1 < size && 1 != board[y + 1][x])
        {
            int sum = total + (dir == -1 || dir == 1 ? 100 : 600);
            if (0 != dir && sum <= cost[y + 1][x][1])
            {
                q.push({ y + 1, x, 1, sum });
            }
        }

        if (0 < x && 1 != board[y][x - 1])
        {
            int sum = total + (dir == -1 || dir == 2 ? 100 : 600);
            if (3 != dir && sum <= cost[y][x - 1][2])
            {
                q.push({ y, x - 1, 2, sum });
            }
        }

        if (x + 1 < size && 1 != board[y][x + 1])
        {
            int sum = total + (dir == -1 || dir == 3 ? 100 : 600);
            if (2 != dir && sum <= cost[y][x + 1][3])
            {
                q.push({ y, x + 1, 3, sum });
            }
        }
    }

    int answer = INT_MAX;

    for (const auto& ele : cost[size - 1][size - 1])
    {
        if (ele < answer)
        {
            answer = ele;
        }
    }

    return answer;
}

void TrackConstructionTest()
{
    //std::vector<std::vector<int>> board = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } }; // 900
    //std::vector<std::vector<int>> board = { {0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0} }; // 3800
    std::vector<std::vector<int>> board = { {0,0,1,0} ,{0,0,0,0},{0,1,0,1},{1,0,0,0} }; // 2100
    //std::vector<std::vector<int>> board = { {0,0,0,0,0,0} ,{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,1},{0,1,0,0,0,1},{0,0,0,0,0,0} }; // 3200
    //std::vector<std::vector<int>> board = { {0, 0, 0, 0, 0} ,{0, 1, 1, 1, 0},{0, 0, 1, 0, 0},{1, 0, 0, 0, 1},{1, 1, 1, 0, 0} }; // 3000

	std::cout << "====================== Track Construction Test Start ======================" << std::endl;

	std::cout << "Board : [ ";
	for (const auto& ele : board)
	{
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution3(board);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Track Construction Test Start ======================" << std::endl;
}
