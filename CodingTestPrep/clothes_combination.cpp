
#include	"hash_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_map>
#include    <algorithm>
#include	<cmath>

std::vector<int> arranged;

int GetCombinationCount(std::vector<int>& select)
{
    int res = 0;
    for (int j = 0; j < select.size(); ++j)
    {
        if (1 == select[j])
        {
            if (0 == res)
            {
                res = arranged[j];
            }
            else
            {
                res *= arranged[j];
            }
        }
    }
    return res;
}

static int solution1(std::vector<std::vector<std::string>> clothes) {
    int answer = 0;

    std::unordered_map<std::string, int> indices;
    bool isEachOne = true;
    for (const auto& ele : clothes)
    {
        auto finder = indices.find(ele[1]);
        if (indices.end() != finder)
        {
            arranged[finder->second]++;
            isEachOne = false;
        }
        else
        {
            arranged.push_back(1);
            indices[ele[1]] = arranged.size() - 1;
        }
    }

    if (true == isEachOne)
    {
        return std::pow(2, indices.size()) - 1;
    }

    for (int i = 0; i < arranged.size(); ++i)
    {
        std::vector<int> select(arranged.size(), 1);
        for (int j = 0; j < i; ++j)
        {
            select[j] = 0;
        }

        answer += GetCombinationCount(select);

        while (0 < select.size() && std::next_permutation(select.begin(), select.end()))
        {
            answer += GetCombinationCount(select);
        }
    }

    return answer;
}

static int solution2(std::vector<std::vector<std::string>> clothes) {
    int answer = 1;

    std::unordered_map <std::string, int> attributes;
    for (int i = 0; i < clothes.size(); i++)
        attributes[clothes[i][1]]++;
    for (auto it = attributes.begin(); it != attributes.end(); it++)
        answer *= (it->second + 1);
    answer--;

    return answer;
}

void ClothesCombinationTest()
{
    //std::vector<std::vector<std::string>> clothes = { { "yellow_hat", "headgear" } ,{ "blue_sunglasses", "eyewear" }, {"green_turban", "headgear" } }; // 5
    std::vector<std::vector<std::string>> clothes = { { "crow_mask", "face" } , { "blue_sunglasses", "face" }, { "smoky_makeup", "face" } }; // 3

    std::cout << "====================== Clothes Combination Test Start ======================" << std::endl;

    std::cout << "Orders : [ ";
    for (const auto& ele : clothes)
    {
        std::cout << "[ name : " << ele[0] << ", type : " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution2(clothes);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Clothes Combination Test End ======================" << std::endl;
}
