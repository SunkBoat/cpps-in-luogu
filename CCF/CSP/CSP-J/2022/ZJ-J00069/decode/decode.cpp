#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,n,e,d,fla;
bool go(int a,int b){
	int tmp=(a-1)*(b-1)+1;
	if(tmp==e*d){if(fla) putchar('\n');
	else fla=1;
	printf("%d %d",a,b);
	return true;}
	return false;
}
signed main(void){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	for(;k;k--){
		bool flag=0;
		scanf("%d %d %d",&n,&e,&d);
		if(n==1) go(1,1);
		else for(int i=2;i*i<=n;i++) if(n%i==0) if(go(i,n/i)){
			flag=1;
			break;
		}
		if(!flag){
			if(fla) putchar('\n');
			else fla=1;
			printf("NO");
		}
	}
	return 0;
}
