#include <string>
#include <vector>

using namespace std;

int getSum(int number)
{
    int result = 0;
    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }
    return result;
}

bool solution(int x)
{
    int sum = getSum(x);
    bool answer = (x % sum == 0);
    return answer;
}