
#include	"simulation_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>
#include    <functional>

static std::vector<std::vector<int>> solution1(int n, std::vector<std::vector<int>> build_frame) {
    std::vector<std::vector<int>> answer;

    const int pillar = 1;
    const int roof = 2;
    std::vector<std::vector<int>> building(n + 1, std::vector<int>(n + 1, 0));

    auto isValid = [&](int x, int y) {
        return 0 <= x && n >= x && 0 <= y && n >= y;
        };

    auto isValidPillar = [&](int x, int y) {
        if (0 == y)
        {
            return true;
        }

        if (isValid(x, y - 1) && (pillar & building[x][y - 1]))
        {
            return true;
        }

        if (isValid(x - 1, y) && (roof & building[x - 1][y]))
        {
            return true;
        }

        if (roof & building[x][y])
        {
            return true;
        }

        return false;
        };

    auto isValidRoof = [&](int x, int y) {
        if (isValid(x, y - 1) && (pillar & building[x][y - 1]))
        {
            return true;
        }

        if (isValid(x + 1, y - 1) && (pillar & building[x + 1][y - 1]))
        {
            return true;
        }

        if (isValid(x - 1, y) && (roof & building[x - 1][y])
            && isValid(x + 1, y) && (roof & building[x + 1][y]))
        {
            return true;
        }

        return false;
        };

    auto isValidBuilding = [&]() {
        for (int x = 0; x < n + 1; ++x)
        {
            for (int y = 0; y < n + 1; ++y)
            {
                if (pillar & building[x][y])
                {
                    if (!isValidPillar(x, y))
                    {
                        return false;
                    }
                }
                if (roof & building[x][y])
                {
                    if (!isValidRoof(x, y))
                    {
                        return false;
                    }
                }
            }
        }

        return true;
        };

    for (const auto& ele : build_frame)
    {
        int x = ele[0];
        int y = ele[1];
        int part = ele[2] ? roof : pillar;
        int install = ele[3];

        if (install)
        {
            if (roof == part)
            {
                building[x][y] |= roof;
                if (!isValidBuilding())
                {
                    building[x][y] &= ~(roof);
                }
            }
            else
            {
                building[x][y] |= pillar;
                if (!isValidBuilding())
                {
                    building[x][y] &= ~(pillar);
                }
            }
        }
        else
        {
            if (roof == part)
            {
                building[x][y] &= ~(roof);
                if (!isValidBuilding())
                {
                    building[x][y] |= roof;
                }
            }
            else
            {
                building[x][y] &= ~(pillar);
                if (!isValidBuilding())
                {
                    building[x][y] |= pillar;
                }
            }
        }
    }

    for (int x = 0; x < n + 1; ++x)
    {
        for (int y = 0; y < n + 1; ++y)
        {
            if (roof & building[x][y])
            {
                answer.push_back({ x, y, 1 });
            }
            if (pillar & building[x][y])
            {
                answer.push_back({ x, y, 0 });
            }
        }
    }

    std::sort(answer.begin(), answer.end(), [](auto& lhs, auto& rhs) {
        if (lhs[0] == rhs[0])
        {
            if (lhs[1] == rhs[1])
            {
                return lhs[2] < rhs[2];
            }

            return lhs[1] < rhs[1];
        }

        return lhs[0] < rhs[0];
        });

    return answer;
}

void PillarAndRoofTest()
{
    //std::vector<std::vector<int>> build_frame = { {1,0,0,1} ,{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1} };
    //int n = 5; // [[1,0,0],[1,1,1],[2,1,0],[2,2,1],[3,2,1],[4,2,1],[5,0,0],[5,1,0]]

    std::vector<std::vector<int>> build_frame = { {0,0,0,1} ,{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} };
    int n = 5; // [[0,0,0],[0,1,1],[1,1,1],[2,1,1],[3,1,1],[4,0,0]]

    std::cout << "====================== Pillar And Roof Test Start ======================" << std::endl;

    std::cout << "Build Frame : " << std::endl;
    for (const auto& ele : build_frame)
    {
        std::cout << "[ x : " << ele[0] << ", y : " << ele[1] << ", part(0:pillar,1:roof) : " << ele[2] << ", install(0:uninstall,1:install) : " << ele[3] << " ] " << std::endl;
    }
    std::cout << std::endl;
    std::cout << "N : " << n << std::endl;

    auto res = solution1(n, build_frame);
    std::cout << "Result : " << std::endl;
    for (const auto& ele : res)
    {
        std::cout << "[ x : " << ele[0] << ", y : " << ele[1] << ", part : " << ele[2] << " ] " << std::endl;
    }
    std::cout << std::endl;

    std::cout << "====================== Pillar And Roof Test End ======================" << std::endl;
}
