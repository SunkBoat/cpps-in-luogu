#include<iostream>
using namespace std;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	int k;
	cin>>k;
	for(int kk=0;kk<k;kk++){
		int n,d,e;
		int flag=0;
		cin>>n>>d>>e;
		int de=d*e;
		for(int pi=1;pi<=n;pi++){
			if(n%pi!=0){
				continue;
			}
			int qi=n/pi;
			if(de==pi*qi-pi-qi+2){
				flag=1;
				cout<<pi<<" "<<qi<<endl;
				break;
			}
		}
		if(flag==0){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}