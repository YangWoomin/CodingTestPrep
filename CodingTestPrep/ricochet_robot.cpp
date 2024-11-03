
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <queue>
#include    <tuple>

static int solution1(std::vector<std::string> board) {
    int answer = -1;

    const int h = board.size(), w = board[0].size();

    std::vector<std::vector<bool>> visit(h, std::vector<bool>(w, false));

    auto isValid = [&](int y, int x) {
        return 0 <= y && h > y && 0 <= x && w > x && 'D' != board[y][x];
        };

    const std::vector<int> dirY = { 0, 0, 1, -1 };
    const std::vector<int> dirX = { 1, -1, 0, 0 };

    int ry = 0, rx = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if ('R' == board[i][j])
            {
                ry = i;
                rx = j;
            }
        }
    }

    std::queue<std::tuple<int, int, int>> q;
    q.push({ ry, rx, 0 });

    while (!q.empty())
    {
        auto [y, x, count] = q.front();
        q.pop();

        if (visit[y][x])
        {
            continue;
        }

        visit[y][x] = true;

        if ('G' == board[y][x])
        {
            return count;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dirY[i], nx = x + dirX[i];
            while (isValid(ny, nx))
            {
                ny += dirY[i];
                nx += dirX[i];
            }

            ny -= dirY[i];
            nx -= dirX[i];

            if (!visit[ny][nx])
            {
                q.push({ ny, nx, count + 1 });
            }
        }
    }

    return answer;
}

void RicochetRobotTest()
{
    //std::vector<std::string> board = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." }; // 7
    std::vector<std::string> board = { ".D.R", "....", ".G..", "...D" }; // -1

    std::cout << "====================== Ricochet Robot Test Start ======================" << std::endl;

    std::cout << "Board : " << std::endl;
    for (const auto& ele : board)
    {
        std::cout << ele << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(board);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Ricochet Robot Test End ======================" << std::endl;
}
