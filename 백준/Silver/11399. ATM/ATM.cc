#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int answer = 0;
	int N;
	vector<int> P;

	cin >> N;
	P.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}

	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++)
	{
		answer += P[i] * (N - i);
	}

	cout << answer;

	return 0;
}