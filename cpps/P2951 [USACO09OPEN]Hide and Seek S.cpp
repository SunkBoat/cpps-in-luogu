#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

struct Edge {
	int nxt, to, dis;
}e[1919810];

struct Node {
	int x, dis;
	bool operator <(const Node& p) const {
		return dis > p.dis;
	}
};

priority_queue<Node> q;

int cnt;
int dis[1919810];
int vis[1919810];
int hd[1919810];
int mx, w, ans;

void add_edge(int u, int v, int d) {
	++cnt;
	e[cnt].dis = d;
	e[cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void dijkstra() {
	Node al, be;
	al.x = 1; al.dis = 0;
	dis[1] = 0;
	q.push(al);
	while (!q.empty()) {
		be = q.top(); q.pop();
		int u, v, d;
		u = be.x;
		vis[u] = 1;
		for (int i = hd[u]; i; i = e[i].nxt) {
			v = e[i].to;
			d = e[i].dis + be.dis;
			if (!vis[v] && d < dis[v]) {
				dis[v] = d;
				al.x = v; al.dis = d;
				q.push(al);
			}
		}
	}
}

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf ("%d%d", &u, &v);
		add_edge(u, v, 1);
		add_edge(v, u, 1);
	}
	for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
	dijkstra();
	for (int i = 1; i <= n; ++i) {
		if (dis[i] > mx) {
			mx = dis[i];
			w = i;
			ans = 1;
		} else if (dis[i] == mx) {
			ans += 1;
		}
	}
	printf ("%d %d %d", w, mx, ans);
}
