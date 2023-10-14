#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHABET_LENGTH = 26;
int counts[ALPHABET_LENGTH];

int main()
{
	int N;
	int answer = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string value;
		cin >> value;
		int length = value.length();
		int multiplier = 1;
		for (int j = 1; j <= length; j++)
		{
			counts[value[length - j] - 'A'] += multiplier;
			multiplier *= 10;
		}
	}

	sort(counts, counts + 26);
	for (int i = 1; i <= 10; i++)
	{
		answer += counts[ALPHABET_LENGTH - i] * (10 - i);
	}
	cout << answer;
}