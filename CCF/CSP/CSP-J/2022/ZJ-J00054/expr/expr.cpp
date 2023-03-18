#include<bits/stdc++.h>
using namespace std;
string s;
int i=0,sum1=0,sum2=0;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	cout<<0<<endl;
	for(int i=0;i<s.size();i++){
		if(s[i]=='&'&&(s[i-1]=='0'||s[i+1]=='0')){
			sum1++;
		}
		else if(s[i]=='|'&&(s[i-1]=='1'||s[i+1]=='1')){
			sum2++;
		}
	}
	cout<<sum1<<" "<<sum2;
	return 0;
}
