#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define ul unsigned long long

struct g {
	int x, y, d;
};

using namespace std;

char mp[1919][810];
int vis[1919][810];
int dis[1919][810];
int ans;

int sx, sy;

int dx[4] = {-2, 0, 0, 2};
int dy[4] = {0, -2, 2, 0};
int tx[4] = {-1, 0, 0, 1};
int ty[4] = {0, -1, 1, 0};

int n, m;

queue<g> q;

void bfs() {
	g t, u, r;
	u.x = sx; u.y = sy; u.d = 0;
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	//cout<<"sx sy:"<<sx<<' '<<sy<<endl;
	for (int i = 0; i < 4; ++i) {
		t.x = u.x + tx[i]; t.y = u.y + ty[i]; t.d = u.d + 1;
		//cout<<t.x<<' '<<t.y<<' '<<mp[t.x][t.y]<<' '<<vis[t.x][t.y]<<endl;
		if (mp[t.x][t.y] == ' ' && !vis[t.x][t.y]) {
			dis[t.x][t.y] = min(dis[t.x][t.y], t.d);
			vis[t.x][t.y] = 1;
			//cout<<dis[t.x][t.y]<<' '<<t.x<<' '<<t.y<<' '<<t.d<<endl;
			q.push(t);
		}
	}
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			t.x = u.x + dx[i]; t.y = u.y + dy[i]; t.d = u.d + 1;
			r.x = u.x + tx[i]; r.y = u.y + ty[i];
			if (mp[t.x][t.y] == ' ' && mp[r.x][r.y] == ' ' && !vis[t.x][t.y]) {
				dis[t.x][t.y] = min(dis[t.x][t.y], t.d);
				vis[t.x][t.y] = 1;
				q.push(t);
			}
		}
	}
}

void func1() {
	for (int i = 0; i < 1919; ++i)
		for (int j = 0; j < 810; ++j) dis[i][j] = 0x3f3f3f3f;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			
			if (i == 1 || i == n || j == 1 || j == m) {
//				if(i==6&&j==11)cout<<"I AK IOI"<<endl;
//				if(mp[i][j]!=' '&&i==6&&j==11)cout<<"?!\n";
				if (mp[i][j] == ' ') {
					sx = i;
					sy = j;
					//cout<<sx<<' '<<sy<<' '<<i<<' '<<j<<endl;
					mp[i][j] = '#';
					return;
				}
			}
		}
	}
}

void func2() {
	for (int i = 0; i < 1919; ++i) {
		for (int j = 0; j < 810; ++j) vis[i][j] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 || i == n || j == 1 || j == m) {
				if (mp[i][j] == ' ') {
					sx = i;
					sy = j;
					//cout<<i<<' '<<j<<' '<<mp[i][j]<<endl;
					mp[i][j] = '#';
					return;
				}
			}
		}
	}
}

int main() {
	//IOS
	scanf ("%d%d", &m, &n);
	m = 2 * m + 1;
	n = 2 * n + 1;
	gets(mp[0]);
	for (int i = 1; i <= n; ++i) {
		gets(mp[i] + 1);
	}
//	cout<<mp[6][11]<<n<<' '<<m<<' '<<endl;
	bool flg = 0;
	func1();
//	cout<<sx<<' '<<sy<<endl;
	bfs();
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			if(dis[i][j]!=0x3f3f3f3f)cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	} 
	func2();
	bfs();
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			if(dis[i][j]!=0x3f3f3f3f)cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	} 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) 
			if (dis[i][j] != 0x3f3f3f3f) ans = max(ans, dis[i][j]);
	}
	cout << ans;
}
