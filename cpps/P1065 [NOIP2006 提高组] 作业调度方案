#include "bits/stdc++.h"
using namespace std;

int m, n, ans;
int d[7255][7255];//机器 
int t[7255][7255];//加工时间 
int lst[1919810];//最后加工时间
int vis[1919810];
int a[1919810];
int f[7255][7255];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> d[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> t[i][j];
	}
	for (int i = 1; i <= n; ++i) lst[i] = 1;
	for (int i = 1; i <= n * m; ++i) {
		vis[a[i]] += 1;
		for (int j = lst[a[i]]; ; ++j) {
			bool flg = true;
			for (int k = j; k < j + t[a[i]][vis[a[i]]]; ++k) {
				if (f[k][d[a[i]][vis[a[i]]]] != 0) {
					flg = false;
					break;
				}
			}
			if (flg) {
//				cout<<lst[a[i]]<<' '<<a[i]<<' '<<
//				vis[a[i]]<<' '<<j<<' '<<t[a[i]][vis[a[i]]]<<
//				' '<<j+t[a[i]][vis[a[i]]]<<' '<<d[a[i]][vis[a[i]]]<<endl;
				for (int k = j; k < j + t[a[i]][vis[a[i]]]; ++k) {
					f[k][d[a[i]][vis[a[i]]]] = a[i];
					ans = max(ans, k);
					lst[a[i]] = max(lst[a[i]], k + 1);
				}
				break;
			}
		}
	} 
//	for (int i=0;i<=20;++i){
//		for(int j=1;j<=2;++j)cout<<f[i][j]<<' ';
//		cout<<endl;
//	}
	cout << ans << endl;
}
