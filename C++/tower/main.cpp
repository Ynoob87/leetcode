#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<stack<int>> stacks(3);

void move(int source, int target)
{
    int temp = stacks[source].top();
    stacks[source].pop();
    stacks[target].push(temp);
}

void solve(int n, int source, int target, int temp)
{
    if (n == 1)
    {
        move(source, target);
        return;
    }

    solve(n - 1, source, temp, target);
    move(source, target);
    solve(n - 1, temp, target, source);
}

int main()
{
    int n = 5;
    int source = 0;
    int target = 1;
    int temp = 2;

    for (int i = n; i >= 1; --i)
    {
        stacks[source].push(i);
    }

    solve(n, source, target, temp);

    for (int i = 0; i < n; i++)
    {
        cout << stacks[target].top() << "\n";
        stacks[target].pop();
    }

    return 0;
}