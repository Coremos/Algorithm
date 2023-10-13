#include <string>
#include <vector>

using namespace std;

int lost_people[31];
int reserve_people[31];
int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = n;

    for (auto i : reserve)
    {
        reserve_people[i] = 1;
    }
    
    for (auto i : lost)
    {
        if (reserve_people[i]) 
        {
            reserve_people[i] = 0;
            continue;
        }
        lost_people[i] = 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (lost_people[i])
        {
            if (reserve_people[i - 1])
            {
                reserve_people[i - 1]--;
                continue;
            }
            else if (reserve_people[i + 1])
            {
                reserve_people[i + 1]--;
                continue;
            }
            answer--;
        }
    }
    
    return answer;
}