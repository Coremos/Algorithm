#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Process
{
    int priority;
    int index;
};

int solution(vector<int> priorities, int location)
{
    int index = 0;
    priority_queue<int> pq;
    queue<Process> q;
    
    for (int priority : priorities)
    {
        pq.push(priority);
        q.push({priority, index++});
    }
    
    index = 1;
    while (!q.empty())
    {
        Process process = q.front();
        q.pop();
        if (process.priority < pq.top())
        {
            q.push(process);
            continue;
        }
        
        pq.pop();
        if (process.index == location)
        {
            return index;
        }
        index++;
    }
    
    return 0;
}