
#include	"greedy_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static int solution1(std::vector<std::vector<int>> routes) {
    int answer = 0;

    std::sort(routes.begin(), routes.end(), [](auto& lhs, auto& rhs) {
        return lhs[1] < rhs[1];
        });

    int camera = -30001;
    for (const auto& ele : routes)
    {
        if (camera < ele[0])
        {
            answer++;
            camera = ele[1];
        }
    }

    return answer;
}

void MonitoringCameraTest()
{
    std::vector<std::vector<int>> routes = { {-20,-15} ,{-14,-5},{-18,-13},{-5,-3} }; // 2

    std::cout << "====================== Monitoring Camera Test Start ======================" << std::endl;

    std::cout << "Routes : [ ";
    for (const auto& ele : routes)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(routes);

    std::cout << "Result: " << res << std::endl;

    std::cout << "====================== Monitoring Camera Test End ======================" << std::endl;
}
