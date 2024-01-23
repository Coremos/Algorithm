#include<vector>
#include<queue>

#define MAX 100

using namespace std;

int solution(vector<vector<int>> maps)
{
    bool check[MAX][MAX] = { false };
    int bfs[MAX][MAX] = { 0 };
    int deltaX[] = { -1, 1, 0, 0 };
    int deltaY[] = { 0, 0, -1, 1 };
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    check[0][0] = true;
    bfs[0][0] = 1;
    
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        
        for (int direction = 0; direction < 4; direction++)
        {
            int newX = current.second + deltaX[direction];
            int newY = current.first + deltaY[direction];
            
            if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
            if (check[newY][newX] || maps[newY][newX] == 0) continue;
            bfs[newY][newX] = bfs[current.first][current.second] + 1;
            check[newY][newX] = true;
            q.push(make_pair(newY, newX));
        }
    }
    
    if (check[n - 1][m - 1]) return bfs[n - 1][m- 1];
    else return -1;
}