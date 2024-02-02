#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int solution(int k, vector<int> tangerine)
{
    int answer = 0;
    map<int, int> numbers;
    for (int number : tangerine)
    {
        numbers[number] += 1;
    }
    vector<pair<int, int>> values(numbers.begin(), numbers.end());
    sort(values.begin(), values.end(), compare);
    
    while (k > 0)
    {
        answer += 1;
        k -= values[values.size() - answer].second;
    }
    return answer;
}