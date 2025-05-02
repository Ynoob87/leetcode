#include <iostream>

int main()
{
    int x = 5;
    int &rx = x;
    int *px = &rx;

    std::cout << rx << "\n";  // 5
    std::cout << px << "\n";  // 記憶體地址
    std::cout << *px << "\n"; // 5, **x
    std::cout << &rx << "\n"; // 記憶體地址, &&x

    return 0;
}