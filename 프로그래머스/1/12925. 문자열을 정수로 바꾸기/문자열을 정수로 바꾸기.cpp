#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int ten = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '+')
        {
            continue;
        }
        else if (s[i] == '-')
        {
            answer *= -1;
            continue;
        }
        answer += ten * (s[i] - '0');
        ten *= 10;
    }
    return answer;
}