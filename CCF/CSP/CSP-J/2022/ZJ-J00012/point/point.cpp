#include<bits/stdc++.h>
using namespace std;
int n,k,ans,x[505],y[505],a[1005][1005];
bool b[1005][1005];
void bs(int l,int r,int m,int t){
	b[l][r]=true;
	if(a[l+1][r]&&!b[l+1][r])bs(l+1,r,m,t+1);
	if(a[l][r+1]&&!b[l][r+1])bs(l,r+1,m,t+1);
	if(m==0){
		ans=max(ans,t);
		m+=1;
		return;
	}
	if(!a[l+1][r]&&!b[l+1][r])bs(l+1,r,m-1,t+1);
	if(!a[l][r+1]&&!b[l][r+1])bs(l,r+1,m-1,t+1);
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],a[x[i]][y[i]]=i;
	for(int i=1;i<=n;i++){
		memset(b,false,sizeof(b));
		bs(x[i],y[i],k,1);
	}
	cout<<ans;
	return 0;
}
