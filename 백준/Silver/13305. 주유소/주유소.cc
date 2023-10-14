#include <iostream>

using namespace std;

int distances[100001];
int costs[100001];

int main()
{
	int N;
	int position = 0;
	long long answer = 0;

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		cin >> distances[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> costs[i];
	}

	while (position < N - 1)
	{
		long long distance = 0;
		for (int i = position; i < N; i++)
		{
			if (costs[position] > costs[i] || i == N - 1)
			{
				answer += distance * costs[position];
				position = i;
				break;
			}
			else
			{
				distance += distances[i];
			}
		}
	}

	cout << answer;

	return 0;
}