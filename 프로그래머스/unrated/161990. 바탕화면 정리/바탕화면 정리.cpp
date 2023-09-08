#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    int lux = 50;
    int luy = 50;
    int rdx = 0;
    int rdy = 0;
    
    vector<string>::iterator iter;
    for (iter = wallpaper.begin(); iter < wallpaper.end(); iter++)
    {
        bool isFound = false;
        int peek = 0;
        cout << *iter;
        while (iter->find('#', peek) != string::npos)
        {
            int index = iter->find('#', peek);
            isFound = true;
            if (index < luy) luy = index;
            if (index > rdy) rdy = index;
            peek = index + 1;
        }
        if (isFound)
        {
            int index = distance(wallpaper.begin(), iter);
            if (index < lux) lux = index;
            if (index > rdx) rdx = index;
        }
    }
    vector<int> answer = {lux, luy, rdx + 1, rdy + 1};
    
    return answer;
}