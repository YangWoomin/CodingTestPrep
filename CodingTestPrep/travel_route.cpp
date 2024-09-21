
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static std::vector<std::string> solution1(std::vector<std::vector<std::string>> tickets) {
    std::vector<std::string> answer;

    std::vector<bool> visit(tickets.size(), false);

    std::sort(tickets.begin(), tickets.end(), [](auto lhs, auto rhs) {
        if (lhs[0] == rhs[0])
        {
            return lhs[1] < rhs[1];
        }

        return lhs[0] < rhs[0];
        });

    std::function<bool(std::string)> dfs = [&](std::string target) {

        std::vector<std::string> t = { target, "" };
        auto it = std::lower_bound(tickets.begin(), tickets.end(), t, [](auto& lhs, auto& rhs) {
            return lhs[0] < rhs[0];
            });
        int next = std::distance(tickets.begin(), it);

        answer.push_back(target);
        while (next < tickets.size() && tickets[next][0] == target)
        {
            if (!visit[next])
            {
                visit[next] = true;
                if (dfs(tickets[next][1]))
                {
                    break;
                }
                visit[next] = false;
            }
            next++;
        }

        if (tickets.size() + 1 == answer.size())
        {
            return true;
        }

        answer.pop_back();
        return false;
        };

    dfs("ICN");

    return answer;
}

void TravelRouteTest()
{
    //std::vector<std::vector<std::string>> tickets = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} }; // ["ICN", "JFK", "HND", "IAD"]
    //std::vector<std::vector<std::string>> tickets = { {"ICN", "SFO"} ,{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} }; // ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]
    std::vector<std::vector<std::string>> tickets = { {"EZE", "TIA"} ,{"EZE", "HBA"},{"AXA", "TIA"},{"ICN", "AXA"},{"ANU", "ICN"}, \
        {"ADL", "ANU"},{"TIA", "AUA"},{"ANU", "AUA"},{"ADL", "EZE"},{"ADL", "EZE"},{"EZE", "ADL"},{"AXA", "EZE"},{"AUA", "AXA"},{"ICN", "AXA"}, \
        {"AXA", "AUA"},{"AUA", "ADL"},{"ANU", "EZE"},{"TIA", "ADL"},{"EZE", "ANU"},{"AUA", "ANU"} }; 
    // ["ICN", "AXA", "AUA", "ADL", "ANU", "AUA", "ANU", "EZE", "ADL", "EZE", "ANU", "ICN", "AXA", "EZE", "TIA", "AUA", "AXA", "TIA", "ADL", "EZE", "HBA"]

    std::cout << "====================== Travel Route Test Start ======================" << std::endl;

    std::cout << "Numbers : [ ";
    for (const auto& ele : tickets)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(tickets);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Travel Route Test Start ======================" << std::endl;
}
