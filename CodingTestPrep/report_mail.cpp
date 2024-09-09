
#include	"hash_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_set>
#include	<unordered_map>
#include	<string>
#include    <sstream>

static std::vector<int> solution1(std::vector<std::string> id_list, std::vector<std::string> report, int k) {
    std::vector<int> answer(id_list.size());

    std::unordered_map<std::string, int> user(id_list.size());
    for (int i = 0; i < id_list.size(); ++i)
    {
        user[id_list[i]] = i;
    }

    std::vector<std::string> line;
    std::string token;

    std::vector<std::unordered_set<int>> reported(id_list.size());
    for (const auto& ele : report)
    {
        line.clear();
        std::istringstream iss(ele);
        while (iss >> token)
        {
            line.push_back(token);
        }

        reported[user[line[1]]].insert(user[line[0]]);
    }

    for (int i = 0; i < reported.size(); ++i)
    {
        if (k <= reported[i].size())
        {
            for (const auto& ele : reported[i])
            {
                answer[ele]++;
            }
        }
    }

    return answer;
}

void ReportMailTest()
{
	//std::vector<std::string> userID = { "muzi", "frodo", "apeach", "neo" };
    //std::vector<std::string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
	//int k = 2; // [2,1,1,0]

    std::vector<std::string> userID = { "con", "ryan" };
    std::vector<std::string> report = { "ryan con", "ryan con", "ryan con", "ryan con" };
    int k = 3; // [0,0]

	std::cout << "====================== Report Mail Test Start ======================" << std::endl;

	std::cout << "User ID : [ ";
	for (const auto& ele : userID)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

    std::cout << "Report : [ ";
    for (const auto& ele : report)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

	auto res = solution1(userID, report, k);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

	std::cout << "====================== Report Mail Game Test End ======================" << std::endl;
}
