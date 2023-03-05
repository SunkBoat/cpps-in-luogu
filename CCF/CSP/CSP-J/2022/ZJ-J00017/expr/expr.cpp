#include<bits/stdc++.h> 
using namespace std;
int cmp[155]={};
string s="";

struct node{
	long long huo,yu;
	bool data;
	node(){huo=yu=0;}
};

stack<node> num;
stack<char> f;

inline void oper(){
	node fit,sed,ans;
	fit=num.top();
	num.pop();
	sed=num.top();
	num.pop();
	if( f.top()=='&' ){
		ans.data=fit.data&sed.data;
		ans.huo=fit.huo+sed.huo,ans.yu=fit.yu+sed.yu;
		if( sed.data==0 )
			ans.yu++;
		num.push(ans);
	}
	else{
		ans.data=fit.data|sed.data;
		ans.huo=fit.huo+sed.huo,ans.yu=fit.yu+sed.yu;
		if( sed.data==1 )
			ans.huo++;
		num.push(ans);
	}
	f.pop();
	return;
}

int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cmp['|']=1,cmp['&']=2,cmp['(']=0,cmp[')']=0;
	cin>>s;
	long long len=s.size();
	for(long long i=0;i<len;i++){
		if( s[i]=='0' || s[i]=='1' ){
			node v;
			v.data=s[i]-48;
			num.push(v);
		}
		else{
			if( s[i]!='(' ){
				while( !f.empty() && cmp[int(s[i])]<cmp[int(f.top())] )
					oper();
			}
			f.push(s[i]);
			if( f.top()==')' ){
				f.pop();
				f.pop();
			}
		}
	}
	while( !f.empty() )
		oper();
	cout<<num.top().data<<'\n'<<num.top().yu<<' '<<num.top().huo;
	return 0;
}
