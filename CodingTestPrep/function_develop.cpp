
#include	"queue_test.h"

#include	<iostream>
#include	<vector>

static std::vector<int> solution1(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;

    int deploy = 0;
    while (deploy < progresses.size())
    {
        for (int i = deploy; i < progresses.size(); ++i)
        {
            progresses[i] += speeds[i];
        }

        int count = 0;
        while (deploy < progresses.size() && 100 <= progresses[deploy])
        {
            count++;
            deploy++;
        }

        if (0 < count)
        {
            answer.push_back(count);
        }
    }

    return answer;
}

static std::vector<int> solution2(std::vector<int> progresses, std::vector<int> speeds)
{
    std::vector<int> answer;

    int max = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        int day = (99 - progresses[i]) / speeds[i] + 1;

        if (day <= max && 0 < answer.size())
        {
            ++answer.back();
        }
        else
        {
            answer.push_back(1);
            max = day;
        }
    }

    return answer;
}

void FunctionDevelopTest()
{
    /*std::vector<int> progresses = { 93, 30, 55 };
    std::vector<int> speeds = { 1, 30, 5 }; // [2, 1] */
    std::vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    std::vector<int> speeds = { 1, 1, 1, 1, 1, 1 }; // [1, 3, 2]

    std::cout << "====================== Function Develop Test Start ======================" << std::endl;

    std::cout << "Progresses : [ ";
    for (const auto& ele : progresses)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    std::cout << "Speeds : [ ";
    for (const auto& ele : speeds)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    std::vector<int> res = solution2(progresses, speeds);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    std::cout << "====================== Function Develop Test End ======================" << std::endl;
}
