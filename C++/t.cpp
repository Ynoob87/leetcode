#include <iostream>

int main()
{
    for (int i = 1; i <= 5; i++)
        std::cout << std::string(i, '*') << "\n";
    return 0;
}