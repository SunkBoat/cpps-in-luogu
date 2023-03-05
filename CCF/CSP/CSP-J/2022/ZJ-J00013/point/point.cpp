#include<bits/stdc++.h>
using namespace std;

const int N = 510;
long long n, k, ans;
long long max_x, cy, max_y, cx;
long long x[N], y[N];
bool dot[N][N];

bool check(int x, int y)
{
	if(y > cy && x > cx) return true;
	if(x >= max_x || y >= max_y) return true;
	return false;
}

void dfs(long long X, long long Y, long long step, long long depth)
{
	//up
	int xx = X + 1, yy = Y;
	//for(int i = 1; i <= depth; i++) cout << "  ";
	//cout << xx << " " << yy << " : " << 
	if(dot[xx][yy]) dfs(xx, yy, step, depth + 1);
	else if(step == 0) ans = max(ans, depth);
	//else if(check(xx, yy)) ans = max(ans, depth + step);
	else dfs(xx, yy, step - 1, depth + 1);
	
	//right
	xx = X, yy = Y + 1;
	if(dot[xx][yy]) dfs(xx, yy, step, depth + 1);
	else if(step == 0) ans = max(ans, depth);
	//else if(check(xx, yy)) ans = max(ans, depth + step);
	else dfs(xx, yy, step - 1, depth + 1);
	
	return;
}

int main()
{
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		dot[x[i]][y[i]] = true;
		if(x[i] > max_x)
		{
			max_x = x[i];
			cy = y[i];
		}
		if(y[i] > max_y)
		{
			max_y = y[i];
			cx = x[i];
		}
	}
	
	for(int i = 1; i <= n; i++) dfs(x[i], y[i], k, 1);
	
	cout << ans << endl;
	
	return 0;
}