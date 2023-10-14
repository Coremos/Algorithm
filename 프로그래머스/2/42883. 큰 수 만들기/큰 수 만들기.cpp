#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
    
    // 12345 / 2
    // position = 0
    // k = 2
    // 
    int maxIndex = 0;
    int peek = 0;
    int position = 0;
    int length = number.length();
    int targetLength = number.length() - k;
    string answer = string(targetLength, '0');
    while (peek < targetLength)
    {
        if (k)
        {
            for (int i = position; i - position <= k; i++)
            {
                if (number[i] > number[maxIndex])
                {
                    maxIndex = i;
                }
            }
            answer[peek] = number[maxIndex];
            k -= maxIndex - position;
            position = ++maxIndex;
            cout << k << endl;
        }
        else
        {
            answer[peek] = number[position++];
        }
        peek++;
    }

    
    return answer;
}