#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int height = triangle.size();
    for (int y = 1; y < height; y++)
    {
        for (int x = 0; x < triangle[y].size(); x++)
        {
            int left = (x > 0) ? triangle[y - 1][x - 1] : 0; 
            int right = (x < triangle[y].size() - 1) ? triangle[y - 1][x] : 0; 
            triangle[y][x] += max(left, right);
        }
    }
    
    int answer = 0;
    for (int x = 0; x < triangle[height - 1].size(); x++)
    {
        int current = triangle[height - 1][x];
        if (answer < current)
        {
            answer = current;
        }
    }
    
    return answer;
}