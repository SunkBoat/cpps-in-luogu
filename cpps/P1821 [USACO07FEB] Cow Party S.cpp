#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

struct Edge {
	int to, nxt, dis;
}e[1919810];

struct Node {
	int x, dis;
	bool operator < (const Node& p) const {
		return dis > p.dis;
	}
};

priority_queue<Node> q;

int cnt;
int hd[1919810];
int dis[1919810];
int res[1919810];
int vis[1919810];
int u[1919810], v[1919810], d[1919810];
int n, m, x, mx;

void add_edge (int u, int v, int d) {
	++cnt;
	e[cnt].dis = d;
	e[cnt].nxt = hd[u];
	e[cnt].to = v;
	hd[u] = cnt;
}

void dijkstra() {
	Node al, be;
	al.x = x;
	al.dis = 0;
	dis[x] = 0;
	q.push(al);
	while (!q.empty()) {
		be = q.top();
		q.pop();
		int u, v, d;
		u = be.x;
		for (int i = hd[u]; i; i = e[i].nxt) {
			v = e[i].to;
			d = e[i].dis + be.dis;
			if (d < dis[v]) {
				al.x = v;
				al.dis = d;
				dis[v] = d;
				q.push(al);
			}
		}
	}
}

int main() {
	scanf ("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= m; ++i) {
		scanf ("%d%d%d", &u[i], &v[i], &d[i]);
		add_edge(u[i], v[i], d[i]);
	}
	for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
	dijkstra();
	for (int i = 1; i <= n; ++i) res[i] = dis[i];
	
	for (int i = 1; i <= cnt; ++i) {
		e[i].dis = e[i].nxt = e[i].to = 0;
	}
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		dis[i] = 0x3f3f3f3f;
		hd[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		add_edge(v[i], u[i], d[i]);
	}
	dijkstra();
	for (int i = 1; i <= n; ++i) res[i] += dis[i];
	for (int i = 1; i <= n; ++i) mx = max(mx, res[i]);
	
	printf ("%d", mx);
}
