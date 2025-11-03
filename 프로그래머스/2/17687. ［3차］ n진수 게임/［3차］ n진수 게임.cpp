#include <string>
#include <vector>

using namespace std;

string digits = "0123456789ABCDEF";

string convertToBase(int number, int base)
{
    string result = "";
    if (number == 0)
    {
        return "0";
    }
    
    while (number > 0)
    {
        result += digits[number % base];
        number /= base;
    }
    return result;
}

string solution(int n, int t, int m, int p)
{
    string answer = "";
    
    int index = 0;
    int number = 0;
    int count = 0;
    
    // 최적화 가능
    while (count < t)
    {
        string digitsString = convertToBase(index++, n);
        int size = digitsString.size() - 1;
        while (size >= 0 && count < t)
        {
            if (++number > m)
            {
                number = 1;
            }
            if (number == p)
            {
                answer += digitsString[size];
                count++;
            }

            size--;
        }
    }
    
    return answer;
}