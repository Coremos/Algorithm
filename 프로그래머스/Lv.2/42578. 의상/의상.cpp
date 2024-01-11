#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<string>> wear;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;
    
    for (auto clothPair : clothes)
    {
        wear[clothPair[1]].push_back(clothPair[0]);
    }
    
    for (auto v : wear)
    {
        answer *= v.second.size() + 1;
    }
    
    return answer - 1;
}