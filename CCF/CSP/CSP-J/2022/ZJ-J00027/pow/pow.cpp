#include<bits/stdc++.h>
using namespace std;
long long a,b,cnt=1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++){
		cnt*=a;
		if(cnt>1000000000){
			cout<<-1;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}

