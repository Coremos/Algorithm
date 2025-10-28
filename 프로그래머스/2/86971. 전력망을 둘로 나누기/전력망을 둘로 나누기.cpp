#include <string>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

vector<int> tree[MAX];

int bfs(int v1, int v2)
{
    int count = 1;
    vector<bool> visited(MAX);
    visited[v1] = true;
    visited[v2] = true;
    queue<int> q;
    q.push(v1);
    
    while (!q.empty())
    {
        int tower = q.front();
        q.pop();
        for (int next : tree[tower])
        {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
            count++;
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = MAX;
    
    for (const auto& wire : wires)
    {
        tree[wire[0]].push_back(wire[1]);
        tree[wire[1]].push_back(wire[0]);
    }
    
    for (const auto& wire : wires)
    {
        answer = min(answer, abs(n - bfs(wire[0], wire[1]) * 2));
    }
    
    return answer;
}