#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "helpers/md5.h"

using namespace std;

string parseData(string filename)
{
    ifstream input;
    input.open(filename);

    if (!input.is_open())
    {
        throw runtime_error("Cannot open file");
    }

    string data;
    getline(input, data);

    input.close();

    return data;
}

int calculateHashSuffix(string input, int numZeroes)
{
    string zeroString = "";

    for (int i = 0; i < numZeroes; i++)
    {
        zeroString += "0";
    }

    string prefix = "";
    int num = 0;
    string key;

    while (prefix.compare(zeroString) != 0)
    {
        key = input + to_string(num);
        prefix = md5(key).substr(0, numZeroes);
        num++;
    }

    return num - 1;
}

int main()
{
    string filename = "data/4.in";
    string input = parseData(filename);

    int hashSuffix5 = calculateHashSuffix(input, 5);

    cout << hashSuffix5 << endl; // Part 1 answer

    int hashSuffix6 = calculateHashSuffix(input, 6);

    cout << hashSuffix6 << endl; //Part 2 answer
}