#include <string>
#include <vector>
#include <iostream>
using namespace std;

int erasedZeroCount;

string eraseAndCountZero(string s)
{
    int length = s.length();
    int count = 0;
    
    for (int index = 0; index < length; index++)
    {
        char number = s.at(index);
        if (number == '1') count++;
    }
    
    erasedZeroCount += length - count;
    return s.assign(count, '1');
}

string convertToBinary(int length)
{
    string result = "";
    
    while (length > 0)
    {
        if ((length & 1) == 0) result = "0" + result;
        else result = "1" + result;
        
        length >>= 1;
    }
    
    return result;
}

vector<int> solution(string s)
{
    int count = 0;
    
    while (s.compare("1") != 0)
    {
        s = eraseAndCountZero(s);
        s = convertToBinary(s.length());
        count++;
    }
    
    vector<int> answer {count, erasedZeroCount};
    return answer;
}