#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> phones;

bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    for (auto phone : phone_book)
    {
        if (!phones.empty())
        {
            for (int i = 1; i < phone.size(); i++)
            {
                if (phones.find(phone.substr(0, i)) != phones.end())
                {
                    return false;
                }
            }
        }
        phones.insert(phone);
    }
    return true;
}