#include <string>
#include <vector>

#define MAX 100

using namespace std;

int numbers[MAX + 1];

int solution(vector<int> arr)
{
    int answer = 0;
    while (true)
    {
        answer += 1;
        for (int index = 0; index < arr.size(); index++)
        {
            if (answer % arr[index] != 0) break;
            if (index == arr.size() - 1) return answer;
        }
    }
}