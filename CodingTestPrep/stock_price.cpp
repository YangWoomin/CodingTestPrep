
#include	"stack_test.h"

#include	<iostream>
#include	<vector>
#include	<stack>

static std::vector<int> solution1(const std::vector<int>& prices) 
{
    std::vector<int> answer(prices.size(), 0);
    std::stack<int> tmp;
    for (int i = 0; i < prices.size(); ++i)
    {
        while (false == tmp.empty())
        {
            int last = tmp.top();
            if (prices[last] > prices[i])
            {
                answer[last] = i - last;
                tmp.pop();
            }
            else
            {
                break;
            }
        }

        tmp.push(i);
    }

    while (false == tmp.empty())
    {
        int last = tmp.top();
        answer[last] = prices.size() - last - 1;
        tmp.pop();
    }

    return answer;
}

void StockPriceTest()
{
    std::vector<int> arr = { 1, 2, 3, 2, 3 }; // [4, 3, 1, 1, 0]

    std::cout << "====================== Stock Price Test Start ======================" << std::endl;

    std::cout << "Prices : ";
    for (const auto& ele : arr)
    {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    std::vector<int> res = solution1(arr);

    std::cout << "Result : ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << std::endl;

    std::cout << "====================== Stock Price Test End ======================" << std::endl;
}
