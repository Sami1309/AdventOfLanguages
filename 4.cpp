#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

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

int calculateHashSuffix(string input)
{

    return 0;
}

int main()
{
    string filename = "data/4.in";
    string input = parseData(filename);

    int hashSuffix = calculateHashSuffix(input);

    cout << hashSuffix << endl; // Part 1 answer
}