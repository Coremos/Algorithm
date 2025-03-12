#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	int M;
	char command;
	list<char> answer;

	cin >> str >> M;
	for (auto c : str) answer.push_back(c);
	auto index = answer.end();
	while (M--)
	{
		cin >> command;
		if (command == 'L')
		{
			if (index != answer.begin()) 
				index--;
		}
		else if (command == 'D')
		{
			if (index != answer.end()) 
				index++;
		}
		else if (command == 'B')
		{
			if (index != answer.begin())
			{
				index = answer.erase(--index);
			}
		}
		else if (command == 'P')
		{
			cin >> command;
			answer.insert(index, command);
		}
	}

	for (auto c : answer) cout << c;
}