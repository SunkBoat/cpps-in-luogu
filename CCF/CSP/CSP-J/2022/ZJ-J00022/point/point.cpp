#include<bits/stdc++.h>
using namespace std;
const int N = 505, K = 105;
int n, k, x[N], y[N], d[N], s[N][K], ans = 0;
bool cmp(int a, int b) {
	return x[a] + y[a] < x[b] + y[b];
}
int main() {
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i]; d[i] = i;
		for (int j = 0; j <= k; j++) s[i][j] = 1;
	} 
	sort(d + 1, d + n + 1, cmp);
	for (int ii = 1; ii <= n; ii++) {
		int i = d[ii];
		for (int j = 0; j <= k; j++) {
			ans = max(ans, s[i][j] + k); 
			for (int ee = ii + 1; ee <= n; ee++) {
				int e = d[ee];
				if (x[i] + y[i] == x[e] + y[e]) continue;
				if (x[i] <= x[e] && y[i] <= y[e]) {
					int t = x[e] - x[i] + y[e] - y[i] - 1;
					if (j + t <= k) {
						s[e][j + t] = max(s[e][j + t], s[i][j] + 1);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}

