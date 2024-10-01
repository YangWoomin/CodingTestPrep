
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

#include    <cmath>

static std::vector<int> solution1(int brown, int yellow) {

    int height = 3;
    int width = (brown - height * 2 + 4) / 2;
    while (height <= width)
    {
        int innerWidth = width - 2;
        int innterHeight = height - 2;
        if (yellow == innerWidth * innterHeight)
        {
            return { width, height };
        }
        height++;
        width = (brown - height * 2 + 4) / 2;
    }

    return { width, height };
}

static std::vector<int> solution2(int brown, int yellow) {
    int total = brown + yellow;
    for (int h = 3; h <= sqrt(total); ++h)
    {
        if (0 == total % h)
        {
            int w = total / h;
            if (brown == (w + h) * 2 - 4)
            {
                return { w, h };
            }
        }
    }
    return { 0, 0 };
}

void CarpetTest()
{
    //int brown = 10, yellow = 2; // [4, 3]
    //int brown = 8, yellow = 1; // [3, 3]
    int brown = 24, yellow = 24; // [8, 6]

    std::cout << "====================== Carpet Test Start ======================" << std::endl;

    std::cout << "Brown : " << brown << ", Yellow : " << yellow << std::endl;

    auto res = solution2(brown, yellow);
    std::cout << "Result : [ " << res[0] << " " << res[1] << " ]" << std::endl;

    std::cout << "====================== Carpet Test End ======================" << std::endl;
}
