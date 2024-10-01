
#include	"sort_test.h"

#include	<iostream>
#include    <vector>
#include    <string>
#include    <functional>
#include    <algorithm>

struct File
{
    std::string _name;
    std::string _head;
    int _number;
    int _idx;

    bool operator<(const File& other)
    {
        if (_head == other._head)
        {
            if (_number == other._number)
            {
                return _idx < other._idx;
            }

            return _number < other._number;
        }

        return _head < other._head;
    }
};

static std::vector<std::string> solution1(std::vector<std::string> files) {
    std::vector<std::string> answer;

    std::vector<File> fs;
    for (int i = 0; i < files.size(); ++i)
    {
        std::string head, tmp;
        int number = -1;
        for (const auto& ele : files[i])
        {
            if (head.empty() && 48 <= ele && 57 >= ele)
            {
                head = tmp;
                tmp.clear();
            }
            else if (!head.empty() && (48 > ele || 57 < ele))
            {
                number = std::atoi(tmp.c_str());
                break;
            }
            tmp += ele;
        }
        if (-1 == number)
        {
            number = std::atoi(tmp.c_str());
        }

        std::transform(head.begin(), head.end(), head.begin(), [](unsigned char c) {
            return std::tolower(c);
            });

        File file;
        file._name = files[i];
        file._head = head;
        file._number = number;
        file._idx = i;
        fs.push_back(file);
    }

    std::sort(fs.begin(), fs.end());

    for (const auto& ele : fs)
    {
        answer.push_back(ele._name);
    }

    return answer;
}

void FileNameSortTest()
{
    //std::vector<std::string> fileNames = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" }; // ["img1.png", "IMG01.GIF", "img02.png", "img2.JPG", "img10.png", "img12.png"]
    std::vector<std::string> fileNames = { "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" }; // ["A-10 Thunderbolt II", "B-50 Superfortress", "F-5 Freedom Fighter", "F-14 Tomcat"]

    std::cout << "====================== File Name Sort Test Start ======================" << std::endl;

    std::cout << "File Names : [ ";
    for (const auto& ele : fileNames)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    auto res = solution1(fileNames);
    std::cout << "Result : [ ";
    for (const auto& ele : res)
    {
        std::cout << ele << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "====================== File Name Sort Test End ======================" << std::endl;
}
