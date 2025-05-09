#include <iostream>
#include <cctype>

using namespace std;

bool isPalindrome(string s)
{
    string preString;

    for (char c : s)
        if (isalnum(c))
            preString += tolower(c);

    int i = 0;
    int j = preString.size() - 1;

    while (i <= j)
    {
        cout << preString[j];
        if (preString[i] != preString[j])
            return false;
        i++;
        j--;
    }

    return true;
}