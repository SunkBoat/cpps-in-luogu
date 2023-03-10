#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

using namespace std;

int minn = 0x3f3f3f3f;

struct edge {
	int to, nxt;
}e[1919810]; 

struct g {
	int x, dis;
};

int f[1919810], cnt;
int w[1919810];
int hd[1919810];
int vis[1919810];
queue<g> q;

//1e5 * 100 * 100 = 1e5 * 1e4 = 1e9
// 1e9 < 2147483647

void add_edge (int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

void bfs(int st) {
	g t, u;
	t.x = st; t.dis = 0;
	vis[st] = 1;
	q.push(t);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = hd[u.x]; i; i = e[i].nxt) {
			t.x = e[i].to;
			t.dis = u.dis + 1;
			if (!vis[t.x]) {
				f[t.x] += w[st] * t.dis;
				q.push(t);
				vis[t.x] = 1;
			}
		}
	}
} 

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int u, v;
		scanf ("%d%d%d", &w[i], &u, &v);
		if (u != 0) {
			add_edge(i, u);
			add_edge(u, i);
		}
		if (v != 0) {
			add_edge(i, v);
			add_edge(v, i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) vis[j] = 0;
		bfs(i);
	}
	for (int i = 1; i <= n; ++i) minn = min(minn, f[i]);
	printf ("%d", minn);
}
