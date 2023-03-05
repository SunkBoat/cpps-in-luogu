#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,k=2147483647;
inline long long read (){
	long long res=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res*f;
}
int main () {
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	n=read(),m=read();
	if (n==1) {
		cout<<1;
		return 0;
	}
	if (n==k) {
		if (m>1) cout<<-1;
		else cout<<n;
		return 0;
	}
	while (k) k/=n,ans++;
	if (m<ans) {
		ans=n;
		for (int i=2;i<=m;i++) ans*=n;
		cout<<ans;
	}
	else cout<<-1;
	return 0;
}