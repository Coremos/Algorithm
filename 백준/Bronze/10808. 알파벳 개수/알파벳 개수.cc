#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int arr[26] = {};
	cin >> S;
	for (int index : S)
	{
		arr[index - 'a'] += 1;
	}
	for (int number : arr)
	{
		cout << number << " ";
	}
	return 0;
}