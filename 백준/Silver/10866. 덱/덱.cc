#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string str;
	deque<int> deque;
	cin >> N;

	while (N--)
	{
		cin >> str;
		if (str == "push_front")
		{
			int X;
			cin >> X;
			deque.push_front(X);
		}
		else if (str == "push_back")
		{
			int X;
			cin >> X;
			deque.push_back(X);
		}
		else if (str == "pop_front")
		{
			if (deque.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque.front() << "\n";
				deque.pop_front();
			}
		}
		else if (str == "pop_back")
		{
			if (deque.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque.back() << "\n";
				deque.pop_back();
			}
		}
		else if (str == "front")
		{
			if (deque.empty())
				cout << -1 << "\n";
			else
				cout << deque.front() << "\n";
		}
		else if (str == "back")
		{
			if (deque.empty())
				cout << -1 << "\n";
			else
				cout << deque.back() << "\n";
		}
		else if (str == "size")
		{
			cout << deque.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << deque.empty() << "\n";
		}
	}
}