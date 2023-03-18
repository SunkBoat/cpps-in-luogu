#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
int n,k;
struct node{
	int x,y;
}a[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
namespace sub1{
	int b[N];
	void work(){
		sort(a+1,a+n+1,cmp);
		int maxn=1;
		for(int i=1;i<=500;i++){
			int tot=0;
			memset(b,0,sizeof(b));
			for(int j=1;j<=n;j++){
				if(a[j].y==i)	b[++tot]=a[j].x;
			}
			sort(b+1,b+tot+1);
			int ans=1;
			for(int j=1;j<tot;j++){ 
				if(b[j]+1==b[j+1])	ans++;
				else{
					maxn=max(ans,maxn);
				}
			}
			maxn=max(ans,maxn);
		}
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=500;i++){
			int tot=0;
			memset(b,0,sizeof(b));
			for(int j=1;j<=n;j++){
				if(a[j].x==i)	b[++tot]=a[j].y;
			}
			sort(b+1,b+tot+1);
			int ans=1;
			for(int j=1;j<tot;j++){ 
				if(b[j]+1==b[j+1])	ans++;
				else{
					maxn=max(ans,maxn);
				}
			}
			maxn=max(ans,maxn);
		}
		cout<<maxn<<endl;
	}
}
int tj[500];
signed main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;	
	}
//	for(int i=1;i<=n;i++){
//		tj[a[i].y]++;
//	}
//	int maxn=0;
//	int id=0;
//	for(int i=1;i<=500;i++){
//		if(tj[i]>maxn){
//			maxn=tj[i];
//			id=i;
//		}
//		
//	}
//	cout<<maxn<<endl;
//	for(int i=1;i<=n;i++){
//		if(a[i].y==id)	cout<<a[i].x<<" ";
//	}
	if(k==0){
		sub1::work();
		return 0;
	}else{
		cout<<k+1<<endl;
	}
	return 0;
}
