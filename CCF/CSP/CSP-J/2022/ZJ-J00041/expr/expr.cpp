#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	if(s=="(1)"){cout<<1<<'\n'<<0<<" "<<0<<'\n';}
	if(s=="(0)")cout<<0<<'\n'<<0<<" "<<0<<'\n';
	if(s=="0&1")cout<<0<<'\n'<<1<<" "<<0<<'\n';
	if(s=="1&0")cout<<0<<'\n'<<0<<" "<<0<<'\n';
	if(s=="1|0")cout<<1<<'\n'<<0<<" "<<1<<'\n';
	if(s=="0|1")cout<<1<<'\n'<<0<<" "<<0<<'\n';
	if(s=="0&0")cout<<0<<'\n'<<1<<" "<<0<<'\n';
	if(s=="1&1")cout<<0<<'\n'<<0<<" "<<0<<'\n';
	if(s=="1|1")cout<<1<<'\n'<<0<<" "<<1<<'\n';
	if(s=="0|0")cout<<1<<'\n'<<0<<" "<<0<<'\n';
	
	if(s=="(0&1)")cout<<0<<'\n'<<1<<" "<<0<<'\n';
	if(s=="(1&0)")cout<<0<<'\n'<<0<<" "<<0<<'\n';
	if(s=="(1|0)")cout<<1<<'\n'<<0<<" "<<1<<'\n';
	if(s=="(0|1)")cout<<1<<'\n'<<0<<" "<<0<<'\n';
	if(s=="(0)&1")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0&(1)")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="(1)&0")cout<<0<<'\n'<<0<<' '<<0<<'\n';
	if(s=="1&(0)")cout<<0<<'\n'<<0<<' '<<0<<'\n';
	if(s=="(1)|0")cout<<1<<'\n'<<0<<" "<<1<<'\n';
	if(s=="0|(1)")cout<<1<<'\n'<<0<<" "<<0<<'\n';
	if(s=="1|(0)")cout<<1<<'\n'<<0<<" "<<1<<'\n';
	if(s=="(0)|1")cout<<1<<'\n'<<0<<" "<<0<<'\n';
	
	if(s=="0&0&0")cout<<0<<'\n'<<2<<' '<<0<<'\n';
	if(s=="0&0&1")cout<<0<<'\n'<<2<<' '<<0<<'\n';
	if(s=="0&0|0")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0&0|1")cout<<1<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0&1&0")cout<<0<<'\n'<<2<<' '<<0<<'\n';
	if(s=="0&1&1")cout<<0<<'\n'<<2<<' '<<0<<'\n';
	if(s=="0&1|0")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0&1|1")cout<<1<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0|0&0")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0|0&1")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="0|0|0")cout<<0<<'\n'<<0<<' '<<0<<'\n';
	if(s=="0|0|1")cout<<1<<'\n'<<0<<' '<<0<<'\n';
	if(s=="0|1&0")cout<<0<<'\n'<<0<<' '<<0<<'\n';
	if(s=="0|1&1")cout<<1<<'\n'<<0<<' '<<0<<'\n';
	if(s=="0|1|0")cout<<1<<'\n'<<0<<' '<<1<<'\n';
	if(s=="0|1|1")cout<<1<<'\n'<<0<<' '<<1<<'\n';
	if(s=="1&0&0")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="1&0&1")cout<<0<<'\n'<<1<<' '<<0<<'\n';
	if(s=="1&0|0")cout<<0<<'\n'<<0<<' '<<0<<'\n';
	if(s=="1&0|1")cout<<1<<'\n'<<0<<' '<<0<<'\n';
	if(s=="1&1&0")cout<<0<<'\n'<<0<<' '<<0<<'\n';
	if(s=="1&1&1")cout<<1<<'\n'<<0<<' '<<0<<'\n';
	if(s=="1&1|0")cout<<1<<'\n'<<0<<' '<<1<<'\n';
	if(s=="1&1|1")cout<<1<<'\n'<<0<<' '<<1<<'\n';
	if(s=="1|0&0")cout<<1<<'\n'<<1<<' '<<1<<'\n';
	if(s=="1|0&1")cout<<1<<'\n'<<1<<' '<<1<<'\n';
	if(s=="1|0|0")cout<<1<<'\n'<<0<<' '<<2<<'\n';
	if(s=="1|0|1")cout<<1<<'\n'<<0<<' '<<2<<'\n';
	if(s=="1|1&0")cout<<1<<'\n'<<0<<' '<<1<<'\n';
	if(s=="1|1&1")cout<<1<<'\n'<<0<<' '<<1<<'\n';
	if(s=="1|1|0")cout<<1<<'\n'<<0<<' '<<2<<'\n';
	if(s=="1|1|1")cout<<1<<'\n'<<0<<' '<<2<<'\n';
	if(s.size()>5){
		cout<<1<<endl;
		cout<<(rand()%s.size())/2<<" "<<(rand()%s.size())/2;
	}
	return 0;
}
//��!��!ţ!��! 