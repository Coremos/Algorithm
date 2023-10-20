#include <string>
#include <vector>

using namespace std;

long long dp[101][101];
const long long DIVIDER = 1000000007;


int solution(int m, int n, vector<vector<int>> puddles)
{
    dp[1][1] = 1;
    for (int i = 0; i < puddles.size(); i++)
    {
        dp[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (dp[x][y] == -1) continue;
            if (y > 0 && dp[x - 1][y] != -1)
            {
                dp[x][y] += dp[x - 1][y];
            }
            if (x > 0 && dp[x][y - 1] != -1)
            {
                dp[x][y] += dp[x][y - 1];
            }
            dp[x][y] %= DIVIDER;
        }
    }
    
    return dp[m][n];
}