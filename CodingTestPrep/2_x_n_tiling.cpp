
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(int n) {

    if (2 > n)
    {
        return n;
    }

    int prev = 1;
    int next = 2;
    for (int i = 3; i <= n; ++i)
    {
        int tmp = next;
        next = (next + prev) % 1000000007;
        prev = tmp;
    }

    return next;
}

void _2xnTilingTest()
{
    int n = 4; // 5

    std::cout << "====================== 2 x N Tiling Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== 2 x N Tiling Test End ======================" << std::endl;
}
