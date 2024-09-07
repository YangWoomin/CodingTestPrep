
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include	<string>
#include	<unordered_map>

static std::string solution1(std::vector<std::string> participant, std::vector<std::string> completion) {

    std::unordered_map<std::string, int> athletes;

    for (const auto& ele : participant)
    {
        auto it = athletes.insert(std::make_pair(ele, 1));
        if (false == it.second)
        {
            it.first->second++;
        }
    }

    for (const auto& ele : completion)
    {
        auto it = athletes.find(ele);
        if (athletes.end() != it)
        {
            it->second--;
            if (0 == it->second)
            {
                athletes.erase(it);
            }
        }
    }

    return athletes.begin()->first;
}

void FailedMarathonerTest()
{
	//std::vector<std::string> participants = { "leo", "kiki", "eden" };
	//std::vector<std::string> completions = { "eden", "kiki" }; // leo

    //std::vector<std::string> participants = { "marina", "josipa", "nikola", "vinko", "filipa" };
    //std::vector<std::string> completions = { "josipa", "filipa", "marina", "nikola" }; // vinko

    std::vector<std::string> participants = { "mislav", "stanko", "mislav", "ana" };
    std::vector<std::string> completions = { "stanko", "ana", "mislav" }; // mislav

	std::cout << "====================== Failed Marathoner Test Start ======================" << std::endl;

	std::cout << "Paticipants : [ ";
	for (const auto& ele : participants)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;
	
	std::cout << "Completions : [ ";
	for (const auto& ele : completions)
	{
		std::cout << ele << " ";
	}
	std::cout << " ]" << std::endl;

	auto res = solution1(participants, completions);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Failed Marathoner Test End ======================" << std::endl;
}

