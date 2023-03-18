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
long long n,e,d,k;
struct pp{int x,y;}c[100005];
int tot;
inline void get(){
	tot=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			tot++;
			c[tot].x=i;
			c[tot].y=n/i;
		}
	}
}
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	k=read();
	for(int t=1;t<=k;t++){
		n=read(),e=read(),d=read();
		get();
		for(int i=1;i<=tot;i++){
			if(n-e*d==c[i].x+c[i].y-2){
				cout<<c[i].x<<' '<<c[i].y<<endl;
				break;
			}
			if(i==tot)cout<<"NO"<<endl;
		}
	}
	return 0;
}
/*
2
37419524665037303 73 512596221121434
11367938665125297 1 11367938440873457





NO
77423133 146828709
*/