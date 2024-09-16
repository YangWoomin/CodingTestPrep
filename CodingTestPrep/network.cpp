
#include	"graph_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <unordered_set>
#include    <functional>
#include    <stack>

// union-find
static int solution1(int n, std::vector<std::vector<int>> computers) {

    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
    }

    std::function<int(int)> getParent;
    getParent = [&getParent, &parent](int node) {
        if (node == parent[node])
        {
            return node;
        }

        parent[node] = getParent(parent[node]);
        return parent[node];
        };

    std::vector<int> rank(n);
    auto merge = [&](int node1, int node2) {
        int root1 = getParent(node1);
        int root2 = getParent(node2);
        if (root1 != root2)
        {
            if (rank[root1] < rank[root2])
            {
                parent[root1] = root2;
            }
            else
            {
                if (rank[root1] == rank[root2])
                {
                    rank[root1]++;
                }
                parent[root2] = root1;
            }
        }
        };

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (computers[i][j])
            {
                merge(i, j);
            }
        }
    }

    std::unordered_set<int> set;
    for (int i = 0; i < n; ++i)
    {
        set.insert(getParent(i));
    }

    return set.size();
}

// dfs
static int solution2(int n, std::vector<std::vector<int>> computers)
{
    int answer = 0;

    std::vector<bool> visit(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (visit[i])
        {
            continue;
        }

        answer++;

        std::stack<int> st;
        st.push(i);
        visit[i] = true;

        while (false == st.empty())
        {
            auto last = st.top();
            st.pop();

            for (int j = 0; j < n; ++j)
            {
                if (computers[last][j] && false == visit[j])
                {
                    visit[j] = true;
                    st.push(j);
                }
            }
        }
    }

    return answer;
}

void NetworkTest()
{
	int n = 3;
	std::vector<std::vector<int>> computers = { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } }; // 2

    //int n = 3;
    //std::vector<std::vector<int>> computers = { { 1, 1, 0 }, { 1, 1, 1 }, { 0, 1, 1 } }; // 1

	std::cout << "====================== Network Test Start ======================" << std::endl;

	std::cout << "Computers : " << std::endl;
	for (const auto& ele : computers)
	{
		std::cout << "[ " << ele[0] << ", " << ele[1] << ", " << ele[2] << " ] ";
	}
	std::cout << std::endl;

	auto res = solution2(n, computers);
	std::cout << "Result : " << res << std::endl;

	std::cout << "====================== Network Test Start ======================" << std::endl;
}
