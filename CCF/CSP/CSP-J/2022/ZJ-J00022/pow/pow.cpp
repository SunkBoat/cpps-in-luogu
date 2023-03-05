#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, ans = 1, maxans = 1e9;
int main() {
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	while (b) {
		if (a > maxans) break;
		if (b & 1) ans *= a;
		if (ans > maxans) break;
		a = a * a; b >>= 1;
	}
	if (b) cout << -1; else cout << ans;
	return 0;
}

