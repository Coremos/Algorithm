#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int width = 0;
    int height = 0;
    
    for (auto size : sizes)
    {
        if (size[0] > size[1])
        {
            if (width < size[0])
            {
                width = size[0];
            }
            if (height < size[1])
            {
                height = size[1];
            }
        }
        else
        {
            if (width < size[1])
            {
                width = size[1];
            }
            if (height < size[0])
            {
                height = size[0];
            }
        }
    }
    int answer = width * height;
    return answer;
}