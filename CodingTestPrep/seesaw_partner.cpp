
#include	"practice.h"

#include	<iostream>
#include	<vector>
#include    <string>
#include    <algorithm>

#include    <unordered_map>

static long long solution1(std::vector<int> weights) {
    long long answer = 0;

    const std::vector<int> dist = { 2, 3, 4 };

    std::unordered_map<long long, long long> count;
    std::unordered_map<int, long long> dupl;

    for (const auto& weight : weights)
    {
        dupl[weight]++;

        for (int i = 0; i < dist.size(); i++)
        {
            long long torque = weight * dist[i];
            answer += count[torque];
            count[torque]++;
        }
    }

    for (const auto& [weight, cnt] : dupl)
    {
        if (1 < cnt)
        {
            answer -= cnt * (cnt - 1) / 2 * 2;
        }
    }

    return answer;
}

void SeesawPartnerTest()
{
    std::vector<int> weights = { 100,180,360,100,270 }; // 4

    std::cout << "====================== Seesaw Partner Test Start ======================" << std::endl;

    std::cout << "Weights : [ ";
    for (const auto& ele : weights)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(weights);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Seesaw Partner Test End ======================" << std::endl;
}
