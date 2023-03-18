#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int a, b, x = 1;
signed main(){
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	a = read();
	b = read();
	if(a == 1){
		puts("1");
		return 0;
	}
	while(x <= 1000000000 && b){
		x *= a;
		b--;
	}
	if(x > 1000000000) puts("-1");
	else cout << x << endl;
	return 0;
}