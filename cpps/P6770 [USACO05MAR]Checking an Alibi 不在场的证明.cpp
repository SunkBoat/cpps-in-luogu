#include "bits/stdc++.h"

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

int n, m;
int t, c;

struct Edge {
	int to, nxt, dis;
}e[1919810];

struct Node {
	int x, dis;
	bool operator <(const Node& p) const {
		return dis > p.dis;
	}
};

priority_queue<Node> q;

int cnt, ans;
int hd[1919810];
int dis[1919810];
int vis[1919810];
int s[1919810];

void add_edge(int u, int v, int d) {
	++cnt;
	e[cnt].to = v;
	e[cnt].dis = d;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void dijkstra() {
	Node al, be;
	al.x = 1; al.dis = 0;
	dis[1] = 0;
	q.push(al);
	while (!q.empty()) {
		be = q.top();
		q.pop();
		int u, v, d;
		u = be.x;
		vis[u] = 1;
		for (int i = hd[u]; i; i = e[i].nxt) {
			v = e[i].to;
			d = e[i].dis + be.dis;
			if (!vis[v] && d < dis[v]) {
				al.x = v; al.dis = d;
				dis[v] = d;
				q.push(al);
			}
		}
	}
}

int main() {
	scanf ("%d%d", &n, &m);
	scanf ("%d%d", &c, &t);
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		scanf ("%d%d%d", &u, &v, &d);
		add_edge(u, v, d);
		add_edge(v, u, d);
	}
	for (int i = 1; i <= n; ++i) dis[i] = 0x3f3f3f3f;
	dijkstra();
	for (int i = 1; i <= c; ++i) {
		scanf ("%d", &s[i]);
		if (dis[s[i]] <= t) ++ans;
		//cout<<dis[s]<<endl;
	}
	printf ("%d\n", ans);
	for (int i = 1; i <= c; ++i) {
		if (dis[s[i]] <= t) printf ("%d\n", i);
		//cout<<dis[s]<<endl;
	}
}
