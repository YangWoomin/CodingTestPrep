
#include	"test1.h"

#include	<iostream>
#include	<vector>
#include	<stack>

static std::string solution1(int n, int m, int x, int y, int r, int c, int k) {
    std::string answer = "";

    auto getDist = [&](int ny, int nx) {
        return std::abs(ny - r) + std::abs(nx - c);
        };

    int dist = getDist(x, y);
    if (dist > k || dist % 2 != k % 2)
    {
        return "impossible";
    }

    auto isValid = [&](int ny, int nx) {
        return 1 <= ny && n >= ny && 1 <= nx && m >= nx;
        };

    const std::vector<int> dirY = { 1, 0, 0, -1 };
    const std::vector<int> dirX = { 0, -1, 1, 0 };
    const std::vector<char> dir = { 'd', 'l', 'r', 'u' };

    int ny = x, nx = y, count = k;
    while (0 < count)
    {
        for (int i = 0; i < 4; ++i)
        {
            int ty = ny + dirY[i];
            int tx = nx + dirX[i];

            if (!isValid(ty, tx))
            {
                continue;
            }

            if (getDist(ty, tx) + answer.size() + 1 > k)
            {
                continue;
            }

            ny = ty;
            nx = tx;
            answer += dir[i];
            break;
        }
        count--;
    }

    return answer;
}

void MazeEscapeCommandTest()
{
    //int n = 3, m = 4, x = 2, y = 3, r = 3, c = 1, k = 5; // "dllrl"
    //int n = 2, m = 2, x = 1, y = 1, r = 2, c = 2, k = 2; // "dr"
    int n = 3, m = 3, x = 1, y = 2, r = 3, c = 3, k = 4; // "impossible"

    std::cout << "====================== Maze Escape Command Test Start ======================" << std::endl;

    std::cout << "N : " << n << ", M : " << m << ", X : " << x << ", Y : " << y << ", R : " << r << ", C : " << c << ", K : " << std::endl;

    auto res = solution1(n, m, x, y, r, c, k);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Maze Escape Command Test End ======================" << std::endl;
}
