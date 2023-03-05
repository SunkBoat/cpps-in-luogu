#include "bits/stdc++.h"
using namespace std;


int f[1500][1500][2];

int dp[1500][1500];
int a[1500][1500];
int b[1500][1500];

int n, m;

int main() {

	for(; ;) {
// 		freopen ("mine.in", "r", stdin);
// 		freopen ("mine.out", "w", stdout); 
		scanf ("%d%d", &n, &m);
		if (n == 0 && m == n) return 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf ("%d", &a[i][j]);
				f[i][j][0] = f[i][j][1] = 0;
				dp[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) scanf ("%d", &b[i][j]);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				f[i][j][0] = f[i][j - 1][0] + a[i][j];
				f[i][j][1] = f[i - 1][j][1] + b[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = max(dp[i - 1][j] + f[i][j][0], dp[i][j - 1] + f[i][j][1]);
			}
		}

		printf ("%d\n", dp[n][m]);
	}
}
