#include<bits/stdc++.h>
using namespace std;
long long n=1;
int a,b;
int main(void){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d %d",&a,&b);
	for(int i=1;i<=b;i++){
		n*=a;
		if(n>1e9){printf("-1");
		return 0;}
	}
	cout<<n;
	return 0;
}