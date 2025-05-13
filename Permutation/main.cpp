#include <iostream>

using namespace std;

// 計算階乘的函式
long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

// 計算排列數 P(n, r)
long long permutation(int n, int r)
{
    return factorial(n) / factorial(n - r);
}
// 計算組合數 P(n, r)
long long combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main()
{
    int n = 3; // 總數量
    int r = 2; // 選擇數量

    // 計算排列數
    cout << "P(" << n << ", " << r << ") = " << permutation(n, r) << endl;

    // 計算組合數
    cout << "C(" << n << ", " << r << ") = " << combination(n, r) << endl;
    return 0;
}