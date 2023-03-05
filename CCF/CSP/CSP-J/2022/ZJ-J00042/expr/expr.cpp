#include<bits/stdc++.h>
using namespace std;
string s;
struct noid{
	long long ans1,ans2;
	int d;
};
stack<noid> st1;
stack<char> st2;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	for(int i=0,n=s.size();i<n;i++){
		if(s[i]=='0'||s[i]=='1'){
			int a=s[i]-'0';
			st1.push({0,0,a});
		}
		else if(s[i]=='('){
			st2.push(s[i]);
		}
		else if(s[i]==')'){
			while(st2.top()!='('){
				char ch=st2.top();
				st2.pop();
				noid a=st1.top();
				st1.pop();
				noid b=st1.top();
				st1.pop();
				if(ch=='&'){
					if(b.d==0){
						st1.push({b.ans1+1,b.ans2,0});
					}
					else if(a.d==0){
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
					}
					else{
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
					}
				}
				else{
					if(b.d==1){
						st1.push({b.ans1,b.ans2+1,1});
					}
					else if(a.d==1){
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
					}
					else{
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
					}
				}
			}
			st2.pop();
		}
		if(s[i]=='&'){
			while(st2.size()&&st2.top()=='&'){
				st2.pop();
				noid a=st1.top();
				st1.pop();
				noid b=st1.top();
				st1.pop();
				if(b.d==0){
					st1.push({b.ans1+1,b.ans2,0});
				}
				else if(a.d==0){
					st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
				}
				else{
					st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
				}
			}
			st2.push(s[i]);
		}
		if(s[i]=='|'){
			while(st2.size()&&(st2.top()=='&'||st2.top()=='|')){
				char ch=st2.top();
				st2.pop();
				noid a=st1.top();
				st1.pop();
				noid b=st1.top();
				st1.pop();
				if(ch=='&'){
					if(b.d==0){
						st1.push({b.ans1+1,b.ans2,0});
					}
					else if(a.d==0){
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
					}
					else{
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
					}
				}
				else{
					if(b.d==1){
						st1.push({b.ans1,b.ans2+1,1});
					}
					else if(a.d==1){
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
					}
					else{
						st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
					}
				}
			}
			st2.push(s[i]);
		}
//		cout<<st1.top().d<<endl;
	}
//	cout<<st2.size()<<endl;
	while(st2.size()){
		char ch=st2.top();
		st2.pop();
		noid a=st1.top();
		st1.pop();
		noid b=st1.top();
		st1.pop();
		if(ch=='&'){
			if(b.d==0){
				st1.push({b.ans1+1,b.ans2,0});
			}
			else if(a.d==0){
				st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
			}
			else{
				st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
			}
		}
		else{
			if(b.d==1){
				st1.push({b.ans1,b.ans2+1,1});
			}
			else if(a.d==1){
				st1.push({a.ans1+b.ans1,a.ans2+b.ans2,1});
			}
			else{
				st1.push({a.ans1+b.ans1,a.ans2+b.ans2,0});
			}
		}
//		cout<<a.ans1<<" "<<a.ans2<<endl;
//		cout<<b.ans1<<" "<<b.ans2<<endl;
	}
	cout<<st1.top().d<<endl;
	cout<<st1.top().ans1<<" "<<st1.top().ans2;
	return 0;
}

