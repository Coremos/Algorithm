#include <string>
#include <vector>

using namespace std;

bool visited[200];

int count;

void dfs(int number, vector<vector<int>> computers)
{
    if (visited[number]) return;
    visited[number] = true;
    count++;
    
    for (int i = 0; i < computers[number].size(); i++)
    {
        if (visited[i]) continue;
        if (computers[number][i])
        {
            dfs(i, computers);
            count--;
        }
    }
}
    
int solution(int n, vector<vector<int>> computers)
{
    for (int i = 0; i < n; i++)
    {
        dfs(i, computers);
    }
    return count;
}