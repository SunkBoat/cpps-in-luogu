#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
long long x,y,z=1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	x=read();//a
	y=read();//b
	if(x==1){
		printf("%d\n",x);
		return 0;//a^b=1;
	}
	for(int i=1;i<=y;i++){
		z*=x;
		if(z>1e9){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",z);
	return 0;
}
