#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

struct Result
{
    int minAppear;
    int maxAppear;
    char letter;
    std::string word;
};

std::vector<Result> readFile(std::string fileName)
{
    std::ifstream inFile(fileName);
    std::string line;
    std::vector<Result> res;
    int delimiterLength = 1;
    while (std::getline(inFile, line))
    {
        std::string part1 = line.substr(0, line.find(" "));
        int minAppear = stoi(part1.substr(0, line.find("-")));
        part1.erase(0, part1.find("-") + delimiterLength);
        int maxAppear = stoi(part1);
        line.erase(0, line.find(" ") + delimiterLength);
        std::string part2 = line.substr(0, line.find(" "));
        char letter = part2.at(0);
        line.erase(0, line.find(" ") + delimiterLength);
        std::string word = line;
        struct Result r;
        r.minAppear = minAppear;
        r.maxAppear = maxAppear;
        r.letter = letter;
        r.word = word;
        res.push_back(r);
    }
    return res;
}

int partOne(std::vector<Result> &arr)
{
    int totalValid = 0;
    for (Result &res : arr)
    {
        int countValid = 0;
        for (int i = 0; i < res.word.size(); i++) // O(n)
        {
            if (res.letter == res.word.at(i))
            {
                countValid++;
            }
        }
        if (countValid >= res.minAppear && countValid <= res.maxAppear)
        {
            totalValid++;
        }
    }
    return totalValid;
}

int partTwo(std::vector<Result> &arr)
{
    int count = 0;
    for (Result res : arr)
    {
        if (res.maxAppear-1 < (int)res.word.size()) //O(1)
        {
            bool isPos1Valid = (res.letter == res.word.at(res.minAppear-1));
            bool isPos2Valid = (res.letter == res.word.at(res.maxAppear-1));
            if (isPos1Valid != isPos2Valid)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    std::vector<Result> data = readFile("input.txt");
    int countValid = partTwo(data);
    std::cout << countValid << std::endl;
    return 0;
}
