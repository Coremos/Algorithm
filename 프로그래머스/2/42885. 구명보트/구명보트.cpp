#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int index = 0;
    
    sort(people.begin(), people.end());
    
    while (index < people.size())
    {
        if (people[index] + people.back() <= limit) index++;
        people.pop_back();
        answer++;
    }
    
    return answer;
}