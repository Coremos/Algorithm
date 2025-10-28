#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int answer = 0;
    int index = 0;
    int size = d.size();
    
    sort(d.begin(), d.end());
    
    while (index < size && budget >= d[index])
    {
        budget -= d[index++];
        answer++;
    }
    return answer;
}