#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

bool isValid(string s)
{
    int n = s.size();
    stack<char> p;

    if (n <= 1)
        return false;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            p.push(c);
        else if (!p.empty() &&
                 ((c == ')' && p.top() == '(') ||
                  (c == ']' && p.top() == '[') ||
                  (c == '}' && p.top() == '{')))
        {
            p.pop();
            n -= 2;
        }
    }

    return p.empty() && n == 0;
}