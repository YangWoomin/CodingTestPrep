
#include	"tree_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <unordered_map>

static std::vector<int> solution1(std::vector<std::string> enroll, std::vector<std::string> referral, std::vector<std::string> seller, std::vector<int> amount) {
    enroll.push_back("-");

    std::vector<int> answer(enroll.size());

    std::unordered_map<std::string, int> indices;
    for (int i = 0; i < enroll.size(); ++i)
    {
        indices[enroll[i]] = i;
    }

    std::vector<int> refs(enroll.size(), -1);
    for (int i = 0; i < enroll.size() - 1; ++i)
    {
        refs[indices[enroll[i]]] = indices[referral[i]];
    }

    for (int i = 0; i < seller.size(); ++i)
    {
        int sum = amount[i] * 100;
        int tax = sum * 0.1;
        int idx = indices[seller[i]];
        while (0 <= idx && 0 < sum)
        {
            if (0 <= refs[idx])
            {
                answer[idx] += sum - tax;
            }
            else
            {
                answer[idx] += sum;
            }
            sum = tax;
            tax = tax * 0.1;
            idx = refs[idx];
        }
    }

    answer.pop_back();

    return answer;
}

void PyramidToothbrushSellTest()
{
    //std::vector<std::string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    //std::vector<std::string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    //std::vector<std::string> seller = { "young", "john", "tod", "emily", "mary" };
    //std::vector<int> amount = { 12, 4, 2, 5, 10 }; // [360, 958, 108, 0, 450, 18, 180, 1080]

    std::vector<std::string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    std::vector<std::string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    std::vector<std::string> seller = { "sam", "emily", "jaimie", "edward" };
    std::vector<int> amount = { 2, 3, 5, 4 }; // [0, 110, 378, 180, 270, 450, 0, 0]

	std::cout << "====================== Pyramid Toothbrush Sell Test Start ======================" << std::endl;

    std::cout << "Enroll : [ ";
    for (const auto& ele : enroll)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Referral : [ ";
    for (const auto& ele : referral)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Seller : [ ";
    for (const auto& ele : seller)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Amout : [ ";
    for (const auto& ele : amount)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

	auto res = solution1(enroll, referral, seller, amount);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

	std::cout << "====================== Pyramid Toothbrush Sell Test End ======================" << std::endl;
}
