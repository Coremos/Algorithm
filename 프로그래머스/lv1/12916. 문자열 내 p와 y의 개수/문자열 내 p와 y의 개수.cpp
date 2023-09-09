#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    
    int length = s.length();
    for (int index = 0; index < length; index++)
    {
        char c = s.at(index);
        if (c == 'p' || c == 'P') p++;
        else if (c == 'y' || c == 'Y') y++;
    }
    
    if (p != y) answer = false;

    return answer;
}