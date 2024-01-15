#include <string>
#include <vector>

using namespace std;

vector<int> solution(int start_num, int end_num)
{
    vector<int> answer;
    for (int number = start_num; number <= end_num; number++)
    {
        answer.push_back(number);
    }
    return answer;
}