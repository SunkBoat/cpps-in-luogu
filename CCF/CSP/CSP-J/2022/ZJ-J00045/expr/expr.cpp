#include<bits/stdc++.h>
using namespace std;
string in;
int yu,huo;
void f(){//res & |
	if(in=="0|0")	cout<<0<<"\n"<<0<<" "<<0;
	else if(in=="0|1")	cout<<1<<"\n"<<0<<" "<<0;
	else if(in=="1|0"||in=="1|1")	cout<<1<<"\n"<<0<<" "<<1;
	else if(in=="1&0")	cout<<0<<"\n"<<0<<" "<<0;
	else if(in=="1&1")	cout<<1<<"\n"<<0<<" "<<0;
	else if(in=="0&0"||in=="0&1")	cout<<0<<"\n"<<1<<" "<<0;
	else if(in=="(0|0)|0"||in=="(0|1)&0"||in=="0|(1&0)"||in=="0|(1&0)"||in=="0|(1&0)")	cout<<0<<"\n"<<0<<" "<<0;
	else if(in=="(0|1)|0"||in=="(0|1)|0"||in=="0|(0|0|)"||in=="0|(0|1)")cout<<1<<"\n"<<0<<" "<<0;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>in;
	int len=in.size();
	if(len<=5)	f();
	else{
		bool p=0;
		for(int i=0;i<len;i++){
			if(in[i]=='&'){
				break;
			}
			if(in[i]=='|'){
				p=1;
				break;
			}
			if(p){
				for(int i=0;i<len;i++){
					if(in[i]=='1'){
						cout<<1<<"\n"<<0<<" "<<1;
						return 0;
					}
					cout<<0<<"\n"<<0<<" "<<1;
				}
			}
			else{
				for(int i=0;i<len;i++){
					if(in[i]=='0'){
						cout<<0<<"\n"<<1<<" "<<0;
						return 0;
					}
					cout<<1<<"\n"<<1<<" "<<0;
				}
			}
		}
	}
	return 0;
}
/*

*/
