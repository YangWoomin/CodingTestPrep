
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include <functional>

static std::vector<int> solution1(int n, long long k) {
    std::vector<int> answer;

    long long num = 1;
    std::vector<int> arr;
    std::vector<long long> factorials(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        arr.push_back(i);
        num *= i;
        factorials[i] = num;
    }

    std::function<void(int, long long)> calc = [&](int num, long long k) {

        if (1 == num)
        {
            answer.push_back(arr[num - 1]);
            return;
        }

        long long count = factorials[num] / num;
        long long target = (k - 1) / count;
        answer.push_back(arr[target]);
        arr.erase(arr.begin() + target);
        long long offset = (k - 1) / count * count;

        calc(num - 1, k - offset);
        };

    calc(n, k);

    return answer;
}

void MethodOfLiningUpTest()
{
    int n = 3, k = 5; // [3,1,2]

    std::cout << "====================== Method Of Lining Up Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n, k);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Method Of Lining Up Test End ======================" << std::endl;
}
