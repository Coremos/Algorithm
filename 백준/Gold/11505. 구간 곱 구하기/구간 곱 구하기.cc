#include <iostream>

using namespace std;

const long long DIVIDER = 1000000007;

int arr[1000000];
long long tree[4000000];

long long create_tree(int n, int start, int end)
{
	if (start == end) return tree[n] = arr[start];

	int mid = (start + end) >> 1;
	return tree[n] = create_tree(n << 1, start, mid) * create_tree((n << 1) + 1, mid + 1, end) % DIVIDER;
}

long long sum_tree(int n, int start, int end, int left, int right)
{
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[n];

	int mid = (start + end) >> 1;
	return sum_tree(n << 1, start, mid, left, right) * sum_tree((n << 1) + 1, mid + 1, end, left, right) % DIVIDER;
}

long long update_tree(int n, int start, int end, int index, long long value)
{
	if (start > index || index > end) return tree[n];
	if (start == end) return tree[n] = value;

	int mid = (start + end) >> 1;
	return tree[n] = update_tree(n << 1, start, mid, index, value) * update_tree((n << 1) + 1, mid + 1, end, index, value) % DIVIDER;
}

int main()
{
	int N;
	int M;
	int K;

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	create_tree(1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int a;
		int b;
		int c;

		cin >> a >> b >> c;
		if (a == 1)
		{
			update_tree(1, 0, N - 1, b - 1, c);
		}
		else
		{
			if (b > c) swap(b, c);
			cout << sum_tree(1, 0, N - 1, b - 1, c - 1) << '\n';
		}
	}
}