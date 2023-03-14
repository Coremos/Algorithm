#include <iostream>

int main()
{
    int score;
    
    std::cin >> score;
    
    if (score > 89)
    {
        std::cout << "A";
    }
    else if (score > 79)
    {
        std::cout << "B";
    }
    else if (score > 69)
    {
        std::cout << "C";
    }
    else if (score > 59)
    {
        std::cout << "D";
    }
    else
    {
        std::cout << "F";
    }
}