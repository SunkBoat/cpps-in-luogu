#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long res=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
int n,k;
int x,y;
bool a[205][205];
int f[205][205][205];
int ans=0;
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	n=read();
	k=read();
	for(int i=1;i<=n;i++){
		x=read(),y=read();
		a[x][y]=true;
	}
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			if(a[i][j])f[i][j][0]=max(f[i][j][0],max(f[i][j-1][0],f[i-1][j][0])+1);
		}
	}
	for(int i=1;i<=200;i++){
		for(int j=1;j<=200;j++){
			for(int t=1;t<=k;t++){
				if(a[i][j])f[i][j][t]=max(f[i][j][t],max(f[i][j-1][t],f[i-1][j][t])+1);
				f[i][j][t]=max(f[i][j][t],max(f[i][j-1][t-1],f[i-1][j][t-1])+1);
				ans=max(ans,f[i][j][t]);
			}
		}
	}
	cout<<ans;
	
	return 0;
}