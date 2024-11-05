
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static int solution1(int n) {
    int answer = 0;

    auto getBinaryOneCount = [&](int num) {
        int count = 0;
        while (0 < num)
        {
            count += num % 2;
            num /= 2;
        }
        return count;
        };

    const int count = getBinaryOneCount(n);

    n++;
    while (true)
    {
        int tmp = getBinaryOneCount(n);
        if (count == tmp)
        {
            return n;
        }
        n++;
    }

    return answer;
}

void NextLargeNumberTest()
{
    //int n = 78; // 83
    int n = 15; // 23

    std::cout << "====================== Next Large Number Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Next Large Number Test End ======================" << std::endl;
}
