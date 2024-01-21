#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int length = s.length();
    if (length & 1)
    {
        answer = s[length >> 1];
    }
    else
    {
        length >>= 1;
        answer = s.substr(length - 1, 2);
    }
    
    return answer;
}