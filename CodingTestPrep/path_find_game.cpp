
#include	"tree_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <unordered_map>
#include    <algorithm>

struct Node
{
    int _num = 0;
    int _x = 0;
    Node* _left = nullptr;
    Node* _right = nullptr;

    ~Node()
    {
        if (nullptr != _left)
        {
            delete _left;
            _left = nullptr;
        }

        if (nullptr != _right)
        {
            delete _right;
            _right = nullptr;
        }
    }

    void Insert(int num, int x)
    {
        if (0 == _num)
        {
            _num = num;
            _x = x;
            return;
        }

        if (x < _x)
        {
            if (nullptr == _left)
            {
                _left = new Node();
            }
            _left->Insert(num, x);
        }
        else // x > _x
        {
            if (nullptr == _right)
            {
                _right = new Node();
            }
            _right->Insert(num, x);
        }
    }

    void PreorderSearch(std::vector<int>& out)
    {
        out.push_back(_num);

        if (nullptr != _left)
        {
            _left->PreorderSearch(out);
        }

        if (nullptr != _right)
        {
            _right->PreorderSearch(out);
        }
    }

    void PostorderSearch(std::vector<int>& out)
    {
        if (nullptr != _left)
        {
            _left->PostorderSearch(out);
        }

        if (nullptr != _right)
        {
            _right->PostorderSearch(out);
        }

        out.push_back(_num);
    }
};

static std::vector<std::vector<int>> solution1(std::vector<std::vector<int>> nodeinfo) {
    std::vector<std::vector<int>> answer(2);

    std::unordered_map<int/* x */, int /* node num */> nodes;
    for (int i = 0; i < nodeinfo.size(); ++i)
    {
        nodes[nodeinfo[i][0]] = i + 1;
    }

    std::vector<std::vector<int>> sorted = nodeinfo;
    std::sort(sorted.begin(), sorted.end(), [](auto lhs, auto rhs) {
        if (lhs[1] == rhs[1])
        {
            return lhs[0] < rhs[0];
        }
        return lhs[1] > rhs[1];
        });

    Node* root = new Node();
    for (const auto& ele : sorted)
    {
        root->Insert(nodes[ele[0]], ele[0]);
    }

    root->PreorderSearch(answer[0]);
    root->PostorderSearch(answer[1]);

    delete root;

    return answer;
}

void PathFindGameTest()
{
    std::vector<std::vector<int>> nodeinfo = { { 5, 3 }, { 11, 5 }, { 13, 3 }, { 3, 5 }, { 6, 1 }, { 1, 3 }, { 8, 6 }, { 7, 2 }, { 2, 2 } }; // [[7,4,6,9,1,8,5,2,3],[9,6,5,8,1,4,3,2,7]]

    std::cout << "====================== Path Find Game Test Start ======================" << std::endl;

    std::cout << "Nodes : [ ";
    for (const auto& ele : nodeinfo)
    {
        std::cout << "[ " << ele[0] << ", " << ele[1] << " ] ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(nodeinfo);
    std::cout << "Result 1 : [ ";
    for (const auto& ele : res[0])
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Result 2 : [ ";
    for (const auto& ele : res[1])
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== Path Find Game Test End ======================" << std::endl;
}
