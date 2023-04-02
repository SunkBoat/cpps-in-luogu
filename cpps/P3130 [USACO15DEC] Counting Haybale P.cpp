#include "bits/stdc++.h"
#define ll long long
using namespace std;

int n, q;

ll a[1919810], b[1919810], d[1919810], c[1919810];

void build(int l, int r, int p) {
	if (l == r) {
		d[p] = a[l];
		c[p] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build (l, m, p * 2);
	build (m + 1, r, p * 2 + 1);
	d[p] = d[p * 2 + 1] + d[p * 2];
	c[p] = min(c[p * 2], c[p * 2 + 1]);
}

void pushdown(int l, int r, int p) {
	int m = (l + r) / 2;
//	cout<<"lazy:"<<b[p]<<' '<<b[p*2]<<' '<<b[p*2+1]<<"min:"<<c[p]<<' '<<c[p*2]<<' '<<c[p*2+1]
//	<<"sum:"<<d[p]<<' '<<d[p*2]<<' '<<d[p*2+1]<<endl;
	c[p * 2] += b[p];
	d[p * 2] += 1ll * (m - l + 1) * b[p];
	c[p * 2 + 1] += b[p];
	d[p * 2 + 1] += 1ll * (r - m) * b[p];
	b[p * 2] += b[p];
	b[p * 2 + 1] += b[p];
	b[p] = 0ll;
//	cout<<"lazy:"<<b[p]<<' '<<b[p*2]<<' '<<b[p*2+1]<<"min:"<<c[p]<<' '<<c[p*2]<<' '<<c[p*2+1]
//	<<"sum:"<<d[p]<<' '<<d[p*2]<<' '<<d[p*2+1]<<endl;
}

void add(int l, int r, int s, int t, int p, ll v) {
	if (l <= s && t <= r) {
//		int y=d[p];
		c[p] += v;
		d[p] += 1ll * (t - s + 1) * v;
		b[p] += v;
		//cout<<l<<' '<<r<<' '<<s<<' '<<t<<' '<<p<<' '<<d[p]<<' '<<y<<endl;
		return;
	}
//	int y=d[p];
	pushdown(s, t, p);
	int m = (s + t) / 2;
	if (l <= m) add(l, r, s, m, p * 2, v);
	if (m < r) add(l, r, m + 1, t, p * 2 + 1, v);
	
	d[p] = d[p * 2 + 1] + d[p * 2];
	c[p] = min(c[p * 2], c[p * 2 + 1]);
	//cout<<l<<' '<<r<<' '<<s<<' '<<t<<' '<<p<<' '<<d[p]<<' '<<y<<endl;
}

ll getsum(int l, int r, int s, int t, int p) {
	//cout<<l<<' '<<r<<' '<<s<<' '<<t<<' '<<p<<' '<<d[p]<<endl;
	if (l <= s && t <= r) return d[p];
	pushdown(s, t, p);
	int m = (s + t) / 2;
	ll f = 0;
	if (l <= m) f += getsum(l, r, s, m, p * 2);
	if (m < r) f += getsum(l, r, m + 1, t, p * 2 + 1);
	return f;
}

ll query(int l, int r, int s, int t, int p) {
	if (l <= s && t <= r) return c[p];
	pushdown(s, t, p);
	int m = (s + t) / 2;
	ll f = 1ll * 1e18;
	if (l <= m) f = min(f, query(l, r, s, m, p * 2));
	if (m < r) f = min(f, query(l, r, m + 1, t, p * 2 + 1));
	return f;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(1, n, 1);
//	for(int i=1;i<=4*n;++i)cout<<d[i]<<' ';cout<<endl;
	for (int i = 1; i <= q; ++i) {
		char ch;
		int l, r;
		ll v;
		cin >> ch >> l >> r;
		if (ch == 'P') {
			cin >> v;
			add(l, r, 1, n, 1, v);
//			for(int i=1;i<=4*n;++i)cout<<d[i]<<' ';cout<<endl;
		}
		if (ch == 'M') cout << query(l, r, 1, n, 1) << endl;
		if (ch == 'S') cout << getsum(l, r, 1, n, 1) << endl;
	} 
}

