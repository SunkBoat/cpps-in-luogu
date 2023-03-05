#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int a,b,t;
int ans;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr,out","w",stdout);
	
	s2=" ";
	getline(cin,s1);
	int l1=s1.size();
	for(int i=0;i<l1;i++){
		if(s1[i]!='('&&s1[i]!=')') s2+=s1[i];
		if(s1[i]=='&'&&s1[i-1]=='0'){
			t++;
			a++;
		}
		if(s1[i]=='|'&&s1[i-1]=='1'){
			t--;
			b++;
		}
	}
	int l2=s2.size();
	for(int i=0;i<l2;i++){
		if(i%2==1){
			if(s2[i]=='&')
				ans=(s2[i-1]-'0')&(s2[i+1]-'0');
			else
				ans=(s2[i-1]-'0')|(s2[i+1]-'0');
			s2[i+1]=ans;
		}
	}
	cout<<ans<<"\n";
	cout<<abs(a-abs(t))<<' ';
	cout<<abs(b-abs(t));
	
	return 0;
}