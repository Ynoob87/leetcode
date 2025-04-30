#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int lengthOfLastWord(string s)
{
    vector<string> words = split(s, ' ');

    return words.back().length();
}