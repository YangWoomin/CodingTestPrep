
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>

static long long solution1(long long n) {
    long long answer = 0;

    std::vector<int> freq(10);

    while (0 < n)
    {
        freq[n % 10]++;
        n /= 10;
    }

    for (int i = freq.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < freq[i]; ++j)
        {
            answer *= 10;
            answer += i;
        }
    }

    return answer;
}

void SortIntegerDescTest()
{
    //int n = 118372; // 873211

    int n = 546267; // 766542

    std::cout << "====================== Sort Integer Desc Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Sort Integer Desc Test End ======================" << std::endl;
}
