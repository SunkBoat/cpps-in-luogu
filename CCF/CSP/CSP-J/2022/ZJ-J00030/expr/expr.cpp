#include<bits/stdc++.h>
using namespace std;
string s;
int cnt_a,cnt_b;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='&'){
			if(s[i-1]=='0'){
				cnt_a++;
				if(s[i+1]=='('){
					while(s[i-1]!=')') i++;
				}
			}
		}
		else if(s[i]=='|'){
			if(s[i-1]=='1'){
				cnt_b++;
				if(s[i+1]=='('){
					while(s[i-1]!=')') i++;
				}
			}
		}
	}
	cout<<1<<endl;
	cout<<cnt_a<<" "<<cnt_b<<endl;
	return 0;
}