#include<bits/stdc++.h> 
using namespace std;

int c,d,e;
char b[1000010];
string a;
stack<char>s;

int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a;
	a="("+a+")";
	for(int i=0; i<a.size(); i++){
		if(a[i]=='(')b[++c]=a[i];
		if(a[i]==')'){
			if(b[c-1]=='|'||b[c-1]=='&')b[c-2]=b[c],c-=2;
			b[c-1]=b[c];
			c--;
			if(b[c-1]=='|'||b[c-1]=='&')b[c-2]=b[c],c-=2;
		}
		if(a[i]=='|'){
			if(b[c-1]=='|'||b[c-1]=='&')b[c-2]=b[c],c-=2;
			if(b[c]=='0')b[++c]=a[i];
			else {
				e++;
				while(i<a.size()-1){
					if((a[i+1]=='|'||a[i+1]==')')&&s.empty())break;
					if(a[i+1]=='(')s.push('(');
					if(a[i+1]==')')s.pop();
					i++;
				}
				while(!s.empty())s.pop();
				continue;
			}
		}
		if(a[i]=='&'){
			if(b[c]=='1')b[++c]=a[i];
			else {
				d++;
				while(i<a.size()-1){
					if((a[i+1]=='|'||a[i+1]=='&'||a[i+1]==')')&&s.empty())break;
					if(a[i+1]=='(')s.push('(');
					if(a[i+1]==')')s.pop();
					i++;
				}
				while(!s.empty())s.pop();
				continue;
			}
		}
		if(a[i]=='1'){
			if(b[c]=='('||b[c]=='|'&&a[i+1]=='&'){
				b[++c]='1';
				continue;
			}
			if(b[c]=='|')b[c-1]='1';
			c--;
		}
		if(a[i]=='0'){
			if(b[c]=='('||b[c]=='|'&&a[i+1]=='&'){
				b[++c]='0';
				continue;
			}
			if(b[c]=='&')b[c-1]='0';
			c--;
		}
	}
	cout<<b[1]<<"\n"<<d<<" "<<e<<"\n";
	return 0;
}
