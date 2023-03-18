#include<bits/stdc++.h>
using namespace std;
string s;
char ch;
int l=0,ansor=0,ansand=0;
inline bool get(bool k){
	bool now,vis=false;
	if(k==0){
		while(l<s.size()){
			if(vis==false&&(s[l]=='1'||s[l]=='0')){
				now=s[l]-'0';
				vis=true;
				l++;
			}
			if(vis==false&&s[l]=='('){
				now=get(1);
				vis=true;
				l++;
			}
			if(s[l]=='|'){
				if(now==1){
					ansor++;
					if(s[l+1]=='1'||s[l+1]=='0')l+=2;
					if(s[l+1]=='('){
						while(s[l]!=')')l++;
						l++;
					}
					continue;
				}
				l++;
				if(s[l]=='1'||s[l]=='0')now|=(s[l]-'0');
				if(s[l]=='(')now|=get(1);
				l++;
			}
			
			if(s[l]=='&'){
				if(now==0){
					ansand++;
					if(s[l+1]=='1'||s[l+1]=='0')l+=2;
					if(s[l+1]=='('){
						while(s[l]!=')')l++;
						l++;
					}
					continue;
				}
				l++;
				if(s[l]=='1'||s[l]=='0')now&=(s[l]-'0');
				if(s[l]=='(')now&=get(1);
				l++;
			}
		}
	}
	if(k==1){
		l++;
		while(s[l]!=')'){
			if(vis==false&&(s[l]=='1'||s[l]=='0')){
				now=s[l]-'0';
				vis=true;
				l++;
			}
			if(vis==false&&s[l]=='('){
				now=get(1);
				vis=true;
				l++;
			}
			if(s[l]=='|'){
				
				if(now==1){
					
					ansor++;
					if(s[l+1]=='1'||s[l+1]=='0')l+=2;
					if(s[l+1]=='('){
						while(s[l]!=')')l++;
						l++;
					}
					continue;
				}
				l++;
				if(s[l]=='1'||s[l]=='0')now|=(s[l]-'0');
				if(s[l]=='(')now|=get(1);
				l++;
			}
			
			if(s[l]=='&'){
				if(now==0){
					ansand++;
					if(s[l+1]=='1'||s[l+1]=='0')l+=2;
					if(s[l+1]=='('){
						while(s[l]!=')')l++;
						l++;
					}
					
					continue;
				}
				l++;
				if(s[l]=='1'||s[l]=='0')now&=(s[l]-'0');
				if(s[l]=='(')now&=get(1);
				l++;
			}
		}
	}
	return now;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	ch=getchar();
	while(ch=='1'||ch=='0'||ch=='&'||ch=='|'||ch=='('||ch==')'){	
		s+=ch;
		ch=getchar();
	}
	cout<<get(0)<<endl<<ansand<<' '<<ansor;
	return 0;
}
/*
1|0|(1|0|1)
*/