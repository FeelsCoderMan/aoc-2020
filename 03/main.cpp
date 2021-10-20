#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> readFile(std::string fileName)
{
    std::ifstream inFile(fileName);
    std::string line;
    std::vector<std::string> res;
    while (std::getline(inFile, line))
    {
        res.push_back(line);
    }
    return res;
}

int main()
{
    std::vector<std::string> inputVec = readFile("input.txt");
    int rows = inputVec.size();
    int columns = inputVec[0].size();
    int x = 0;
    int y = 0;
    int moveX = 1;
    int moveY = 3;
    int countTree = 0;
    while (x < rows)
    {
        if (inputVec[x][y] == '#')
        {
            countTree++;
        }
        x += moveX;
        y = (y + moveY) % columns;
    }
    std::cout << countTree;
    return 0;
}
