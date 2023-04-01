#include "bits/stdc++.h"
using namespace std;

int r, c, n, m;

int f[1145][1419];
int x[1919810], y[1919810];
int ans[1919810];
char l[1919810];

int chk(int p) {
//	cout<<p<<":\n";
//	for(int i=1;i<=r;++i){
//		for(int j=1;j<=c;++j)cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	for (int i = 1; i <= n; ++i) {
		if (i == p) continue;
		int N = 0, E = 0;
		for (int tx = x[i] - 1, ty = y[i]; tx >= 1; --tx) {
			if (f[tx][ty] == 1) ++N;
//			cout<<tx<<' '<<ty<<' '<<f[tx][ty]<<endl;
		}
//		cout<<endl;
		for (int tx = x[i], ty = y[i] + 1; ty <= 150; ++ty) {
			if (f[tx][ty] == 1) ++E;
//			if(ty<=7)cout<<tx<<' '<<ty<<' '<<f[tx][ty]<<endl;
		}
//		cout<<i<<':'<<' '<<x[i]<<' '<<y[i]<<' '<<N<<' '<<E<<endl;
		int mn = min(N, E);
		if (mn > 0) return 0;
	}
	return 1;
}

int main() {
	scanf ("%d%d", &r, &c);
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		//int x, y;
		scanf ("%d%d", &x[i], &y[i]);
		gets(l);
		f[x[i]][y[i]] = 1;
	}
	if (chk(0)) {
		return puts("0"), 0;	
	}
	for (int i = 1; i <= n; ++i) {
		f[x[i]][y[i]] = 0;
		if (chk(i)) ans[++m] = i;
		f[x[i]][y[i]] = 1;
	}
	if (m == 0) return puts("-1"), 0;
	for (int i = 1; i <= m; ++i) printf ("%d\n", ans[i]);
}
