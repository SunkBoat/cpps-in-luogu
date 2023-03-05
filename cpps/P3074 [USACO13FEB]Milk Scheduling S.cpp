#include "bits/stdc++.h"
using namespace std;

struct Node {
	int dis, x;
};

int n, m;
int f[1919810];
int ind[1919810];
int a[1919810];
queue<Node> q;

struct edge {
	int nxt, to;
}e[1919810];

int hd[1919810];
int cnt;

void addedge(int u, int v) {
	++cnt;
	++ind[v];
	e[cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void topo() {
	Node t, pt;
	for (int i = 1; i <= n; ++i)
		if (ind[i] == 0) {
			t.dis = a[i];
			t.x = i;
			q.push(t);
			f[i] = a[i];
		}
	while (!q.empty()) {
		pt = q.front();
		int u = pt.x, s = pt.dis;
		q.pop();
		for (int i = hd[u]; i; i = e[i].nxt) {
			int v = e[i].to;
			f[v] = max(f[v], s + a[v]);
			--ind[v];
			if (ind[v] == 0) {
				t.dis = f[v];
				t.x = v;
				q.push(t);
			}
		}
	}
}

int main() {
	
// 	freopen ("msched.in", "r", stdin);
// 	freopen ("msched.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		addedge(x, y);
	}
	topo();
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, f[i]);
	printf ("%d", ans);
}
