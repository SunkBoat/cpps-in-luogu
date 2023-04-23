//宇宙射线（悲）

#include "bits/stdc++.h"
using namespace std;

int dp[450][80000];

struct Node {
	int h, a, c;
}f[322620];

bool cmp (Node x, Node y) {
	return x.a < y.a;
}

int n;

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) scanf ("%d%d%d", &f[i].h, &f[i].a, &f[i].c);
	sort (f + 1, f + n + 1, cmp);
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= f[i].a; ++j) {
			for (int k = 0; k <= f[i].c; ++k) {
				if ((j - (k * f[i].h)) >= 0) dp[i][j] |= dp[i - 1][j - (k * f[i].h)];
			}
		}
	}
	for (int i = f[n].a; i >= 0; --i) {
		if (dp[n][i] == 1) {
			cout << i;
			return 0;
		}
	}
}
