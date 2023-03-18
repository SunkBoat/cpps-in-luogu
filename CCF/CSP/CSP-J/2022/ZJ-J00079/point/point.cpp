#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
}a[510];
bool operator<(point x,point y){return x.x!=y.x?x.x<y.x:x.y<y.y;}
int n,k,f[510][110],ans;
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i][0]=1;
		for(int j=i-1;j;j--){
			if(a[j].y>a[i].y)continue;
			int dis=a[i].x-a[j].x+a[i].y-a[j].y;
			for(int p=dis-1;p<=k;p++)f[i][p]=max(f[i][p],f[j][p-dis+1]+dis);
		}
		for(int j=1;j<=k;j++)f[i][j]=max(f[i][j],f[i][j-1]+1);
		ans=max(ans,f[i][k]);
	}
	printf("%d\n",ans);
    return 0;
}
