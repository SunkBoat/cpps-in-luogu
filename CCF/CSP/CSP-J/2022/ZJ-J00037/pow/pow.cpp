#include<bits/stdc++.h>
using namespace std;
int a,b;
long long sum=1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++){
		sum*=a;
		if(sum>1000000000){
			cout<<"-1";
			return 0;
		}
	}
	printf("%lld",sum);
	
	return 0;
}