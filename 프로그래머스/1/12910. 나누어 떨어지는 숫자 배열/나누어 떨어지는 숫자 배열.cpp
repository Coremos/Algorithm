#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for (int number : arr)
    {
        if (number % divisor == 0)
        {
            answer.push_back(number);
        }
    }
    if (answer.empty()) answer.push_back(-1);
    return answer;
}