#include "bits/stdc++.h"
using namespace std;

int n, s;

int t[1919][810];
int vis[1919][810];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int dfs(int x, int y, int p) {
    int qwq = 1;
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= n
         && 
         !vis[tx][ty] && abs(t[tx][ty] - t[x][y]) <= p) {
//          if(p==3)cout<<x<<','<<y<<' '<<tx<<','<<ty<<':'<<
//			t[x][y]<<' '<<t[tx][ty]<<' '<<abs(t[tx][ty] - t[x][y])<<' '<<
//			vis[tx][ty]<<endl;
			vis[tx][ty] = 1;
            qwq += dfs(tx, ty, p);
            //cout<<qwq<<endl;
            //vis[tx][ty] = 0;
        }
    }
    return qwq;
}

bool chk(int t) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) vis[i][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
        	vis[i][j] = 1;
			int res = dfs(i, j, t);
        	
        // 	if (res >= 2 && t == 3) cout << endl;
            if (res >= s) {
                //cout<<i<<' '<<j<<' '<<t<<' '<<res<<' '<<s<<endl;
                //cout<<endl;
                //if (dfs(i, j, t) < s) cout << "????" << endl;
                return 1;
            }
        }
    }
    return 0;
}

int sea() {
    int l = 0, r = 1919810;
    while (l < r) {
        int m = (l + r) / 2;
        if (chk(m)) r = m;
        else l = m + 1;
        //cout<<l<<' '<<r<<endl;
    }
    return r;
}

int main() {
    scanf ("%d", &n);
    s = int(ceil(0.5 * n * n));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) scanf ("%d", &t[i][j]);
    }
    // cout<<endl;
    cout << sea();
}
