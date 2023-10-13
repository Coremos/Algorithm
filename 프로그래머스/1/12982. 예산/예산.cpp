#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;
    int index = 0;
    
    sort(d.begin(), d.end());
    
    while (budget > 0)
    {
        if (d[index] > budget || index >= d.size()) break;
        
        budget -= d[index++];
        answer++;
    }
    return answer;
}