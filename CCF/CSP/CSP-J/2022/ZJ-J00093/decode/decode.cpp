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
int k, n, d, e, x, l, r, mid, h, hh, ppp;
signed main(){
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	k = read();
	while(k--){
		ppp = 0;
		n = read();
		d = read();
		e = read();
		x = n - d * e + 2;
		l = 1, r = x;
		while(l <= r){
			mid = (l + r) / 2;
			h = x - mid;
			hh = mid * h;
			if(hh > n) r = mid - 1;
			else if(hh == n){
				if(h < mid) swap(h, mid);
				cout << mid << ' ' << h << endl;
				ppp = 1;
				break;
			}
			else l = mid + 1;
		}
		if(!ppp) puts("NO");
	}
	return 0;
}