
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <cmath>

static std::vector<int> solution1(long long begin, long long end) {
    std::vector<int> answer;

    auto getNum = [&](long long num) -> long long {

        if (1 == num)
        {
            return 0;
        }

        long long res = 1;
        long long max = std::sqrt(num);
        for (long long i = 2; i <= max && i <= 10000000; ++i)
        {
            if (0 == num % i)
            {
                res = i;
                if (10000000 >= num / i)
                {
                    return num / i;
                }
            }
        }

        return res;
    };

    while (begin <= end)
    {
        answer.push_back(getNum(begin));
        begin++;
    }

    return answer;
}

void NumberBlockTest()
{
    long long begin = 1, end = 10; // [0, 1, 1, 2, 1, 3, 1, 4, 3, 5]

    std::cout << "====================== Number Block Test Start ======================" << std::endl;

    std::cout << "Begin  : " << begin << ", End : " << end << std::endl;

    auto res = solution1(begin, end);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Number Block Test End ======================" << std::endl;
}
