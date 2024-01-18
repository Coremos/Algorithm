#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> que;

long long solution(int n, vector<int> works)
{
    long long answer = 0;
    for (int work : works)
    {
        que.push(work);
    }
    while (n > 0)
    {
        int top = que.top();
        que.pop();
        que.push(top - 1);
        n -= 1;
    }
    while (!que.empty())
    {
        int top = que.top();
        que.pop();
        if (top <= 0) continue;
        answer += top * top;
    }
    return answer;
}