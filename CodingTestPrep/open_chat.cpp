
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include	<unordered_map>
#include	<string>
#include    <sstream>

static std::vector<std::string> solution1(std::vector<std::string> record) {
    std::vector<std::string> answer;

    std::unordered_map<std::string, std::string> nickname;
    std::vector<std::string> cmds;
    std::string token;
    for (const auto& ele : record)
    {
        cmds.clear();
        std::istringstream iss(ele);
        while (iss >> token)
        {
            cmds.push_back(token);
        }

        if ("Enter" == cmds[0])
        {
            nickname[cmds[1]] = cmds[2];
        }
        else if ("Change" == cmds[0])
        {
            nickname[cmds[1]] = cmds[2];
        }
    }

    for (const auto& ele : record)
    {
        cmds.clear();
        std::istringstream iss(ele);
        while (iss >> token)
        {
            cmds.push_back(token);
        }

        if ("Enter" == cmds[0])
        {
            answer.push_back(nickname[cmds[1]] + "님이 들어왔습니다.");
        }
        else if ("Leave" == cmds[0])
        {
            answer.push_back(nickname[cmds[1]] + "님이 나갔습니다.");
        }
    }

    return answer;
}


void OpenChatTest()
{
    std::vector<std::string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" }; // [ "Prodo님이 들어왔습니다." "Ryan님이 들어왔습니다." "Prodo님이 나갔습니다." "Prodo님이 들어왔습니다." ]

    std::cout << "====================== Open Chat Test Start ======================" << std::endl;

    std::cout << "Record : [ ";
    for (const auto& ele : record)
    {
        std::cout << "\"" << ele << "\" ";
    }
    std::cout << " ]" << std::endl;

    auto res = solution1(record);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << "\"" << ele << "\" ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Open Chat Test End ======================" << std::endl;
}
