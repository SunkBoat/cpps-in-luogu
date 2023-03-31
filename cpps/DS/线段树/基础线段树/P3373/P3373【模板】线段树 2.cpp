#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int M = 200000;
ll a[M * 4];
ll b[M * 4];
ll c[M * 4];
ll d[M * 4];

ll mod;
int n, t;

void build(int p, int l, int r) {
    //cout<<p<<' '<<l<<' '<<r<<endl;
    if (l == r) {
        d[p] = a[l] % mod;
        c[p] = 1ll;
        return;
    }
    int m = (l + r) / 2;
    build(p * 2, l, m);
    build(p * 2 + 1, m + 1, r);
    c[p] = 1ll;
    d[p] = (d[p * 2] + d[p * 2 + 1]) % mod;
}

void pushdown(int p, int l, int r) {
    int m = (l + r) / 2;
	d[p * 2] = (d[p * 2] * c[p] + b[p] * (m - l + 1)) % mod;
	d[p * 2 + 1] = (d[p * 2 + 1] * c[p] + b[p] * (r - m)) % mod;
	
	c[p * 2] = (c[p * 2] * c[p]) % mod;
	c[p * 2 + 1] = (c[p * 2 + 1] * c[p]) % mod;
	
	b[p * 2] = (b[p * 2] * c[p] + b[p]) % mod;
	b[p * 2 + 1] = (b[p * 2 + 1] * c[p] + b[p]) % mod;
	
	b[p] = 0; c[p] = 1;
}

void add(int p, int l, int r, int s, int t, ll v) {
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * v;
        b[p] += v;
        d[p] %= mod;
        b[p] %= mod;
        return;
    }
    if (s != t) pushdown(p, s, t);
    int m = (s + t) / 2;
    if (l <= m) add(p * 2, l, r, s, m, v);
    if (m < r) add(p * 2 + 1, l, r, m + 1, t, v);
    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}

void mul(int p, int l, int r, int s, int t, ll v) {
    //cout<<p<<' '<<l<<' '<<r<<' '<<s<<' '<<t<<' '<<v<<endl;
    if (l <= s && t <= r) {
        //b[p] *= v;
        d[p] *= v;
        c[p] *= v;
        b[p] *= v;
        b[p] %= mod;
        d[p] %= mod;
        c[p] %= mod;
        return;
    }
    if (s != t) pushdown(p, s, t);
    int m = (s + t) / 2;
    if (l <= m) mul(p * 2, l, r, s, m, v);
    if (m < r) mul(p * 2 + 1, l, r, m + 1, t, v);
    d[p] = d[p * 2] + d[p * 2 + 1];
    d[p] %= mod;
}

ll query(int p, int l, int r, int s, int t) {
    if (l <= s && t <= r) {
        return d[p] % mod;
    }
    if (s != t) pushdown(p, s, t);
    int m = (s + t) / 2;
    ll f = 0;
    if (l <= m) {
        f += query(p * 2, l, r, s, m);
        f %= mod;
    }
    if (m < r) {
        f += query(p * 2 + 1, l, r, m + 1, t);
        f %= mod;
    }
    return f;
}

int main() {
    scanf ("%d %d %lld", &n, &t, &mod);
    for (int i = 1; i <= n; ++i) scanf ("%lld", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= t; ++i) {
        int op, x, y;
        ll f;
        scanf ("%d", &op);
        if (op == 1) {
            scanf ("%d%d%lld", &x, &y, &f);
            mul(1, x, y, 1, n, f);
        } else if (op == 2) {
            scanf ("%d%d%lld", &x, &y, &f);
            add(1, x, y, 1, n, f);
        } else {
            scanf ("%d%d", &x, &y);
            printf ("%lld\n", query(1, x, y, 1, n));
        }
    }
}
