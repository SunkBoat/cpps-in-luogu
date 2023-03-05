#include<bits/stdc++.h>
using namespace std;
int ans1,ans2;
int zkhq(int i,int r,string s){
	int q=1,h=0;;
	for(int j=i+1;j<=r;j++){
		if(s[j]=='('){
			q++;
		}
		if(s[j]==')'){
			h++;
		}
		if(q==h){
			return j;
		}
	}
	return 0;
}
int dfs(int l,int r,string s){
	cout<<l<<" "<<r<<endl;
	if(s[l]=='('&&s[r]==')'){
		l++;r--;
	}
	if(l==r){
		if(s[l]=='0')
		return 0;
		return 1;
	}
	for(int i=l;i<=r;i++){
		if(s[i]=='('){
			int j=zkhq(i,r,s);
			cout<<i<<" "<<j<<endl;
			if(i==l+2&&s[l]=='0'&&s[1]=='&'){
				ans1++;
			}
			if(i==l+2&&s[l]=='1'&&s[1]=='|'){
				ans2++;
			}
			if(i==l){
				if(s[j+1]=='&')
				return dfs(i+1,j-1,s)&dfs(j+2,r,s);
				if(s[j+1]=='|')
				return dfs(i+1,j-1,s)|dfs(j+2,r,s);
			}
			if(j==r){
				if(s[i-1]=='&')
				return dfs(l,i-2,s)&dfs(i+1,j-1,s);
				if(s[i-1]=='|')
				return dfs(l,i-2,s)|dfs(i+1,j-1,s);
			}
			if(s[i-1]=='&'&&s[j+1]=='&'){
				return dfs(l,i-2,s)&dfs(i+1,j-1,s)&dfs(j+2,r,s);
			}
			if(s[i-1]=='|'&&s[j+1]=='&'){
				return dfs(l,i-2,s)|(dfs(i+1,j-1,s)&dfs(j+2,r,s));
			}
			if(s[i-1]=='&'&&s[j+1]=='|'){
				return (dfs(l,i-2,s)&dfs(i+1,j-1,s))|dfs(j+2,r,s);
			}
			if(s[i-1]=='|'&&s[j+1]=='|'){
				return dfs(l,i-2,s)|dfs(i+1,j-1,s)|dfs(j+2,r,s);
			}
		}
	}
	for(int i=l;i<=r;i++){
		if(s[i]=='|'){
			if(dfs(l,i-1,s)){
				ans2++;
				return 1;
			}
			return dfs(l,i-1,s)|dfs(i+1,r,s);
		}
	}
	for(int i=l;i<=r;i++){
		if(s[i]=='&'){
			if(!dfs(l,i-1,s)){
				ans1++;
				return 0;
			}
			return dfs(l,i-1,s)&dfs(i+1,r,s);
		}
	}
	return 0;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	cout<<dfs(0,len-1,s)<<endl;
	cout<<ans1<<" "<<ans2;
	return 0;
} 
