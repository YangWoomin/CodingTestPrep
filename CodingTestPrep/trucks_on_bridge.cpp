
#include	"queue_test.h"

#include	<iostream>
#include	<vector>
#include    <queue>

static int solution1(int bridge_length, int weight, std::vector<int> truck_weights) {
    int answer = 0;

    std::queue<int> bridge;
    for (int i = 0; i < bridge_length; ++i)
    {
        bridge.push(0);
    }

    int idx = 0, comple = 0, total_weight = 0, len = 0;
    while (truck_weights.size() > comple)
    {
        // pop from bridge
        int passed = bridge.front();
        bridge.pop();
        if (0 < passed)
        {
            total_weight -= passed;
            comple++;
            len--;
        }

        // push to bridge
        int w = 0;
        if (bridge_length > len
            && truck_weights.size() > idx
            && weight >= total_weight + truck_weights[idx])
        {
            w = truck_weights[idx];
            idx++;
            len++;
        }
        total_weight += w;
        bridge.push(w);

        // increase tick
        answer++;
    }

    return answer;
}

void TrucksOnBridgeTest()
{
    /*int bridge_length = 2, weight = 10;
    std::vector<int> truck_weights = { 7,4,5,6 };*/

    /*int bridge_length = 100, weight = 100;
    std::vector<int> truck_weights = { 10 };*/

    int bridge_length = 100, weight = 100;
    std::vector<int> truck_weights = { 10,10,10,10,10,10,10,10,10,10};

    std::cout << "====================== Trucks On Bridge Test Start ======================" << std::endl;

    std::cout << "Bridge Length : " << bridge_length << ", Weight : " << weight << std::endl;
    std::cout << "Truck Weigts : [ ";
    for (const auto& ele : truck_weights)
    {
        std::cout << ele << " ";
    }
    std::cout << " ]" << std::endl;

    int res = solution1(bridge_length, weight, truck_weights);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Trucks On Bridge Test End ======================" << std::endl;
}