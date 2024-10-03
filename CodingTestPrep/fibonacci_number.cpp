
#include	"dp_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(int n) {

    std::vector<int> fibo(n + 1, 0);
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;
    }

    return fibo[n];
}

static int solution2(int n) {

    int prev = 0, next = 1;
    for (int i = 2; i <= n; ++i)
    {
        int tmp = next;
        next = (prev + next) % 1234567;
        prev = tmp;
    }

    return next;
}

void FibonacciNumberTest()
{
    //int n = 3; // 2
    int n = 5; // 5

    std::cout << "====================== Fibonacci Number Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution2(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Fibonacci Number Test End ======================" << std::endl;
}
