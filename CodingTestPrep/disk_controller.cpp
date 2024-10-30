
#include	"heap_test.h"

#include	<iostream>
#include	<vector>
#include    <string>

#include    <algorithm>
#include    <queue>

static int solution1(std::vector<std::vector<int>> jobs) {
    int answer = 0;

    std::sort(jobs.begin(), jobs.end(), [](auto& lhs, auto& rhs) {
        if (lhs[0] == rhs[0])
        {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
        });

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    int idx = 0, now = jobs[idx][0];
    pq.push({ jobs[idx][1], jobs[idx][0] });
    idx++;
    while (!pq.empty())
    {
        auto [duration, start] = pq.top();
        pq.pop();

        answer += now - start;
        answer += duration;

        now += duration;

        while (idx < jobs.size() && jobs[idx][0] <= now)
        {
            pq.push({ jobs[idx][1], jobs[idx][0] });
            idx++;
        }

        if (pq.empty() && idx < jobs.size())
        {
            pq.push({ jobs[idx][1], jobs[idx][0] });
            now = jobs[idx][0];
            idx++;
        }
    }

    return answer / jobs.size();
}

void DiskControllerTest()
{
    std::vector<std::vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} }; // 9

    std::cout << "====================== Disk Controller Test Start ======================" << std::endl;

    std::cout << "Jobs : [ ";
    for (const auto& ele : jobs)
    {
        std::cout << "[ " << ele[0] << " " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(jobs);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Disk Controller Test End ======================" << std::endl;
}
