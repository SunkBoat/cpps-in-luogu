#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

const int N = int(3e5);

using namespace std;

int a[N << 4];
int b[N << 4];
int d[N << 4];
int ans[N << 4];

void build(int l, int r, int p) {
	if (l == r) {
		d[p] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build (l, m, p * 2);
	build (m + 1, r, p * 2 + 1);
	d[p] = min(d[p * 2], d[p * 2 + 1]);
} 

int query(int l, int r, int s, int t, int p) {
	if (l <= s && t <= r) {
		return d[p];
	}
	int m = (s + t) / 2;
	int f = 0x7fffffff;
//	cout<<l<<' '<<r<<' '<<s<<' '<<m<<' '<<t<<' '<<p<<endl;
//	system("pause");
	if (l <= m) f = min(f, query(l, r, s, m, p * 2));
	if (m < r) f = min(f, query(l, r, m + 1, t, p * 2 + 1));
	return f;
}

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf ("%d%d", &l, &r);
		ans[i] = query(l, r, 1, n, 1);
	}
	for (int i = 1; i <= m; ++i) printf ("%d ", ans[i]);
}
