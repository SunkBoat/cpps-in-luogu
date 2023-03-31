#include "bits/stdc++.h"
typedef long long ll;
using namespace std;

const int M = 1000000;

ll d[M << 4];
ll b[M << 4];
ll a[M << 4];

void Binah(int p) {
	printf ("%d:%d %d\n", p, d[p], b[p]);
	
	if (d[p * 2] != 0) Binah(p * 2);
	if (d[p * 2 + 1] != 0) Binah(p * 2 + 1);
}

void pushdown(int p, int s, int t, int m) {
	d[p * 2] += b[p] * (m - s + 1); d[p * 2 + 1] += b[p] * (t - m);
	b[p * 2] += b[p]; b[p * 2 + 1] += b[p];
	b[p] = 0;
}

void build(int l, int r, int p) {
    //l 表示区间左端点，r 表示区间右端点，p 表示区间当前节点 
    if (l == r) {
        d[p] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, p * 2);
    build(m + 1, r, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

ll getsum(int l, int r, int s, int t, int p) {
	if (l <= s && t <= r) return d[p];//在区间内
	int m = (s + t) / 2;
	if (s != t && b[p] != 0) pushdown(p, s, t, m);
	ll ans = 0ll;
	if (m >= l) ans += getsum(l, r, s, m, p * 2);
	if (m < r) ans += getsum(l, r, m + 1, t, p * 2 + 1);
	return ans;
}

void add(int l, int r, ll c, int s, int t, int p) {
	if (l <= s && t <= r) {
		d[p] += c * (t - s + 1);//该节点更新 
		b[p] += c;//懒标记更新 
		return;
	}
	int m = (s + t) / 2;
	if (s != t && b[p] != 0) pushdown(p, s, t, m);
	if (m >= l) add(l, r, c, s, m, p * 2);
	if (m < r) add(l, r, c, m + 1, t, p * 2 + 1);
	d[p] = d[p * 2] + d[p * 2 + 1];
}

int main() {
	int n, m;
	ll mod;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf ("%lld", &a[i]);
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		int op, x, y;
		ll k;
		scanf ("%d", &op);
		if (op == 1) {
			scanf ("%d%d%lld", &x, &y, &k);
			add(x, y, k, 1, n, 1);
		} else {
			scanf ("%d%d", &x, &y);
			printf ("%lld\n", getsum(x, y, 1, n, 1));
		}
	}
}
