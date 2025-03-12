#include <stdio.h>
#include <string.h>
char stack[101];
int main() {
	int j, c = 0;
	char str[101], last;
	while(1) {
		gets(str);
		if (str[0] == '.') break;
		j = c = 0;
		while (str[j] != '.') {
			//printf("%d일때 %c이고 스택은 %c이고 %d\n", j, str[j], stack[c - 1], c);
			if (str[j] == '\(') {
				stack[c++] = '\(';
			}
			else if (str[j] == '\)') {
				if (c == 0) {
					c = -1;
					break;
				}
				else if (stack[c - 1] == '\[') {
					c = -1;
					break;
				}
				c -= 1;
			}
			if (str[j] == '\[') {
				stack[c++] = '\[';
			}
			else if (str[j] == '\]') {
				if (c == 0) {
					c = -1;
					break;
				}
				else if (stack[c - 1] == '\(') {
					c = -1;
					break;
				}
				c -= 1;
			}
			j++;
		}
		if (c == 0) printf("yes\n");
		else printf("no\n");
	}
}