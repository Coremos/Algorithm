#include <string>
#include <vector>

using namespace std;

string solution(string my_string)
{
    int length = my_string.length();
    string answer = my_string;
    for (int index = 0; index < length; index++)
    {
        answer[index] = my_string[length - index - 1];
    }
    return answer;
}