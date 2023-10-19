#include <string>
#include <vector>

using namespace std;

int result;

void calc(vector<int> numbers, int index, int sum, int oper, int target)
{
    sum += numbers[index++] * oper;
    if (index < numbers.size())
    {
        calc(numbers, index, sum, 1, target);
        calc(numbers, index, sum, -1, target);
    }
    else if (sum == target) 
    {
        result++;
    }
}

int solution(vector<int> numbers, int target)
{
    calc(numbers, 0, 0, 1, target);
    calc(numbers, 0, 0, -1, target);
    int answer = result;
    
    return answer;
}