#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, k, sk, d, e, p, q;
int main() {
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> d >> e; m = n - d * e + 2;
		k = m * m - 4 * n;
		if (k >= 0) {
			sk = sqrt(k);
			if (sk * sk == k) {
				if ((m + sk) % 2 == 0) {
					p = (m - sk) / 2; q = (m + sk) / 2;
					cout << p << " " << q << '\n';
				}
				else cout << "NO" << '\n';
			}
			else cout << "NO" << '\n';
		}
		else cout << "NO" << '\n';
	}
	return 0;
}

