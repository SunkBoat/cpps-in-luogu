#include<bits/stdc++.h>
using namespace std;
int k;
void work(){
	long long a,b,c,q,p,tmp1,tmp2;
	cin>>a>>b>>c;
	tmp1=a-b*c+2;
	tmp2=sqrt(tmp1*tmp1-4*a);
	if(tmp2*tmp2!=tmp1*tmp1-4*a){
		cout<<"NO\n";
		return;
	}
	cout<<(tmp1-tmp2)/2<<" "<<(tmp1+tmp2)/2<<endl;
}
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	for(int i=0;i<k;i++){
		work();
	}
	return 0;
}
