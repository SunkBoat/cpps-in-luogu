#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
struct node{
	int x,y;
}a[510];
bool cmp(node a,node b) {
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
signed main() {
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
	}
	printf("%lld\n",k+n-1);
	return 0;
}