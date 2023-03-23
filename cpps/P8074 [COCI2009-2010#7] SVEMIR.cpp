#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

struct g {
	int u, v, d;
}t[1919810];

struct gh {
	int id, t;
}x[1919810], y[1919810], z[1919810];

bool cmp(gh x, gh y) {
	return x.t < y.t;
}

bool cpu(g a, g b) {
	return a.d < b.d;
}

int f[1919810];

int m, n;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
int ms(int x, int y) {
	if (find(x) == find(y)) return 1;
	f[find(x)] = find(y);
	return 0;
}

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d%d%d", &x[i].t, &y[i].t, &z[i].t);
		f[i] = x[i].id = y[i].id = z[i].id = i;
	}
	sort(x + 1, x + n + 1, cmp); sort(y + 1, y + n + 1, cmp); sort(z + 1, z + n + 1, cmp);
	for (int i = 2; i <= n; ++i) {
		++m;
		t[m].u = x[i].id; t[m].v = x[i - 1].id; t[m].d = abs(x[i].t - x[i - 1].t);
		++m;
		t[m].u = y[i].id; t[m].v = y[i - 1].id; t[m].d = abs(y[i].t - y[i - 1].t);
		++m;
		t[m].u = z[i].id; t[m].v = z[i - 1].id; t[m].d = abs(z[i].t - z[i - 1].t);
	}
	//for (int i=1;i<=m;++i)cout<<t[i].u<<' '<<t[i].v<<' '<<t[i].d<<endl;
	sort(t + 1, t + m + 1, cpu);
	//for (int i=1;i<=m;++i)cout<<t[i].u<<' '<<t[i].v<<' '<<t[i].d<<endl;
	int cnt = 0, ans = 0;
	for (int i = 1; i <= m; ++i) {
		if (!ms(t[i].u, t[i].v)) ans += t[i].d, ++cnt;
		//cout<<ans<<' '<<cnt<<endl;
		if (cnt == n - 1) {printf ("%d", ans); return 0;}
	}
	if (cnt == n - 1) {printf ("%d", ans); return 0;}
}
