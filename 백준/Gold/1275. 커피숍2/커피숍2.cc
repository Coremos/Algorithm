#include <iostream>

using namespace std;

int arr[100000];
long long tree[400000];

long long create_tree(int n, int start, int end)
{
	if (start == end) return tree[n] = arr[start];

	int mid = (start + end) >> 1;
	long long left = create_tree(n << 1, start, mid);
	long long right = create_tree((n << 1) + 1, mid + 1, end);
	return tree[n] = left + right;
}

long long sum_tree(int n, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[n];

	int mid = (start + end) >> 1;
	long long leftsum = sum_tree(n << 1, start, mid, left, right);
	long long rightsum = sum_tree((n << 1) + 1, mid + 1, end, left, right);

	return leftsum + rightsum;
}

void update_tree(int n, int start, int end, int index, long long difference)
{
	if (start > index || index > end) return;

	tree[n] += difference;

	if (start != end)
	{
		int mid = (start + end) >> 1;
		update_tree(n << 1, start, mid, index, difference);
		update_tree((n << 1) + 1, mid + 1, end, index, difference);
	}
}

int main()
{
	int N;
	int Q;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	create_tree(1, 0, N - 1);

	for (int i = 0; i < Q; i++)
	{
		int x;
		int y;
		int a;
		long long b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << sum_tree(1, 0, N - 1, x - 1, y - 1) << '\n';
		update_tree(1, 0, N - 1, a - 1, b - arr[a - 1]);
		arr[a - 1] = b;
	}
}