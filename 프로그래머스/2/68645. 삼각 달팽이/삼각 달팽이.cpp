#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int n)
{
    vector<int> answer((n * n + n) >> 1);
    int dx[] = {0, 1, -1};
    int dy[] = {1, 0, -1};
    int index = 1;
    int direction = 0;
    int x = 0;
    int y = 0;
    
    while (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            int pos = ((y * y + y) >> 1) + x;
            answer[pos] = index++;
            if (i == n - 1)
            {
                direction = ++direction % 3;
            }
            x += dx[direction];
            y += dy[direction];
        }
        n--;
    }
    
    return answer;
}