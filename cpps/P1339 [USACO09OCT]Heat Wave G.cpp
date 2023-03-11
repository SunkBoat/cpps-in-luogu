#include "bits/stdc++.h"
using namespace std;

struct edge {
	int to, dis, nxt;
}e[1919810];

struct Node {
	int x, dis;
	bool operator < (const Node &p) const {
		return dis > p.dis;
	}
};

priority_queue<Node> q;

int hd[1919810];
int dis[1919810];
int cnt;
int vis[1919810];
int n, m, s, t;

void add_edge(int u, int v, int d) {
	++cnt;
	e[cnt].dis = d;
	e[cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void dijkstra() {
	Node al, be;
	al.x = s;
	al.dis = 0;
	dis[s] = 0;
	//vis[s] = 1;
	q.push(al);
	
	while (!q.empty()) {
		be = q.top();
		q.pop();
		
		int u = be.x, d = be.dis;
		vis[u] = 1;
		for (int i = hd[u]; i; i = e[i].nxt) {
			al.x = e[i].to;
			al.dis = e[i].dis + d;
			if (!vis[al.x] && al.dis < dis[al.x]) {
				dis[al.x] = al.dis;
				q.push(al);
			}
		}
	}
}

int main() {
	scanf ("%d%d", &n, &m);scanf ("%d%d", &s, &t);
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		scanf ("%d%d%d", &u, &v, &d);
		add_edge(u, v, d);
		add_edge(v, u, d);
	} 
	for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
	dijkstra();
	if (dis[t] == 0x3f3f3f3f) puts("-1");
	else printf ("%d", dis[t]);
}
