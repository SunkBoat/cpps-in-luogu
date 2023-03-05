#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d%d",&a,&b,&c);c=1;
	for(int i=1;i<=b;i++){
		c*=a;
		if(c>1e9){printf("-1\n");return 0;}
	}
	printf("%d",c);
}
