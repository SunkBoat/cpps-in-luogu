#include<bits/stdc++.h>
using namespace std;
int n,k,mx;
struct noid{
	int x,y;
}a[510];
int f[510][110];
int cmp(noid a,noid b){
	if(a.x==b.x) return a.y<b.y;
	else return a.x<b.x;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n;j++)
			f[j][i]=1;
	}
//	for(int i=1;i<=n;i++){
//		cout<<a[i].x<<" "<<a[i].y<<endl;
//	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			int xx=a[i].x-a[j].x;
			int yy=a[i].y-a[j].y;
//			if(i==7&&j==5) cout<<xx<<" "<<yy<<endl;
			if(xx<0||yy<0) continue;
			for(int o=xx+yy-1;o<=k;o++){
				f[i][o]=max(f[i][o],f[j][o-xx-yy+1]+xx+yy);
//				if(i==5&&j==4&&o==0){
//					cout<<f[i][o]<<" "<<f[j][o-xx-yy+1]+1<<endl;
//					cout<<o<<endl;
//				}
			}
		}
//		cout<<f[i][1]<<" "<<a[i].x<<" "<<a[i].y<<endl;
	}
	for(int i=0;i<=k;i++){
		for(int j=1;j<=n;j++){
			mx=max(f[j][i]+k-i,mx);
		}
	}
	cout<<mx;
	return 0;
}

