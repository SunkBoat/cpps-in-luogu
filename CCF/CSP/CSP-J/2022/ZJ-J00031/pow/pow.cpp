#include<bits/stdc++.h>
using namespace std;
int a,b;
__int128 ans=1;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
signed main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	a=read(),b=read();
	if(a==1)printf("1"),exit(0);
	for(int i=1;i<=b;++i){
		ans*=a;
		if(ans>1e9)printf("-1"),exit(0);
	}
	int x=ans;
	printf("%d",x);
}
