#include<bits/stdc++.h>
using namespace std;
int k,n,e,d;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%d",&k);
	while(k--){
		bool flag=0;
		scanf("%d%d%d",&n,&e,&d);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i*j>n)break;
				if((i-1)*(j-1)+1>e*d)break;
				if(i*j==n&&(i-1)*(j-1)+1==e*d){
					cout<<i<<' '<<j<<"\n";
					flag=1;
					break;
				}
			}
			if(flag==1)break;
		}
		if(flag==0)cout<<"NO"<<"\n";
	}
	
	return 0;
}

