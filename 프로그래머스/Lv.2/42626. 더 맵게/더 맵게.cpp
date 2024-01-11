#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> foods(scoville.begin(), scoville.end());
    while (foods.size() >= 2 && foods.top() < K)
    {
        count += 1;
        int firstFood = foods.top();
        foods.pop();
        int secondFood = foods.top();
        foods.pop();
        foods.push(firstFood + (secondFood << 1));
    }
    if (foods.top() < K) return -1;
    return count;
}