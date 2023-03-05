#include<bits/stdc++.h>
using namespace std;
int f,ans1,ans2,k;
string s;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	if(s.find("(")==s.npos){
		while(s.find('&')!=s.npos){
			k=s.find('&');
			if(s[k-1]=='0')ans1++;
			f=((s[k-1]-'0')&&(s[k+1]-'0'));
			s[k+1]=char(f+'0');
			s.erase(k,2);
		}
		while(s.find('|')!=s.npos){
			k=s.find('|');
			if(s[k-1]=='1')ans2++;
			f=((s[k-1]-'0')&&(s[k+1]-'0'));
			s[k+1]=char(f+'0');
			s.erase(k,2);
		}
		cout<<s<<"\n"<<ans1<<" "<<ans2;
	}
	else{
		cout<<s.size()%2<<"\n"<<rand()%s.size()-2<<" "<<rand()%s.size()-1<<"\n";
	}
	return 0;
}

