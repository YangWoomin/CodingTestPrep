
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <queue>

static std::vector<int> solution1(int m, int n, std::vector<std::vector<int>> picture) {

    auto isValid = [&](int y, int x, int num) {
        return 0 <= y && m > y && 0 <= x && n > x && num == picture[y][x];
        };

    const std::vector<int> dirY = { 0, 0, 1, -1 };
    const std::vector<int> dirX = { 1, -1, 0, 0 };

    int max = 0, areaCount = 0;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int num = picture[i][j];
            if (0 == num)
            {
                continue;
            }

            areaCount++;

            int count = 0;
            std::queue<std::pair<int, int>> q;
            q.push({ i, j });
            while (!q.empty())
            {
                auto [y, x] = q.front();
                q.pop();

                if (0 == picture[y][x])
                {
                    continue;
                }

                picture[y][x] = 0;
                count++;
                max = std::max(max, count);

                for (int k = 0; k < 4; ++k)
                {
                    int ny = y + dirY[k];
                    int nx = x + dirX[k];
                    if (isValid(ny, nx, num))
                    {
                        q.push({ ny, nx });
                    }
                }
            }
        }
    }

    return { areaCount, max };
}

void KakaoFriendsColoringBookTest()
{
    int m = 6, n = 4;
    std::vector<std::vector<int>> picture = { {1, 1, 1, 0} ,{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} }; // [4, 5]

    std::cout << "====================== Kakao Friends Coloring Book Test Start ======================" << std::endl;

    std::cout << "M : " << m << ", N : " << n << std::endl;
    std::cout << "Picture : " << std::endl;
    for (const auto& ele : picture)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(m, n, picture);

    std::cout << "Result : " << res[0] << ", " << res[1] << std::endl;

    std::cout << "====================== Kakao Friends Coloring Book Test End ======================" << std::endl;
}
