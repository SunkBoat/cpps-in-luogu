#include<bits/stdc++.h>
using namespace std;
#define int __int128
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
int n,e,d;
int k;
namespace sub{
	void work(){
		while(k--){
		if(n!=sqrt(n)*sqrt(n)){
			cout<<"NO"<<endl;
		}else{
			int x=(int)sqrt(n),y=(int)sqrt(n);
			if(e*d==(x-1)*(y-1)+1){
				cout<<(long long)x<<" "<<(long long)y<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
		}
	}
}
signed main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	k=read();
	if(n>10){
		sub::work();
		return 0;
	}
	while(k--){
		n=read();
		d=read();
		e=read();
		int now=e*d-1;
		bool fl=0;
		int a,b;
		for(int i=1;i<=sqrt(now);i++){
			if(now%i!=0)	continue;
			else{
				a=i,b=now/i;
				if(a*b==now&&(a+1)*(b+1)==n){
					fl=1;
					break;
				}
			}
		}
		if(fl==0)	cout<<"NO"<<endl;
		else{
			cout<<(long long)a+1<<" "<<(long long)b+1<<endl;
		}
	}
	return 0;
}
