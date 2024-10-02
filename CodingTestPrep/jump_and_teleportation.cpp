
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

#include    <bitset>

static int solution1(int n)
{
    int ans = 0;

    while (0 < n)
    {
        ans += n % 2;
        n /= 2;
    }

    return ans;
}

static int solution2(int n)
{
    return std::bitset<32>(n).count();
}

void JumpAndTeleportationTest()
{
    //int n = 5; // 2
    //int n = 6; // 2
    int n = 5000; // 5

    std::cout << "====================== Jump And Teleportation Test Start ======================" << std::endl;

    std::cout << "N : " << n  << std::endl;

    auto res = solution2(n);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Jump And Teleportation Test End ======================" << std::endl;
}
