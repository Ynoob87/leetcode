#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

int longestValidParentheses(string s)
{
    int n = s.size();
    int count = 0;
    int maxCount = 0;
    stack<char> p;

    if (n <= 1)
        return 0;

    for (char c : s)
    {
        if (c == '(')
        {
            if (count > 0)
            {
                maxCount = count;
                count = 0;
            }
            p.push(c);
        }

        else if (!p.empty() && ((c == ')' && p.top() == '(')))
        {
            p.pop();
            count += 2;
        }
    }

    return count;
}
