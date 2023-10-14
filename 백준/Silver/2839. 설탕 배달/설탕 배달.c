#include <stdio.h>
int arr[5001];
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int N;
	scanf("%d", &N);
	arr[3] = arr[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (arr[i - 3]) arr[i] = arr[i - 3] + 1;
		if (arr[i - 5]) arr[i] = arr[i] ? min(arr[i], arr[i - 5] + 1) : arr[i - 5] + 1;
	}
	printf("%d", arr[N] ? arr[N]: -1);
}