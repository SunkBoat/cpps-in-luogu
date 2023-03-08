#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

int n, m;

const int M = 1e6;

int a[M << 3], d[M << 3];

void build(int l, int r, int p) {
	if (l == r) {
		d[p] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(l, m, p * 2);
	build(m + 1, r, p * 2 + 1);
	d[p] = max(d[p * 2], d[p * 2 + 1]);
}

void add(int s, int t, int a, int v, int p) {
	if (s == t) {
		d[p] = max(d[p], v);
		return;
	}
	int m = (s + t) / 2;
	if (a <= m) add(s, m, a, v, p * 2);
	else add(m + 1, t, a, v, p * 2 + 1);
	d[p] = max(d[p * 2], d[p * 2 + 1]);
}

int query(int l, int r, int s, int t, int p) {
	if (l <= s && t <= r) {
		return d[p];
	}
	int m = (s + t) / 2, f = 0;
	if (l <= m) f = max(f, query(l, r, s, m, p * 2));
	if (m < r) f = max(f, query(l, r, m + 1, t, p * 2 + 1));
	return f;
}

int main() {
	IOS
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		char op;
		int l, r, v;
		cin >> op;
		if (op == 'Q') {
			cin >> l >> r;
			cout << query(l, r, 1, n, 1) << '\n';
		} else {
			cin >> l >> v;
			add(1, n, l, v, 1);
		}
	}
}
