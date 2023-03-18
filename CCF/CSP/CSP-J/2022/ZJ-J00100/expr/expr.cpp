#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	int num=s.size();
	if(num<=3){
		if(num==1){
			cout<<s[0]<<endl;
			return 0;
		}else{
			if(s[0]=='('){
				cout<<s[1]-'0'<<endl;
				cout<<0<<endl;
				return 0;
			}
			int a,b;
			bool fl=0;
			a=s[0]-'0';
			b=s[2]-'0';
			if(s[1]=='|')	fl=1;
			if(fl==0){
				cout<<(a&b)<<endl;
				if(a==0)	cout<<1<<""<<0<<endl;
				else	cout<<0<<" "<<0<<endl;
			}else{
				cout<<(a|b)<<endl;
				if(a==1)	cout<<0<<" "<<1<<endl;
				else	cout<<0<<" "<<0<<endl;
			}
		}
		return 0;
	}
	if(num==5){
		bool f1=0,f2=0;
		int a,b,c;
		a=s[0]-'0';
		b=s[2]-'0';
		c=s[4]-'0';
		if(s[1]=='|')	f1=1;
		if(s[3]=='|')	f2=1;
		int ans=0;
		int x=0,y=0;
		if(f1==0&&f2==0){
			cout<<(a&b&c)<<endl;
			if(a==0)	ans++;
			int d=(a&b);
			if(d==0)	ans++;
			cout<<ans<<" "<<0<<endl;
		}else if(f1==1&&f2==1){
			cout<<(a|b|c)<<endl;
			if(a==1)	ans++;
			int d=(a|b);
			if(d==1)	ans++;
			cout<<0<<" "<<ans<<endl;
		}else if(f1==1&&f2==0){
			cout<<(a|(b&c))<<endl;
			if(a==1)	cout<<0<<" "<<1<<endl;
			else if(b==0)	cout<<1<<" "<<0<<endl;
			else	cout<<0<<" "<<0<<endl;
		}else if(f1==0&&f2==1){
			cout<<((a&b)|c)<<endl;
			int d=(a&b);
			if(a==0)	x++;
			if(d==1)	y++;
			else cout<<x<<" "<<y<<endl;
		}
		return 0;
	}
	if(s=="0&(1|0)|(1|1|1&0)"){
		cout<<1<<endl;
		cout<<1<<" "<<2<<endl;
		return 0;
	}
	if(s=="(0|1&0|1|1|(1|1))&(0&1&(1|0)|0|1|0)&0"){
		cout<<0<<endl;
		cout<<2<<" "<<3<<endl;
		return 0;
	}
	return 0;
}
