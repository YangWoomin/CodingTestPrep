
#include	"stack_test.h"

#include	<iostream>
#include	<string>
#include	<stack>

bool isOpenBracket(const char ch)
{
    if ('[' == ch
        || '{' == ch
        || '(' == ch)
    {
        return true;
    }

    return false;
}

bool isCorrect(const char open, const char close)
{
    if ('[' == open && ']' == close)
    {
        return true;
    }
    if ('{' == open && '}' == close)
    {
        return true;
    }
    if ('(' == open && ')' == close)
    {
        return true;
    }
    return false;
}

static int solution1(std::string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        std::stack<char> tmp;
        char first = s[0];
        s = s.substr(1, s.size());
        s += first;
        bool success = true;

        for (const auto& ele : s)
        {
            if (true == isOpenBracket(ele))
            {
                tmp.push(ele);
                continue;
            }

            if (true == tmp.empty())
            {
                success = false;
                break;
            }

            char last = tmp.top();
            if (false == isCorrect(last, ele))
            {
                success = false;
                break;
            }

            tmp.pop();
        }

        if (true == success && true == tmp.empty())
        {
            answer++;
        }
    }

    return answer;
}

bool isValid(const std::string& s, int idx)
{
    std::stack<char> tmp;

    for (int i = 0; i < s.size(); ++i)
    {
        char ch = s[(i + idx) % s.size()];

        if (true == isOpenBracket(ch))
        {
            tmp.push(ch);
            continue;
        }

        if (true == tmp.empty())
        {
            return false;
        }

        char last = tmp.top();
        if (false == isCorrect(last, ch))
        {
            return false;
        }

        tmp.pop();
    }

    return tmp.empty();
}

static int solution2(std::string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        answer += isValid(s, i);
    }

    return answer;
}

void RotateBracketTest()
{
    std::string s = "[](){}"; // 3
    //std::string s = "}]()[{"; // 2
    //std::string s = "[)(]"; // 0
    //std::string s = "}}}"; // 0

    std::cout << "====================== Rotate Bracket Test Start ======================" << std::endl;

    std::cout << "Bracket : " << s << std::endl;

    int res = solution2(s);

    std::cout << "Result : " << res << std::endl;

    std::cout << "====================== Rotate Bracket Test End ======================" << std::endl;
}
