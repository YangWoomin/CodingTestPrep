
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
            answer.push_back(nickname[cmds[1]] + "���� ���Խ��ϴ�.");
        }
        else if ("Leave" == cmds[0])
        {
            answer.push_back(nickname[cmds[1]] + "���� �������ϴ�.");
        }
    }

    return answer;
}


void OpenChatTest()
{
    std::vector<std::string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" }; // [ "Prodo���� ���Խ��ϴ�." "Ryan���� ���Խ��ϴ�." "Prodo���� �������ϴ�." "Prodo���� ���Խ��ϴ�." ]

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
