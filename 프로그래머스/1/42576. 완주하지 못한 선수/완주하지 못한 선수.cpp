#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> maratoners;

string solution(vector<string> participant, vector<string> completion)
{
    for (int index = 0; index < participant.size(); index++)
    {
        maratoners[participant[index]]++;
    }
    for (int index = 0; index < completion.size(); index++)
    {
        maratoners[completion[index]]--;
    }
    
    for (auto iter = maratoners.begin(); iter != maratoners.end(); iter++)
    {
        if (iter->second > 0) return iter->first;
    }
}