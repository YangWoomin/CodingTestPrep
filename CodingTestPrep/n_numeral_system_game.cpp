
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <cmath>
#include    <functional>
#include    <unordered_set>

static std::string solution1(int n, int t, int m, int p) {
    std::string answer = "";

    auto convert = [&](int num) -> std::string {

        if (0 == num)
        {
            return "0";
        }

        std::string res;
        while (0 < num)
        {
            int tmp = num % n;
            if (9 < tmp)
            {
                res = std::string(1, 'A' + tmp - 10) + res;
            }
            else
            {
                res = std::to_string(tmp) + res;
            }
            num /= n;
        }
        return res;
        };

    int num = 0, idx = p, count = 0;
    std::string str;
    while (count < t)
    {
        str += convert(num);
        while (str.size() > idx && count < t)
        {
            answer += str[idx - 1];
            idx += m;
            count++;
        }
        num++;
    }

    return answer;
}

void NNumeralSystemGameTest()
{
    //int n = 2, t = 4, m = 2, p = 1; // "0111"
    //int n = 16, t = 16, m = 2, p = 1; // "02468ACE11111111"
    int n = 16, t = 16, m = 2, p = 2; // "13579BDF01234567"

    std::cout << "====================== N Numeral System Game Test Start ======================" << std::endl;

    std::cout << "n : " << n << ", t : " << t << ", m : " << m << ", p : " << p << std::endl;

    auto res = solution1(n, t, m, p);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== N Numeral System Game Test End ======================" << std::endl;
}
