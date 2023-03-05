#include<bits/stdc++.h>
using namespace std;
long long T,n,m,k,l,r,mid,x,y,len,ans;
inline long long read (){
	long long res=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res*f;
}
int main () {
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	T=read();
	for (int t=1;t<=T;t++) {
		n=read(),m=read(),k=read();
		len=n+2-(m*k),l=1,r=len/2,ans=-1;
		while (l<=r) {
			mid=(l+r)/2;
			x=len-mid;
			y=x*mid;
			if (y==n) {
				ans=mid;
				break;
			}
			if (y>n) r=mid-1;
			else l=mid+1;
		}
		if (ans==-1) cout<<"NO"<<endl;
		else cout<<ans<<" "<<len-mid<<endl;
	}
	return 0;
}