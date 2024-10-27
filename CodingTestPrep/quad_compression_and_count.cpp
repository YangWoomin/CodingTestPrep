
#include	"test2.h"

#include	<iostream>
#include	<vector>
#include	<stack>
#include    <string>

#include    <functional>

static std::vector<int> solution1(std::vector<std::vector<int>> arr) {
    std::vector<int> answer(2, 0);

    const int size = arr.size();

    std::function<int(int, int, int)> dfs = [&](int y, int x, int len) {

        if (1 == len)
        {
            return arr[y - 1][x - 1];
        }

        int ret = -1;

        std::vector<int> tmp(2, 0);
        const std::vector<int> diffY = { len / 2, 0, len / 2, 0 };
        const std::vector<int> diffX = { 0, len / 2, len / 2, 0 };

        for (int i = 0; i < 4; ++i)
        {
            int ny = y - diffY[i];
            int nx = x - diffX[i];
            int res = dfs(ny, nx, len / 2);
            if (0 == i)
            {
                ret = res;
            }
            else if (ret != res)
            {
                ret = -1;
            }

            if (0 <= res)
            {
                tmp[res]++;
            }
        }

        if (-1 == ret)
        {
            answer[0] += tmp[0];
            answer[1] += tmp[1];
        }

        return ret;
        };

    int res = dfs(size, size, size);
    if (0 == res)
    {
        answer[0]++;
    }
    else if (1 == res)
    {
        answer[1]++;
    }

    return answer;
}

void QuadCompressionAndCountTest()
{
    //std::vector<std::vector<int>> arr = { {1,1,0,0} ,{1,0,0,0},{1,0,0,1},{1,1,1,1} }; // [4, 9]
    std::vector<std::vector<int>> arr = { 
        {1,1,1,1,1,1,1,1} ,
        {0,1,1,1,1,1,1,1},
        {0,0,0,0,1,1,1,1},
        {0,1,0,0,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,1,1,1}
    }; // [10, 15]

    std::cout << "====================== Quad Compression And Count Test Start ======================" << std::endl;

    std::cout << "Array : " << std::endl;
    for (const auto& ele : arr)
    {
        std::cout << "[ ";
        for (const auto& ele2 : ele)
        {
            std::cout << ele2 << " ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;

    auto res = solution1(arr);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Quad Compression And Count Test End ======================" << std::endl;
}
