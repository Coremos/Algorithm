#include <iostream>

int main()
{
    int A;
    int B;
    
    std::cin >> A >> B;
    
    if (A > B)
    {
        std::cout << ">";
    }
    else if (A < B)
    {
        std::cout << "<";
    }
    else
    {
        std::cout << "==";
    }
}