#include <iostream>
using namespace std;
int a, b, flag = 0, res = 0;

int main() {
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	scanf("%d%d", &a, &b);
	if (a == 1 || b < 1) {
		printf("1\n");
		return 0;
	}
	if (b == 1 && a > 1000000000) {
		printf("-1\n");
		return 0;
	}
	res = a;
	for (int i = 1; i < b; i++) {
		res *= a;
		if (res > 1000000000) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", res);
	return 0;
}

