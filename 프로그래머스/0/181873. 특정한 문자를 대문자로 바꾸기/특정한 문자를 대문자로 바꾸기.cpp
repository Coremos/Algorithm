#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    for (string::size_type index = 0; index < my_string.length(); index++)
    {
        if (my_string[index] == alp[0]) my_string[index] += 'A' - 'a';
    }
    return my_string;
}