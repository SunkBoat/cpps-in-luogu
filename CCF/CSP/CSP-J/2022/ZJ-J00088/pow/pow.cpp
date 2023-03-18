#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll stra, strb, len = 0;
ll a[11], c[2200], ans[2200];
void quickcin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int main(){
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	quickcin();
	cin >> stra >> strb;
	while(stra){
		len++;
		a[len] = stra % 10;
		stra /= 10;
	}
	ll s = 1;
	c[1] = 1;
	for(int i = 1; i <= strb; ++i){
		for(int j = 1; j <= len; ++j)
			for(int k = 1; k <= s; ++k)
				ans[j + k - 1] += a[j] * c[k];
		for(int j = 1; j <= len + s; ++j){
			if(ans[j] >= 10){
				ans[j + 1] += ans[j] / 10;
				ans[j] %= 10;
			}
		}
		for(int i = 1; i <= len + s; ++i)
			if(ans[i])
				s = i;
		for(int j = 1; j <= len + s + 1; ++j){
			if(ans[j]) s = j;
			if(ans[j] && j >= 11){
				cout << -1;
				return 0;
			}
		}
		for(int j = 1; j <= s; ++j) c[j] = ans[j], ans[j] = 0;
	}
	ll check = 0;
	if(s == 10){
		for(int i = s; i >= 1; --i)
			check = check * 10 + c[i];
		if(check > 2147483647){
			cout << -1;
			return 0;
		}
	}
	for(int i = s; i >= 1; --i)
		cout << c[i];
	cout << "\n";
	return 0;
}