
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

static std::string solution1(int n) {
    std::string answer = "";

    while (0 < n)
    {
        answer = std::string(1, n % 3 + '0') + answer;
        n /= 3;
    }

    int mst = 0;
    for (int i = 1; i < answer.size(); ++i)
    {
        if ('0' == answer[i])
        {
            answer[i] = '4';

            int tmp = i - 1;
            while (0 <= tmp)
            {
                if ('4' == answer[tmp])
                {
                    answer[tmp] = '2';
                    break;
                }
                else if ('2' == answer[tmp])
                {
                    answer[tmp] = '1';
                    break;
                }
                else if ('1' == answer[tmp])
                {
                    if (mst < tmp)
                    {
                        answer[tmp] = '4';
                    }
                    else
                    {
                        answer[tmp] = ' ';
                        mst = tmp;
                    }
                    tmp--;
                }
            }
        }
    }

    for (auto it = answer.begin(); answer.end() != it;)
    {
        if (' ' == *it)
        {
            it = answer.erase(it);
        }
        else
        {
            it++;
        }
    }

    return answer;
}

void NumberOf124NationTest()
{
    //int n = 1; // 1
    //int n = 2; // 2
    //int n = 3; // 4
    int n = 4; // 11

    std::cout << "====================== Number Of 124 Nation Test Start ======================" << std::endl;

    std::cout << "N : " << n << std::endl;

    auto res = solution1(n);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Number Of 124 Nation Test End ======================" << std::endl;
}
