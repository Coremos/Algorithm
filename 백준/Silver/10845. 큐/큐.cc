#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string str;
	queue<int> queue;
	cin >> N;

	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			int X;
			cin >> X;
			queue.push(X);
		}
		else if (str == "pop")
		{
			if (queue.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << queue.front() << "\n";
				queue.pop();
			}
		}
		else if (str == "front")
		{
			if (queue.empty())
				cout << -1 << "\n";
			else
				cout << queue.front() << "\n";
		}
		else if (str == "back")
		{
			if (queue.empty())
				cout << -1 << "\n";
			else
				cout << queue.back() << "\n";
		}
		else if (str == "size")
		{
			cout << queue.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << queue.empty() << "\n";
		}
	}
}