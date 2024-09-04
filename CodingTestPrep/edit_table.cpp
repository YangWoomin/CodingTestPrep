
#include	"stack_test.h"

#include	<iostream>
#include	<vector>
#include	<stack>
#include	<set>

static std::string solution1(int n, int k, const std::vector<std::string>& cmd) {
    std::string answer(n, 'O');
    int max = n - 1;

    std::stack<int> deleted;
    std::set<int> cache;
    for (const auto& ele : cmd)
    {
        if ('D' == ele[0])
        {
            int offset = std::atoi(ele.substr(2).c_str());
            auto near = cache.upper_bound(k);
            while (cache.end() != near)
            {
                if (k + offset >= *near)
                {
                    offset++;
                }
                else
                {
                    break;
                }

                std::advance(near, 1);
            }
            k += offset;
            continue;
        }
        else if ('U' == ele[0])
        {
            int offset = std::atoi(ele.substr(2).c_str());
            auto near = cache.lower_bound(k);
            if (cache.begin() != near && false == cache.empty())
            {
                near = std::prev(near);
            }
            else
            {
                near = cache.end();
            }
            while (cache.end() != near)
            {
                if (k - offset <= *near)
                {
                    offset++;
                }
                else
                {
                    break;
                }

                if (cache.begin() != near)
                {
                    std::advance(near, -1);
                }
                else
                {
                    break;
                }
            }
            k -= offset;
            continue;
        }
        else if ('C' == ele[0])
        {
            deleted.push(k);
            cache.insert(k);

            answer[k] = 'X';

            if (max == k)
            {
                while ('X' == answer[--max]);
                k = max;
            }
            else
            {
                while ('X' == answer[++k]);
            }
        }
        else // 'Z' == ele[0]
        {
            int last = deleted.top();
            deleted.pop();
            cache.erase(last);

            answer[last] = 'O';

            if (max < last)
            {
                max = last;
            }
        }
    }

    return answer;
}

void EditTableTest()
{
    int n = 8, k = 2;
    std::vector<std::string> cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" };
    //std::vector<std::string> cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C" };

    std::cout << "====================== Edit Table Test Start ======================" << std::endl;

    std::cout << "n : " << n << ", k : " << k << std::endl;
    std::cout << "Cmds : ";
    for (int i = 0; i < cmd.size(); ++i)
    {
        std::cout << "[ " << cmd[i] << " ]";

        if (i < cmd.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    
    std::string res = solution1(n, k, cmd);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Edit Table Test End ======================" << std::endl;
}
