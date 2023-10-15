#include <stdio.h>
#include <string.h>

int stack[100000];
int main() {
	int N, c = 0, n;
	char command[6];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", command);
		if (strcmp(command, "push") == 0) {
			scanf("%d", &n);
			stack[c++] = n;
		}
		else if (strcmp(command, "pop") == 0) {
			if (c == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[--c]);
			}
		}
		else if (strcmp(command, "size") == 0) {
			printf("%d\n", c);
		}
		else if (strcmp(command, "empty") == 0) {
			printf("%d\n", c == 0);
		}
		else if (strcmp(command, "top") == 0) {
			if (c == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[c - 1]);
			}
		}
	}
}