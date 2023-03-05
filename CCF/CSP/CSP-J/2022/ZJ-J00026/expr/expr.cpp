#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int a,b;
bool f(int l,int r){
	//find the lowest fuhao
//	if(s[l]=='('&&s[r]==')'){
//		l+=1;
//		r-=1;
//	}
	if(l==r){
		if(s[l]=='0') return 0;
		else return 1;
	}
	int yu=-1,huo=-1;
	for(int i=l;i<=r;i++){
		if(s[i]=='('){
			int j=i+1,left=1,right=0;
			for(j;left!=right;j++){
				if(s[j]=='(') left++;
				if(s[j]==')') right++;
			}
			if(i==l&&j-1==r){
				return f(l+1,r-1);
			}
			i=j-1;
		}
		else if(s[i]=='|'){
			huo=i;
		}else if(s[i]=='&'){
			yu=i;
		}
	}
	if(huo==-1){
		bool t=f(l,yu-1);
		if(t==0){
		//	cout<<"and"<<yu<<endl;
			a++;
			return 0;
		}
		return t&&f(yu+1,r);
	}else{
		bool t=f(l,huo-1);
		if(t==1){
		//	cout<<"or"<<huo<<endl;
			b++;
			return 1;
		}
		return t||f(huo+1,r);
	}
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	len=s.length();
	cout<<f(0,len-1)<<endl<<a<<' '<<b;
	return 0;
}
/*
(0|1&0|1|1|(1|1))&(0&1&(1|0)|0|1|0)&0

*/