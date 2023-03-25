#include "bits/stdc++.h"
#define N 0
#define E 1
#define S 2
#define W 3
#define Tr(x) ((x + 1) % 4)
#define Tl(x) ((x + 3) % 4)
using namespace std;

int n, m;

struct Node {
	int x, y, dis;
	int f;
};

queue<Node> q;

int dx[4][4] = {
	{0, -1, -2, -3}, //北
	{0, 0, 0, 0}, //东
	{0, 1, 2, 3}, //南
	{0, 0, 0, 0}  //西
};
int dy[4][4] = {
	{0, 0, 0, 0}, //北
	{0, 1, 2, 3}, //东
	{0, 0, 0, 0}, //南
	{0, -1, -2, -3} //西
};

int c[1919][810];
int mp[1919][810];
int vis[1919][810][4];
int sx, sy, tx, ty;
char qwq;

// debug------------------------------------------------------------------------
void Output_dx_dy() {
	cout << "dx:" << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << dx[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "dy:" << endl;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << dy[i][j] << ' ';
		}
		cout << endl;
	}
}
void outputNewmap() {
	cout << endl;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cout << mp[i][j] << ' ';
		cout << endl;
	}
}
//-------------------------------------------------------------------------debug

void getNewmap() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (c[i][j] == 1) {
				mp[i - 1][j - 1] = mp[i - 1][j] = mp[i][j - 1] = mp[i][j] = 1;
			}
		}
	}
}

int bfs() {
	Node t, u;
	t.x = sx;
	t.y = sy;
	t.dis = 0;
	if (qwq == 'S') t.f = S;
	if (qwq == 'W') t.f = W;
	if (qwq == 'N') t.f = N;
	if (qwq == 'E') t.f = E;
	q.push(t);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (u.x == tx && u.y == ty) {
			return u.dis;
		}
		//cout << u.x << ' ' << u.y << ' ' << u.f << ' ' << u.dis << endl;
		
		//左转
		t.x = u.x; t.y = u.y; t.dis = u.dis + 1; t.f = Tl(u.f);
		if (!vis[t.x][t.y][t.f]) {
			vis[t.x][t.y][t.f] = 1;
			q.push(t);
		}
		//右转
		t.x = u.x; t.y = u.y; t.dis = u.dis + 1; t.f = Tr(u.f);
		if (!vis[t.x][t.y][t.f]) {
			vis[t.x][t.y][t.f] = 1;
			q.push(t);
		} 
		//直行
		for (int i = 1; i < 4; ++i) {
			t.x = u.x + dx[u.f][i];
			t.y = u.y + dy[u.f][i];
			
			t.dis = u.dis + 1;
			t.f = u.f;
			if (mp[t.x][t.y] == 1) break;
			if (t.x < 1 || t.y < 1 || t.x >= n || t.y >= m) break;
			if (!vis[t.x][t.y][t.f]) {
				vis[t.x][t.y][t.f] = 1;
				q.push(t);
			}
		}
	}
	return -1;
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) scanf ("%d", &c[i][j]);
	}
	getNewmap();
	//outputNewmap();
	scanf ("%d%d%d%d", &sx, &sy, &tx, &ty);
	cin >> qwq;
	cout << bfs();
}
