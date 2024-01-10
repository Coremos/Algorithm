#include <vector>
#include <map>

using namespace std;

map<int, int> phoneketmons;

int solution(vector<int> nums)
{
    int count = nums.size() >> 1;
    int diversity = 0;
    
    for (int index = 0; index < nums.size(); index++)
    {
        phoneketmons[nums[index]]++;
        if (phoneketmons[nums[index]] <= 1) diversity++;
    }
    return (diversity > count) ? count : diversity;
}