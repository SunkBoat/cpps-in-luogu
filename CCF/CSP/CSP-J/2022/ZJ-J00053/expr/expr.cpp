#include<bits/stdc++.h>
using namespace std;

string s;
int len,p1,p2;

int dfs(int l,int r)
{
	int h=0;
	for(;;){
	int u=-1,l1,r1,l2,r2,st=0;
	for(int i=l;i<=r;i++){
		if(s[i]=='&'&&st==0){
			u=i;
			break;
		}
		else if(s[i]=='('){
			st++;
		}
		else if(s[i]==')'){
			st--;
		}
	}
	st=0;
	for(int i=l;i<=r;i++){
		if(s[i]=='|'&&u==-1&&st==0){
			u=i;
			break;
		}
		else if(s[i]=='('){
			st++;
		}
		else if(s[i]==')'){
			st--;
		}
	}
	if(u==-1)break;
	if(s[u-1]==')'){
		st=0;
		int o;
		for(int i=u-1;i>=l;i--){
			if(s[i]=='('){
				st--;
			}
			if(s[i]==')'){
				st++;
			}
			if(st==0){
				o=i;
				break;
			}
		}
		l1=dfs(o+1,u-2);
		l2=o;
	}
	else{
		l1=s[u-1]-'0';
		l2=u-1;
	}
	if(s[u]=='&'&&l1==0){
		p1++;
		if(s[u+1]=='('){
			int o;
			st=0;
			for(int i=u+1;i<=r;i++){
				if(s[i]=='('){
					st--;
				}
				if(s[i]==')'){
					st++;
				}
				if(st==0){
					o=i;
					break;
				}
			}
			r2=o;
		}
		else{
			r2=u+1;
		}
		for(int i=l2;i<=r2;i++){
			s[i]='0';
		}
		h=0;
		continue;
	}
	else if(s[u]=='|'&&l1==1){
		p2++;
		if(s[u+1]=='('){
			int o;
			st=0;
			for(int i=u+1;i<=r;i++){
				if(s[i]=='('){
					st--;
				}
				if(s[i]==')'){
					st++;
				}
				if(st==0){
					o=i;
					break;
				}
			}
			r2=o;
		}
		else{
			r2=u+1;
		}
		for(int i=l2;i<=r2;i++){
			s[i]='1';
		}
		h=1;
		continue;
	}
	if(s[u+1]=='('){
		int o;
		st=0;
		for(int i=u+1;i<=r;i++){
			if(s[i]=='('){
				st--;
			}
			if(s[i]==')'){
				st++;
			}
			if(st==0){
				o=i;
				break;
			}
		}
		r1=dfs(u+2,o-1);
		r2=o;
	}
	else{
		r1=s[u+1]-'0';
		r2=u+1;
	}
	int o=0;
	if(s[u]=='|')o=l1|r1;
	if(s[u]=='&')o=l1&r1;
	for(int i=l2;i<=r2;i++){
		s[i]=o+'0';
	}
	h=o;
	}
	return h;
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	len=s.size();
	s=' '+s;
	cout<<dfs(1,len)<<"\n"<<p1<<" "<<p2;
	return 0;
}