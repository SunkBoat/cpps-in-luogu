#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll x[15], y[15];
void quickcin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int main(){
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	quickcin();
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i];
	cout << n - 2 + k << endl;
	return 0;
}