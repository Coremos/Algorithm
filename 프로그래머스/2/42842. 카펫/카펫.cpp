#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer(2);
    int sum = brown + yellow;
    
    for (int n = 1; n < sum; n++)
    {
        if (sum % n == 0)
        {
            int m = sum / n;
            if (n < m)
            {
                continue;
            }

            if (n + n + m + m - 4 == brown && (n - 2) * (m - 2) == yellow)
            {
                answer[0] = n;
                answer[1] = m;
                break;
            }
        }
    }
    return answer;
}