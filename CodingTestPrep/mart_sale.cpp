
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_map>
#include	<unordered_set>
#include	<string>

static int solution1(std::vector<std::string> want, std::vector<int> number, std::vector<std::string> discount) {
    int answer = 0;

    int count = 0;
    std::unordered_map<std::string, int> hope;
    for (int i = 0; i < want.size(); ++i)
    {
        hope.insert(std::make_pair(want[i], number[i]));
        count += number[i];
    }

    std::unordered_map<std::string, int> current;
    for (int i = 0; i < count; ++i)
    {
        current[discount[i]]++;
    }

    std::unordered_set<std::string> unsatisfactory;
    for (const auto& ele : hope)
    {
        auto finder = current.find(ele.first);
        int bought = 0;
        if (current.end() != finder)
        {
            bought = finder->second;
        }
        if (0 < ele.second - bought)
        {
            unsatisfactory.insert(ele.first);
        }
    }

    if (0 == unsatisfactory.size())
    {
        answer++;
    }

    for (int i = count; i < discount.size(); ++i)
    {
        current[discount[i - count]]--;
        current[discount[i]]++;

        auto finder = hope.find(discount[i - count]);
        if (hope.end() != finder)
        {
            if (finder->second > current[discount[i - count]])
            {
                unsatisfactory.insert(discount[i - count]);
            }
        }

        finder = hope.find(discount[i]);
        if (hope.end() != finder)
        {
            if (finder->second <= current[discount[i]])
            {
                unsatisfactory.erase(discount[i]);
            }
        }

        if (0 == unsatisfactory.size())
        {
            answer++;
        }
    }

    return answer;
}

void MartSaleTest()
{
    std::vector<std::string> want = { "banana", "apple", "rice", "pork", "pot" };
    std::vector<int> number = { 3, 2, 2, 2, 1 };
    std::vector<std::string> discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" }; // 3

    //std::vector<std::string> want = { "apple" };
    //std::vector<int> number = { 10 };
    //std::vector<std::string> discount = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" }; // 0

    std::cout << "====================== Mart Sale Test Start ======================" << std::endl;

    std::cout << "Wish List : [ ";
    for (const auto& ele : want)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    std::cout << "Wish Count : [ ";
    for (const auto& ele : number)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    std::cout << "Discount List : [ ";
    for (const auto& ele : discount)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    auto res = solution1(want, number, discount);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Mart Sale Test End ======================" << std::endl;
}