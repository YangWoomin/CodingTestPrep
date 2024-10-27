
#include	"test3.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <functional>
#include    <stack>

static int solution1(int n, int k) {
    int answer = 0;

    std::stack<int> st;

    while (0 < n)
    {
        st.push(n % k);
        n /= k;
    }

    std::string num;
    while (!st.empty())
    {
        int d = st.top();
        st.pop();
        num += '0' + d;
    }

    auto isPrime = [](long long num) {
        for (long long i = 2; i * i <= num; ++i)
        {
            if (0 == num % i)
            {
                return false;
            }
        }
        return true;
        };

    long long number = 0;
    for (const auto& ch : num)
    {
        if ('0' != ch)
        {
            number = number * 10 + ch - '0';
        }
        else
        {
            if (1 < number && isPrime(number))
            {
                answer++;
            }
            number = 0;
        }
    }

    if (1 < number && isPrime(number))
    {
        answer++;
    }

    return answer;
}

void PrimeNumberInKBaseTest()
{
    //int n = 437674, k = 3; // 3
    int n = 110011, k = 10; // 2

    std::cout << "====================== Prime Number In K Base Test Start ======================" << std::endl;

    std::cout << "N : " << n << ", K : " << k << std::endl;

    auto res = solution1(n, k);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Prime Number In K Base Test End ======================" << std::endl;
}
