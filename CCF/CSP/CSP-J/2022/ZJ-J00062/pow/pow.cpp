#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e9;
int a,b,sum=1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++){
		sum=sum*a;
		if(sum>MAXN){
			printf("-1");
			return 0;
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}