#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
long long k,n,e,d,r,l,mid;
bool flag;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	k=read();
	for(int i=1;i<=k;i++){
		flag=1;
		n=read();
		d=read();
		e=read();
		d*=e;
		for(long long j=1;j<=sqrt(n);j++){
			if(n%j==0){
				if((j-1)*(n/j-1)+1==d){
					printf("%lld %lld\n",j,n/j);
					flag=0;
					break;
				}
			}
		}
		if(flag)putchar('N'),putchar('O'),putchar('\n');
	}
}
