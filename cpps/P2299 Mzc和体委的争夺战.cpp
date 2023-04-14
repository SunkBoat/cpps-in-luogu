#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

int n, m;

struct Edge {
	int to, dis, nxt;
}e[1919810];

int cnt;

int dis[1991810];

struct Node {
	int x, dis;
	bool operator < (const Node& p) const {
		return dis > p.dis;
	}
};

priority_queue<Node> q;

int hd[1919810];

void add_edge(int u, int v, int d) {
	++cnt;
	e[cnt].nxt = hd[u];
	e[cnt].dis = d;
	e[cnt].to = v;
	hd[u] = cnt;
}

void Dijkstra(int st) {
	Node al, be;
	al.dis = 0; al.x = st;
	dis[st] = 0;
	q.push(al);
	while (!q.empty()) {
		be = q.top(); q.pop();
		int u, v, d;
		u = be.x;
		for (int i = hd[u]; i; i = e[i].nxt) {
			v = e[i].to;
			d = e[i].dis + dis[u];
			if (dis[v] > d) {
				dis[v] = d;
				al.x = v; al.dis = d;
				q.push(al);
			}
		}
	}
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		scanf ("%d%d%d", &u, &v, &d);
		add_edge(u, v, d);
		add_edge(v, u, d);
	}
	for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
	Dijkstra(1);
	cout << dis[n];
}
