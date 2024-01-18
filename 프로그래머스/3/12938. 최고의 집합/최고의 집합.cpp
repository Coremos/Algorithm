#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s)
{
    if (n > s)
    {
        vector<int> answer = { -1 };
        return answer;
    }
    
    int quotient = s / n;
    vector<int> answer(n, quotient);
    int remain = s % n;
    for (int index = n - 1; remain > 0; index--)
    {
        answer[index] += 1;
        remain -= 1;
    }
    return answer;
}