#include "bits/stdc++.h"
using namespace std;
#define int long long//加入邪教

int s[1919810], top;

int a[1919810];
int f[1919810];
int ans;

int sea(int t) {
	int l = 0, r = top, mid, delt = 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (s[mid] > t) {
			l = mid + 1; delt = mid;
		} else {
			r = mid - 1;
		}
	}
	return top - delt + 1;
}

signed main() {
	int n;
	scanf ("%lld", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		f[i] = sea(a[i]);
		while (top && a[i] > s[top]) --top;
		s[++top] = a[i];
	}
//	cout << endl;
	for (int i = 1; i <= n; ++i) ans += f[i];
	cout << ans;
}
