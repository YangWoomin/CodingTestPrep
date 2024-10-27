
#include	"test1.h"

#include	<iostream>
#include	<vector>
#include	<stack>
#include    <string>

#include    <unordered_map>

static std::vector<int> solution1(std::string today, std::vector<std::string> terms, std::vector<std::string> privacies) {
    std::vector<int> answer;

    std::unordered_map<char, int> tms;
    for (const auto& ele : terms)
    {
        tms[ele[0]] = std::stoi(ele.substr(2));
    }

    int tyear = std::stoi(today.substr(0, 4));
    int tmonth = std::stoi(today.substr(5, 2));
    int tday = std::stoi(today.substr(8));

    for (int i = 0; i < privacies.size(); ++i)
    {
        auto& p = privacies[i];
        int year = std::stoi(p.substr(0, 4));
        int month = std::stoi(p.substr(5, 2));
        int day = std::stoi(p.substr(8, 2));
        char type = p[11];

        month += tms[type];
        year += (month - 1) / 12;
        month = (month - 1) % 12 + 1;

        if (tyear > year)
        {
            answer.push_back(i + 1);
        }
        else if (tyear == year && tmonth > month)
        {
            answer.push_back(i + 1);
        }
        else if (tyear == year && tmonth == month && tday >= day)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

void PersonalInformationCollectionExpiryDateTest()
{
    //std::string today = "2022.05.19";
    //std::vector<std::string> terms = { "A 6", "B 12", "C 3" };
    //std::vector<std::string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" }; // [1, 3]

    std::string today = "2020.01.01";
    std::vector<std::string> terms = { "Z 3", "D 5" };
    std::vector<std::string> privacies = { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" }; // [1, 4, 5]

    std::cout << "====================== Personal Information Collection Expiry Date Test Start ======================" << std::endl;

    std::cout << "Today : " << today << std::endl;
    std::cout << "Terms : [ ";
    for (const auto& ele : terms)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Privacies : [ ";
    for (const auto& ele : privacies)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(today, terms, privacies);

    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Personal Information Collection Expiry Date Test End ======================" << std::endl;
}
