
#include	"test5.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <unordered_map>
#include    <unordered_set>
#include    <set>

static std::vector<int> solution1(std::vector<std::string> gems) {

    std::vector<int> answer(2);

    int idx = 0;
    std::unordered_map<std::string, int> indices;
    for (int i = 0; i < gems.size(); ++i)
    {
        if (indices.end() == indices.find(gems[i]))
        {
            indices[gems[i]] = idx++;
        }
    }

    std::vector<int> minIndices(idx, -1);
    std::unordered_set<int> set;
    std::set<int> min;
    int max = gems.size(), minDist = gems.size();
    for (int i = 0; i < gems.size(); ++i)
    {
        min.erase(minIndices[indices[gems[i]]]);
        minIndices[indices[gems[i]]] = i + 1;
        min.insert(i + 1);
        max = i + 1;
        set.insert(indices[gems[i]]);
        if (set.size() == idx)
        {
            int dist = max - *min.begin();
            if (minDist > dist)
            {
                answer[0] = *min.begin();
                answer[1] = max;
                minDist = dist;
            }
        }
    }

    return answer;
}

void GemstoneShoppingTest()
{
    //std::vector<std::string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" }; // [3, 7]

    //std::vector<std::string> gems = { "AA", "AB", "AC", "AA", "AC" }; // [1, 3]

    //std::vector<std::string> gems = { "XYZ", "XYZ", "XYZ" }; // [1, 1]

    std::vector<std::string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" }; // [1, 5]

    std::cout << "====================== Gemstone Shopping Test Start ======================" << std::endl;

    std::cout << "Gemstones : [ ";
    for (const auto& ele : gems)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(gems);

    std::cout << "Result : " << res[0] << ", " << res[1] << std::endl;

    std::cout << "====================== Gemstone Shopping Test End ======================" << std::endl;
}
