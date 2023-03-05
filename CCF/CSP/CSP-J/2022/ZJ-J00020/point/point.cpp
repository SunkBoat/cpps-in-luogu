#include<cstdio>
#include<algorithm>

using namespace std;
struct pos {
	int x, y;
};
pos a[600];
int data[600][600], l[600];
int dp[600];

bool cmp(pos x, pos y){
	if(x.x == y.x)
		return x.y < y.y;
	return x.x < y.y;
}

int main() {
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	
	int n, k;
	scanf("%d%d", &n, &k);
	/*for(int i = 1; i <= n; i ++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	
	sort(a+1, a+1+n, cmp);
	
	for(int i = n; i >= 1; i --)
	{
		for(int j = i+1; j <= n; j ++)
		{
			if(a[i].y<a[j].y)
				data[i][j] = a[j].x - a[i].x + a[j].y - a[i].x;
		}
	}
	for(int i = 1; i <= n ; i ++)
	{
		if(!l[i])
			l[i] = 1;
		for(int j = i+1; j <= n; j ++)
		{
			if(data[i][j] == 1)
				l[j] = max(l[j], l[i]+1);
		}
	}
	for(int i = 1; i <= n; i ++)*/
	printf("%d", &n);
}
