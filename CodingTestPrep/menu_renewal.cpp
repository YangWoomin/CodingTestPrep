
#include	"hash_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_set>
#include	<unordered_map>
#include    <algorithm>

std::unordered_map<int, std::unordered_set<std::string>> maxCombis;
std::unordered_map<std::string, int> combis;

void IncreaseCombination(int size, const std::string& combi)
{
    if (1 < ++combis[combi])
    {
        if (0 == maxCombis[size].size())
        {
            maxCombis[size].insert(combi);
        }
        else
        {
            if (combis[combi] > combis[*maxCombis[size].begin()])
            {
                maxCombis[size].clear();
                maxCombis[size].insert(combi);
            }
            else if (combis[combi] == combis[*maxCombis[size].begin()])
            {
                if (combi == *maxCombis[size].begin())
                {
                    maxCombis[size].clear();
                }
                maxCombis[size].insert(combi);
            }
        }
    }
}

std::string GetCombination(std::vector<int>& arr, const std::string& str)
{
    std::string res;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (1 == arr[i])
        {
            res += str[i];
        }
    }
    return res;
}

static std::vector<std::string> solution1(std::vector<std::string> orders, std::vector<int> course) {
    std::vector<std::string> answer;

    for (const auto& ele : course)
    {
        maxCombis[ele];
    }

    for (auto& order : orders)
    {
        std::sort(order.begin(), order.end());

        for (const auto& size : course)
        {
            if (order.size() < size)
            {
                break;
            }

            std::vector<int> select(order.size(), 0);
            for (int j = order.size() - 1, k = 0; k < size; ++k, --j)
            {
                select[j] = 1;
            }
            std::string combi = GetCombination(select, order);
            IncreaseCombination(size, combi);

            while (std::next_permutation(select.begin(), select.end()))
            {
                combi = GetCombination(select, order);
                IncreaseCombination(size, combi);
            }
        }
    }

    for (const auto& ele : maxCombis)
    {
        for (const auto& ele2 : ele.second)
        {
            answer.push_back(ele2);
        }
    }
    std::sort(answer.begin(), answer.end());

    return answer;
}

void MenuRenewalTest()
{
    //std::vector<std::string> orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    //std::vector<int> course = { 2,3,4 }; // ["AC", "ACDE", "BCFG", "CDE"]

    //std::vector<std::string> orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
    //std::vector<int> course = { 2,3,5 }; // ["ACD", "AD", "ADE", "CD", "XYZ"]

    std::vector<std::string> orders = { "XYZ", "XWY", "WXA" };
    std::vector<int> course = { 2,3,4 }; // ["WX", "XY"]

    std::cout << "====================== Menu Renewal Test Start ======================" << std::endl;

    std::cout << "Orders : [ ";
    for (const auto& ele : orders)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Course : [ ";
    for (const auto& ele : course)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(orders, course);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Menu Renewal Game Test End ======================" << std::endl;
}
