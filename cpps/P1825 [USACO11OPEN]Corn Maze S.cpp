#include "bits/stdc++.h"
#define ma(x, y) make_pair(x, y)
using namespace std;

char c[1145][1419];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct g {
	pair<int, int> p;
	int dis;
}t, u;

queue<g> q;

map<pair<int, int>, pair<int, int> > mp;

int n, m, sx, sy, tx, ty;

int bfs() {
	g t, u;
	t.dis = 0;
	t.p = ma(sx, sy);
	q.push(t);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		//cout<<u.p.first<<' '<<u.p.second<<' '<<u.dis<<endl;
		if (u.p == ma(tx, ty)) {
			return u.dis;
		}
		for (int i = 0; i < 4; ++i) {
			int px = u.p.first + dx[i], py = u.p.second + dy[i];
			int tx = mp[ma(px, py)].first, ty = mp[ma(px ,py)].second;
			//if(px==3&&py==1)cout<<'p'<<tx<<' '<<ty<<' '<<c[tx][ty]<<' '<<u.dis+1<<endl;
			if (tx > 0 && tx <= n && ty > 0 && ty <= m && c[tx][ty] != '#') {
				t.p = ma(tx, ty);
				t.dis = u.dis + 1;
				q.push(t);
				c[tx][ty] = '#';
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) cin >> c[i][j];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (c[i][j] == '.') mp[ma(i, j)] = ma(i, j);
            else if (c[i][j] == '@') {
                sx = i; sy = j;
                c[i][j] = '.';
                mp[ma(i, j)] = ma(i, j);
            }
            else if (c[i][j] == '=') {
                tx = i; ty = j; c[i][j] = '.';
                mp[ma(i, j)] = ma(i, j);
            }
			else if (c[i][j] != '#'){
				for (int k = 1; k <= n; ++k) {
					for (int l = 1; l <= m; ++l) {
						if (c[i][j] == c[k][l] && (i != k || j != l)) {
							//cout<<i<<' '<<j<<' '<<k<<' '<<l<<':'<<c[i][j]<<' '<<c[k][l]<<endl;
							mp[ma(i, j)] = ma(k, l);
						}
					}
				}
			} else {
				mp[ma(i, j)] = ma(-1, -1);
			}
		}
	}
	int res = bfs();
	if (res == -1) cout << "No Solution.";
	else cout << res << endl;
}
