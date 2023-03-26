#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

double r[1919810], x[1919810], y[1919810];
int d[1919810];
int vis[1919810], v[1919810];
double sx, sy, tx, ty;
double ans;
int n;

double dis(double X1, double Y1, double X2, double Y2) {
	return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
} 

void work(int p) {
	double mn = min(x[p] - sx, min(y[p] - sy, min(tx - x[p], ty - y[p])));
	for (int i = 1; i <= n; ++i) {
		if (i == p || vis[i]) continue;
//		if (p == 1) cout << x[p] << ' ' << y[p] << ' ' << x[i] << ' ' << y[i] << endl;
//		if (p == 1) cout << (x[p] - y[p]) * (X1 - Y1) + (X2 - Y2) * (X2 - Y2) << endl;
		mn = min(mn, max(0.0, dis(x[p], y[p], x[i], y[i]) - r[i]));
		//if (p == 1) cout << mn << ' ' << dis(x[p], y[p], x[i], y[i]) << ' ' << r[i] << endl;
	}
	r[p] = mn;
	vis[p] = 0;
}

void dfs(int dep) {
	if (dep > n) {
		double cnt = 0.0;
		for (int i = 1; i <= n; ++i) vis[i] = 1;
		for (int i = 1; i <= n; ++i) work(d[i]);
		for (int i = 1; i <= n; ++i) cnt += r[i] * r[i] * 3.14159265358979323;
		for (int i = 1; i <= n; ++i) {
			//cout << d[i] << ' ' << r[i] << endl;
		}
		ans = max(ans, cnt);
	}
	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			v[i] = 1;
			d[dep] = i;
			dfs(dep + 1);
			d[dep] = 0;
			v[i] = 0;
		}
	}
}

int reint(double x) {
	return int(x + 0.5);
}

int main() {
	scanf ("%d", &n);
	scanf ("%lf%lf%lf%lf", &sx, &sy, &tx, &ty);
	if (sx > tx) swap(sx, tx);
	if (sy > ty) swap(sy, ty);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lf%lf", &x[i], &y[i]);
	}
	dfs(1);
	//cout<<ans<<endl;
	printf ("%d\n", reint((tx - sx) * (ty - sy) - ans));
}
