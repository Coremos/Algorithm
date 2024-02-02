#include <string>
#include <vector>

#define MAX 21

using namespace std;

int solution(int n)
{
    int arr[MAX] = { 0 };
    int index = 0;
    int count = -1;
    int answer = 0;
    
    while (n > 0)
    {
        if (n & 1) arr[index] = 1;
        n >>= 1;
        index++;
    }
    
    index = 0;
    while (true)
    {
        if (arr[index] != 0)
        {
            arr[index] = 0;
            count++;
            if (arr[index + 1] == 0)
            {
                arr[index + 1] = 1;
                break;
            }
        }
        index++;
    }
    for (index = 0; index < count; index++)
    {
        arr[index] = 1;
    }
    
    count = 1;
    for (index = 0; index < MAX; index++)
    {
        if (arr[index])
        {
            answer += count;
        }
        count <<= 1;
    }
    return answer;
}