
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <cmath>
#include    <functional>
#include    <unordered_set>

static int solution1(std::string numbers) {
    int answer = 0;

    auto isPrime = [](int num) {
        if (2 > num)
        {
            return false;
        }
        else if (2 == num)
        {
            return true;
        }

        int len = std::sqrt(num);
        for (int i = 2; i <= len; ++i)
        {
            if (0 == num % i)
            {
                return false;
            }
        }
        return true;
        };

    std::vector<bool> visit(numbers.size(), false);
    std::string str;
    std::unordered_set<int> primes;

    std::function<void()> dfs = [&]() {

        if (0 < str.size())
        {
            int num = std::stoi(str);
            if (isPrime(num) && primes.end() == primes.find(num))
            {
                answer++;
                primes.insert(num);
            }
        }

        for (int i = 0; i < numbers.size(); ++i)
        {
            if (visit[i])
            {
                continue;
            }

            visit[i] = true;
            str.push_back(numbers[i]);

            dfs();

            visit[i] = false;
            str.pop_back();
        }
        };

    dfs();

    return answer;
}

void FindingPrimeNumbersTest()
{
    //std::string numbers = "17"; // 3
    std::string numbers = "011"; // 2

    std::cout << "====================== Finding Prime Numbers Test Start ======================" << std::endl;

    std::cout << "Numbers : " << numbers << std::endl;

    auto res = solution1(numbers);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Finding Prime Numbers Test End ======================" << std::endl;
}
