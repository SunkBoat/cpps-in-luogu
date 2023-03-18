#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[505];
int n,k;
bool cmp(node x,node y){
	if(x.x<y.x)return true;
	if(x.x==y.x&&x.y<y.y)return true;
	return false;
}
bool check(){
	int maxn=0,kk=k;
	for(int i=1;i<=n;i++){
		int sum=1;
		for(int j=i+1;j<=n+1;j++){
			if(a[j].x==a[j].y&&a[j].x==0){
				sum+=kk;
				break;
			}
			if(a[j].x==a[j-1].x&&a[j].y==a[j-1].y+1||a[j].y==a[j-1].y&&a[j].x==a[j-1].x+1){
				sum++;
			}
			else if(a[j].x==a[j-1].x&&a[j].y-a[j-1].y-1<=kk){
				sum+=a[j].y-a[j-1].y;
				kk-=a[j].y-a[j-1].y-1;
			}
			else if(a[j].y==a[j-1].y&&a[j].x-a[j-1].x-1<=kk){
				sum+=a[j].x-a[j-1].x;
				kk-=a[j].x-=a[j-1].x-1;
			}
			else break;
		}
		kk=k;
		maxn=max(maxn,sum);
	}
	return maxn;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	printf("%d",check());
	return 0;
}

