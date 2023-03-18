#include<bits/stdc++.h>
using namespace std;
#define int __int128
const int mod=1e9;
inline int read(){
	int f=1,w=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')	f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		w=(w<<1)+(w<<3)+(c^48);
		c=getchar();
	}
	return f*w;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)	print(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	a=read();
	b=read();
	if(a>mod){
		cout<<-1<<endl;
		return 0;
	}
	if(a==1){
		cout<<1<<endl;
	}else{
		if(b>=1e5){
			cout<<-1<<endl;
		}else{
			int ans=1;
			for(int i=1;i<=b;i++){
				ans*=a;
				if(ans>mod){
					cout<<-1<<endl;
					return 0;
				}
			}
			cout<<(long long)ans<<endl;
		}
	}
	return 0;
}
