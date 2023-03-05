#include<bits/stdc++.h>
using namespace std;
string s;
long long a,o,pos;
stack<int> st;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	long long len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i] == '0' || s[i] == '1') st.push((int)(s[i]-'0'));
		else{
			if(s[i] == '(' || s[i] == ')') continue;
			int b = (s[i+1]-'0');
			int c = st.top();
			if(s[i] == '&') pos = b&c;
			else pos = b|c;
			st.push(pos);
			i++;
		}
		if(st.top() == 0 && s[i+1] == '&') a++;
		else if(st.top() == 1 && s[i+1] == '|') o++;
	}
	cout<<st.top()<<endl;
	cout<<a<<" "<<o;
	return 0;
}
