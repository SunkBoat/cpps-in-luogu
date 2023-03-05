#include<iostream>
using namespace std;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	int a,b;
	cin>>a>>b;
	long long ans=1;
	if(b<=200000000){
		for(int i=0;i<b;i++){
			ans*=a;
			if(ans>1000000000){
				cout<<-1;
				return 0;
			}
		}
	}
	else{
		int oa=a*a*a*a*a;
		for(int i=0;i<b/5;i++){
				ans*=oa;
				if(ans>1000000000){
					cout<<-1;
					return 0;
				}
			}	
		if(b%5==1){
			ans*=a;
			if(ans>1000000000){
				cout<<-1;
				return 0;
			}
		}
		if(b%5==2){
			ans*=(a*a);
			if(ans>1000000000){
				cout<<-1;
				return 0;
			}
		}
		if(b%5==3){
			ans*=(a*a*a);
			if(ans>1000000000){
				cout<<-1;
				return 0;
			}
		}
		if(b%5==4){
			ans*=(a*a*a);
			if(ans>1000000000){
				cout<<-1;
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}