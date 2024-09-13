
#include	"tree_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

void findMax(const std::vector<std::vector<int>>& edges, int pre, int cur, int except, int& max, int& num)
{
    int size = edges[cur].size(), _max = -1, _num = 0;
    for (int i = 0; i < size; ++i)
    {
        int next = edges[cur][i];
        if (1 == size && pre == next)
        {
            max = 0;
            num = cur;
            return;
        }
        else if (pre != next)
        {
            int tmpMax = 0, tmpNum = 0;
            findMax(edges, cur, next, except, tmpMax, tmpNum);
            if (tmpMax > _max && tmpNum != except)
            {
                _max = tmpMax;
                _num = tmpNum;
            }
            else if (tmpNum == except)
            {
                _num = cur;
            }
        }
    }

    max = _max + 1;
    num = _num;
}

void find(const std::vector<std::vector<int>>& edges, int pre, int cur, int target, int& len)
{
    int size = edges[cur].size();
    for (int i = 0; i < size; ++i)
    {
        int next = edges[cur][i];
        if (target == next)
        {
            len++;
            return;
        }
        else if (1 == size && pre == next)
        {
            return;
        }
        else if (pre != next)
        {
            find(edges, cur, next, target, len);
            if (0 < len)
            {
                len++;
                return;
            }
        }
    }
}

static int solution1(int n, std::vector<std::vector<int>> edges) {
    int answer = 0;

    std::vector<std::vector<int>> edges2(n + 1);
    for (const auto& edge : edges)
    {
        edges2[edge[0]].push_back(edge[1]);
        edges2[edge[1]].push_back(edge[0]);
    }

    int max1 = 0, num1 = 0;
    findMax(edges2, 0, 1, 0, max1, num1);
    //std::cout << "Num1 : " << num1 << ", Max1 : " << max1 << std::endl;

    int max2 = 0, num2 = 0;
    findMax(edges2, 0, num1, 0, max2, num2);
    //std::cout << "Num2 : " << num2 << ", Max2 : " << max2 << std::endl;

    int max3 = 0, num3 = 0;
    findMax(edges2, 0, num1, num2, max3, num3);
    //std::cout << "Num3 : " << num3 << ", Max3 : " << max3 << std::endl;

    int len3 = 0;
    find(edges2, 0, num2, num3, len3);
    //std::cout << "Length from Num2(" << num2 << ") to Num3(" << num3 << ") : " << len3 << std::endl;

    int max4 = 0, num4 = 0;
    findMax(edges2, 0, num2, num1, max4, num4);
    //std::cout << "Num4 : " << num4 << ", Max4 : " << max4 << std::endl;

    int len4 = 0;
    find(edges2, 0, num1, num4, len4);
    //std::cout << "Length from Num1(" << num1 << ") to Num4(" << num4 << ") : " << len4 << std::endl;

    int answer1 = max3 < len3 ? len3 : max3;
    int answer2 = max4 < len4 ? len4 : max4;

    return answer1 > answer2 ? answer1 : answer2;
}

void TreeTrioMiddleValueTest()
{
    //int n = 4;
    //std::vector<std::vector<int>> edges = { { 1, 2 }, { 2, 3 }, { 3, 4 } }; // 2

    int n = 5;
    std::vector<std::vector<int>> edges = { { 1, 5 }, { 2, 5 }, { 3, 5 }, { 4, 5 } }; // 2

    std::cout << "====================== Tree Trio Middle Value Test Start ======================" << std::endl;

    std::cout << "Edges : [ ";
    for (const auto& ele : edges)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(n, edges);
    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Tree Trio Middle Value Test End ======================" << std::endl;
}
