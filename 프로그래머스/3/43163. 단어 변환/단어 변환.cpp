#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

#define MAX 50

using namespace std;

int solution(string begin, string target, vector<string> words)
{
    int start;
    int end;
    if (find(words.begin(), words.end(), begin) == words.end())
    {
        start = words.size();
        words.push_back(begin);
    }
    else
    {
        start = find(words.begin(), words.end(), begin) - words.begin();
    }
    
    if (find(words.begin(), words.end(), target) == words.end())
    {
        return 0;
    }
    else
    {
        end = find(words.begin(), words.end(), target) - words.begin();
    }
    
    bool wordMap[MAX][MAX] = { false };
    bool check[MAX] = { false };
    int bfs[MAX] = { 0 };
    queue<int> q;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            int count = 0;
            for (int k = 0; k < words[0].size() && count < 2; k++)
            {
                if (words[i][k] != words[j][k])
                {
                    count += 1;
                }
            }
            if (count == 1)
            {
                wordMap[j][i] = wordMap[i][j] = true;
            }
        }
    }

    bfs[start] = 0;
    q.push(start);
    check[start] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for (int index = 0; index < words.size(); index++)
        {
            if (current == index || check[index]) continue;
            if (!wordMap[current][index]) continue;
            q.push(index);
            check[index] = true;
            bfs[index] = bfs[current] + 1;
        }
        if (check[end]) break;
    }
    if (check[end]) return bfs[end];
    else return 0;
}