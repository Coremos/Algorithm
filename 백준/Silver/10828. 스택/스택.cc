#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	string str;
	stack<int> stack;
	cin >> N;

	while (N--)
	{
		cin >> str;
		if (str == "push")
		{
			int X;
			cin >> X;
			stack.push(X);
		}
		else if (str == "pop")
		{
			if (stack.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << stack.top() << "\n";
				stack.pop();
			}

		}
		else if (str == "top")
		{
			if (stack.size() == 0)
				cout << -1 << "\n";
			else
				cout << stack.top() << "\n";
		}
		else if (str == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (str == "empty")
		{
			cout << stack.empty() << "\n";
		}
	}
}