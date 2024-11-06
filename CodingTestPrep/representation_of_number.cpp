
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static int solution1(int n) {
    int answer = 0;

    int i = 0, j = 0, sum = 0;
    while (i <= n && j <= n)
    {
        if (sum == n)
        {
            answer++;
            i++;
            sum += i;
        }
        else if (sum < n)
        {
            i++;
            sum += i;
        }
        else  // sum > n
        {
            sum -= j;
            j++;
        }
    }

    return answer;
}

void RepresentationOfNumberTest()
{
    int n = 15; // 4

    std::cout << "====================== Representation Of Number Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Representation Of Number Test End ======================" << std::endl;
}
