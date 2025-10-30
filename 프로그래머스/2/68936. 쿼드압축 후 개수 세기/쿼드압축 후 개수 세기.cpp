#include <string>
#include <vector>

using namespace std;

vector<int> quad(vector<vector<int>> &arr, int x, int y, int power)
{
    vector<int> answer(3);
    if (power == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                answer[arr[y + i][x + j]]++;
            }
        }
        if (answer[0] == 4)
        {
            answer[0] = 1;
            answer[2] = 1;
        }
        if (answer[1] == 4)
        {
            answer[1] = 1;
            answer[2] = 2;
        }
    }
    else
    {
        vector<int> result[4];
        result[0] = quad(arr, x, y, power - 1);
        result[1] = quad(arr, x + (1 << power), y, power - 1);
        result[2] = quad(arr, x, y + (1 << power), power - 1);
        result[3] = quad(arr, x + (1 << power), y + (1 << power), power - 1);
        
        answer[2] = result[0][2];
        for (int i = 0; i < 4; i++)
        {
            answer[0] += result[i][0];
            answer[1] += result[i][1];
            answer[2] &= result[i][2];
        }
        if (answer[0] == 4 && answer[2] > 0)
        {
            answer[0] = 1;
        }
        if (answer[1] == 4 && answer[2] > 0) answer[1] = 1;
    }
    return answer;
}
    
vector<int> solution(vector<vector<int>> arr)
{
    int size = arr.size();
    int power = 0;
    while (size > 2)
    {
        power++;
        size >>= 1;
    }
    vector<int> answer = quad(arr, 0, 0, power);
    answer.pop_back();
    return answer;
}