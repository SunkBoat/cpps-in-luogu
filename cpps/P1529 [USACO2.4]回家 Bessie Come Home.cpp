#include "bits/stdc++.h"
using namespace std;

struct Edge {
	int to, nxt, dis;
}e[1919810];

int cnt;
char w;
int m;
int hd[1919810];
int dis[1919810];
int vis[1919810];
int mn = 0x3f3f3f3f;

struct Node {
	int x, dis;
	bool operator < (const Node& p) const {
		return dis > p.dis;
	}
};

priority_queue<Node> q;

void add_edge(int u, int v, int d) {
	++cnt;
	e[cnt].dis = d;
	e[cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void dijkstra(int st) {
	Node al, be;
	al.x = st;
	al.dis = 0;
	q.push(al);
	dis[st] = 0;
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
	scanf ("%d", &m);
	for (int i = 1; i <= m; ++i) {
		char u, v;int d;
		cin >> u >> v;
		scanf ("%d", &d);
		add_edge(int(u), int(v), d);
		add_edge(int(v), int(u), d);
	}
	for (int i = 1; i <= 500; ++i) dis[i] = 0x3f3f3f3f;
	dijkstra(int('Z'));
	for (int i = int('A'); i <= int('Y'); ++i) {
		if (dis[i] < mn) {
			mn = dis[i];
			w = char(i);
		}
	}
	cout << w << ' ' << mn;
}
