#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N]; int n, k[N], j[N], root;
int son[N][2], cnt = 0;
bool b[N];
int lans = 0, rans = 0;
void build(int l, int r, int fa, int right) {
	if (s[r] == ')' && k[r] == l) l++, r--;
	if (l == r) {
		son[fa][right] = l; return;
	}
	int q = -1;
	for (int i = r; i >= l; i--) {
		if (s[i] == ')') {
			i = k[i]; continue;
		}
		if (s[i] == '|') {
			q = i; break;
		}
		if (s[i] == '&' && q == -1) q = i;
	}
	if (fa) son[fa][right] = q; else root = q;
	build(l, q - 1, q, 0); build(q + 1, r, q, 1);
}
void dfs(int x) {
	if (s[x] == '0') {
		b[x] = false; return;
	}
	else if (s[x] == '1') {
		b[x] = true; return;
	}
	dfs(son[x][0]);
	if (s[x] == '&' && !b[son[x][0]]) {
		lans++; b[x] = false; return;
	}
	else if (s[x] == '|' && b[son[x][0]]) {
		rans++; b[x] = true; return;
	}
	dfs(son[x][1]); b[x] = b[son[x][1]]; return;
}
int main() {
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s; n = strlen(s);
	int ll = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') j[ll++] = i;
		else if (s[i] == ')') {
			k[i] = j[--ll];
		}
	}
	build(0, n - 1, 0, 0); dfs(root);
	cout << b[root] << '\n' << lans << " " << rans;
	return 0;
}
