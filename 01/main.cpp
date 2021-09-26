#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> readFile(string fileName)
{
    vector<int> res;
    ifstream readStream;
    readStream.open(fileName, ios::in);
    int number;
    while (readStream >> number)
    {
        res.push_back(number);
    }
    readStream.close();
    return res;
}

long part1(vector<int> &arr)
{
    const size_t n = arr.size();

    // // O(n^2)
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n - 1; j++)
    //     {
    //         if (arr[i] + arr[j] == 2020)
    //         {
    //             return arr[i] * arr[j];
    //         }
    //     }
    // }

    // O(n logn)
    sort(arr.begin(), arr.end()); // O(n logn)
    for (int i = 0; i < n; i++)   // O(n)
    {
        if (binary_search(arr.begin() + i, arr.end(), 2020 - arr[i])) // O(logn)
            return arr[i] * (2020 - arr[i]);
    }
    return -1;
}

long part2(vector<int> &arr)
{
    const size_t n = arr.size();
    // // O(n^3)
    // for (int i = 0; i < n - 2; i++)
    // {
    //     for (int j = i + 1; j < n - 1; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             if (arr[i] + arr[j] + arr[k] == 2020)
    //             {
    //                 return arr[i] * arr[j] * arr[k];
    //             }
    //         }
    //     }
    // }

    // O(n^2 logn)
    sort(arr.begin(), arr.end()); // O(n logn)
    for (int i = 0; i < n - 1; i++)
    { // O(n)
        for (int j = i + 1; j < n; j++)
        { // O(n)
            if (binary_search(arr.begin() + j, arr.end(), 2020 - arr[i] - arr[j]))
                return arr[i] * arr[j] * (2020 - arr[i] - arr[j]); // O(logn)
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = readFile("input.txt");
    long res = part1(arr);
    printf("Result : %d\n", res);
    return 0;
}