
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <climits>
#include	<queue>
#include	<unordered_map>

// dijkstra
static int solution1(int N, std::vector<std::vector<int> > road, int K) {
    int answer = 0;

    std::vector<std::unordered_map<int, int>> graph(N + 1);
    for (const auto& ele : road)
    {
        if (0 == graph[ele[0]][ele[1]])
        {
            graph[ele[0]][ele[1]] = ele[2];
            graph[ele[1]][ele[0]] = ele[2];
        }
        else if (0 < graph[ele[0]][ele[1]] && graph[ele[0]][ele[1]] > ele[2])
        {
            graph[ele[0]][ele[1]] = ele[2];
            graph[ele[1]][ele[0]] = ele[2];
        }
    }

    std::vector<int> cost(N + 1, INT_MAX);
    cost[1] = 0;
    std::vector<bool> visited(N + 1, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({ 0, 1 });

    int count = 0;
    while (count < N)
    {
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
        {
            continue;
        }

        visited[cur] = true;
        count++;

        for (const auto& [next, weight] : graph[cur])
        {
            int newCost = cost[cur] + weight;
            if (newCost < cost[next])
            {
                cost[next] = newCost;
                pq.push({ cost[next], next });
            }
        }
    }

    for (int i = 1; i < cost.size(); ++i)
    {
        if (cost[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}

// bellman ford
static int solution2(int N, std::vector<std::vector<int> > road, int K) {
    int answer = 0;

    std::vector<std::vector<int>> graph = road;
    for (auto& ele : road)
    {
        graph.push_back({ ele[1], ele[0], ele[2] });
    }

    std::vector<int> cost(N + 1, INT_MAX);
    cost[1] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (const auto& ele : graph)
        {
            int from = ele[0];
            int to = ele[1];
            int weight = ele[2];

            if (INT_MAX != cost[from])
            {
                int newCost = cost[from] + weight;
                if (newCost < cost[to])
                {
                    cost[to] = newCost;
                }
            }
        }
    }

    for (int i = 1; i < cost.size(); ++i)
    {
        if (cost[i] <= K)
        {
            answer++;
        }
    }

    return answer;
}

void DeliveryTest()
{
	int N = 5, K = 3;
    std::vector<std::vector<int>> road = { { 1, 2,1 }, { 2, 3, 3 }, { 5, 2, 2 }, { 1, 4, 2 }, { 5, 3, 1 }, { 5, 4, 2 } }; // 4

    //int N = 6, K = 4;
    //std::vector<std::vector<int>> road = { { 1, 2, 1 }, { 1, 3, 2 }, { 2, 3, 2 }, { 3, 4, 3 }, { 3, 5, 2}, { 3, 5, 3 }, { 5, 6, 1 } }; // 4

	std::cout << "====================== Delivery Test Start ======================" << std::endl;

	std::cout << "N : " << N << ", K : " << K << std::endl;
	std::cout << "Road : [ ";
	for (const auto& ele : road)
	{
		std::cout << "[ " << ele[0] << ", " << ele[1] << ", " << ele[2] << " ] ";
	}
	std::cout << "]" << std::endl;

	auto res = solution2(N, road, K);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Delivery Test Start ======================" << std::endl;
}
