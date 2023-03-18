#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, k, ans = 1;
struct Point
{
	LL x, y;
}a[N], stk[N];
int idx;

bool cmp(Point x, Point y)
{
	if (x.x != y.x) return x.x < y.x;
	else return x.y < y.y;
}

int main()
{
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) cin >> a[i].x >> a[i].y;
	
	sort(a + 1, a + n + 1, cmp);
	Point now = a[1];
	stk[ ++ idx] = now;
	for (int i = 2; i <= n; i ++ )
	{
		Point x = a[i];
		LL cur = abs(x.x - now.x) + abs(x.y - now.y) - 1;
		if (x.x < now.x || x.y < now.y) continue;
		if (cur == 0)
		{
			ans ++ ;
			now = x;
			stk[ ++ idx] = x;
		}
		else if (cur <= k && cur > 0)
		{
			ans += cur + 1;
			k -= cur;
			stk[ ++ idx] = x;
			now = x;
		}
	}
	
	cout << ans + k << endl;
	
	return 0;
}

