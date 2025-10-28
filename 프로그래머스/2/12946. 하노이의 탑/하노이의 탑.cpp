#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int temp, vector<vector<int>> &answer)
{
    vector<int> v;
    v.push_back(from);
    v.push_back(to);
    
    if (n == 1)
    {
        answer.push_back(v);
        return;
    }
    
    hanoi(n - 1, from, temp, to, answer);
    answer.push_back(v);
    hanoi(n - 1, temp, to, from, answer);
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}