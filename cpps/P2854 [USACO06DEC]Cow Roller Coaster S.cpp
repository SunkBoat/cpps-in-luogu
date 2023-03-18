#include "bits/stdc++.h"
#define ll long long
using namespace std;
struct g {
	ll f;
	int x, c;
};

vector<g> v[1919];

ll dp[1145][1419];

int main() {
	int n, l, b;
	scanf ("%d%d%d", &l, &n, &b);
	++l;
	for (int i = 1; i <= n; ++i) {
		int x, w, c;
		int f;
		scanf ("%d%d%lld%d", &x, &w, &f, &c);
		g t;
		t.c = c; t.f = f; t.x = x + 1;
		v[x + w + 1].push_back(t);
	}
	for (int i = 0; i <= 1100; ++i) {
		for (int j = 0; j <= 1100; ++j) dp[i][j] = -0x3f3f3f3f;
	}
	for (int i = 0; i <= b; ++i) dp[1][i] = 0;
	for (int i = 1; i <= l; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k < v[i].size(); ++k) {
				if (j > v[i][k].c) {
					dp[i][j] = max(dp[i][j], 
					dp[v[i][k].x][j - v[i][k].c] + v[i][k].f);
				}
			}
		}
	}
//	for(int i=1;i<=l;++i){
//		for(int j=0;j<=b;++j)cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	if (dp[l][b] >= 0) printf ("%lld", dp[l][b]);
	else puts("-1");
}
