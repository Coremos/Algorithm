#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> SENTENCES = {"aya", "ye", "woo", "ma"};
map<string, char> babblingMap;

// Add permutation babble to a babblingMap
void permutation(int depth, int n, int r)
{
    if (depth == r)
    {
        string result;
        for (int i = 0; i < r; i++)
        {
            result += SENTENCES[i];
        }
        babblingMap.insert(make_pair(result, '\0'));
    }
    
    for (int i = depth; i < n; i++)
    {
        SENTENCES[depth].swap(SENTENCES[i]);
        permutation(depth + 1, n, r);
        SENTENCES[depth].swap(SENTENCES[i]);
    }
}

int solution(vector<string> babbling)
{
    int answer = 0;
    
    // Make a babblingMap
    for (int i = 1; i <= SENTENCES.size(); i++)
    {
        permutation(0, SENTENCES.size(), i);
    }
    
    // Count answer
    vector<string>::iterator iter;
    for (iter = babbling.begin(); iter != babbling.end(); iter++)
    {
        if (iter->empty()) continue;
        if (babblingMap.find(*iter) != babblingMap.end()) answer++;
    }
    
    return answer;
}