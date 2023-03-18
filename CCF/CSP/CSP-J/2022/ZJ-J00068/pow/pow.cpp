#include<bits/stdc++.h>
using namespace std;
int a,b;
void check(){
	long long base=a,cnt=b,sum=1;
	while(cnt){
		if(cnt%2==0){
			if(cnt>1){
				base*=base;
			}
			if(base>1000000000){
				cout<<-1;
				return;
			}
		}else{
			sum*=base;
			if(cnt>1){
				base*=base;
			}
			
			if(base>1000000000||sum>1000000000){
				cout<<-1;
				return;
			}
		}
		cnt/=2;
	}
	cout<<sum;
}
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	check();
	return 0;
}
