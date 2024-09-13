
#include	"set_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

static int Find(std::vector<int>& compacted, int node)
{
    if (compacted[node] == node)
    {
        return node;
    }

    compacted[node] = Find(compacted, compacted[node]);

    return compacted[node];
}

static void UnifySet(std::vector<int>& compacted, std::vector<int>& rank, int node1, int node2)
{
    int root1 = Find(compacted, node1);
    int root2 = Find(compacted, node2);

    if (root1 != root2)
    {
        if (rank[root1] < rank[root2])
        {
            compacted[root1] = root2;
        }
        else if (rank[root1] > rank[root2])
        {
            compacted[root2] = root1;
        }
        else
        {
            compacted[root2] = root1;
            rank[root1]++;
        }
    }
}

static std::vector<bool> solution1(int k, std::vector<std::vector<char>> ops)
{
    std::vector<bool> res;

    std::vector<int> compacted(k);
    for (int i = 0; i < k; ++i)
    {
        compacted[i] = i;
    }

    std::vector<int> rank(k, 0);

    for (const auto& ele : ops)
    {
        std::string tmp;
        tmp += ele[1];
        int node1 = std::atoi(tmp.c_str());
        tmp.clear();
        tmp += ele[2];
        int node2 = std::atoi(tmp.c_str());

        if ('u' == ele[0])
        {
            UnifySet(compacted, rank, node1, node2);
        }
        else // 'f' == ele[0]
        {
            res.push_back(Find(compacted, node1) == Find(compacted, node2));
        }
    }

    return res;
}

void SimpleUnionFindTest()
{
    int k = 3;
    std::vector<std::vector<char>> ops = { {'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}  }; // [true]

    //int k = 4;
    //std::vector<std::vector<char>> ops = { {'u', '0', '1'}, {'u', '2', '3'}, {'f', '0', '1'}, {'f', '0', '2'} }; // [true, false]

    std::cout << "====================== Simple Union Find Test Start ======================" << std::endl;

    std::cout << "Node Number : " << k << std::endl;
    std::cout << "Operations : [ ";
    for (const auto& ele : ops)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << ", " << ele[2] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(k, ops);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Simple Union Find Test End ======================" << std::endl;
}

