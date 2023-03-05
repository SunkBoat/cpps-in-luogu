#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int x,y;
} a[555];
int n,K;
int f[555][111];
int s[555];
bool cmp(node x,node y) { //x第一关键字 y第二关键字
	return x.x==y.x ? x.y<y.y : x.x<y.x;
}
signed main() {
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp); 
	int ans=0; 
	for(int k=0; k<=K; k++) {//2.5e7，时间复杂度卡得刚刚好 
		for(int i=1; i<=n; i++) {//现在正在看的点 
			for(int j=1; j<i; j++) {//转移的点 
				int p=a[i].x-a[j].x+a[i].y-a[j].y-1;//需要多少个点 
				if(a[j].y<=a[i].y&&p<=k) { //x肯定兼容 若y兼容 则一定兼容
					f[i][k]=max(f[i][k],f[j][k-p]+p+1);
				}
				ans=max(ans,f[i][k]+1+K-k);
			}
		}
	}
    printf("%d",ans);
    return 0;
}

