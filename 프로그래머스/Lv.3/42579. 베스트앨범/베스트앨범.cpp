#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct cmp
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};


bool compareGenre(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>> album;
    map<string, int> counter;
    vector<int> answer;
    
    for (int index = 0; index < genres.size(); index++)
    {
        counter[genres[index]] += plays[index];
        album[genres[index]].push(make_pair(plays[index], index));
    }
    
    vector<pair<string, int>> a(counter.begin(), counter.end());
    sort(a.begin(), a.end(), compareGenre);
    
    for (auto genre : a)
    {
        auto q = album[genre.first];
        int count = 0;
        while (!q.empty() && count < 2)
        {
            count++;
            answer.push_back(q.top().second);
            q.pop();
        }
    }
    
    return answer;
}