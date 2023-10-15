#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> zams[300001];
int bags[300001];
priority_queue<int> priority;

bool sort_zam(pair<int, int> zam1, pair<int, int> zam2)
{
	return zam1.second < zam2.second;
}

int main()
{
	long long answer = 0;
	int N;
	int K;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> zams[i].first >> zams[i].second;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> bags[i];
	}

	sort(zams, zams + N);
	sort(bags, bags + K);

	int zamIndex = 0;
	for (int i = 0; i < K; i++)
	{
		for (; bags[i] >= zams[zamIndex].first && zamIndex < N; zamIndex++)
		{
			priority.push(zams[zamIndex].second);
		}

		if (!priority.empty())
		{
			answer += priority.top();
			priority.pop();
		}
	}

	cout << answer;

	return 0;
}