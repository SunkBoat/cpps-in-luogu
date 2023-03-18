#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500 + 5, K = 100 + 5;
inline int read(){
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
struct node{
	int x, y;
}a[N];
int n, k, f[N][K], ans;
bool cmp(node p, node q){
	return (p.x == q.x) ? (p.y < q.y) : (p.x < q.x);
}
int jl(int p, int q){
	return abs(a[p].x - a[q].x) + abs(a[p].y - a[q].y);
}
signed main(){
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	n = read();
	k = read();
	for(int i = 1; i <= n; i++){
		a[i].x = read();
		a[i].y = read();
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			f[i][j] = j + 1;
			for(int l = 1; l < i; l++){
				int jl1 = jl(i, l) - 1;
				if(jl1 <= j && a[l].x <= a[i].x && a[l].y <= a[i].y)
					f[i][j] = max(f[i][j], f[l][j - jl1] + jl1 + 1);
			}
		}
	}
	for(int i = 1; i <= n; i++) ans = max(ans, f[i][k]);
	cout << ans << endl;
	return 0;
}