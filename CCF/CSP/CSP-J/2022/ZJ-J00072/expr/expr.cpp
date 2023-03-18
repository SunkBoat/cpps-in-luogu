#include<bits/stdc++.h>
using namespace std;
string s;
int l,w,w2,a,b;
int ss[1000010];
char c[1000020];
bool check(int x){
	for(int i=x+1;i<s.size();i++){
		if(s[i]=='&') return 0;
		if(s[i]==')') return 1;
		if(s[i]=='|') return 1;
	}
	return 1;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='1'||s[i]=='0'){
			ss[w++]=s[i]-'0';
			if(c[w2-1]=='&'){
				while(w>1&&(c[w2-1]=='|'||c[w2-1]=='&')){
					if(c[w2-1]=='|'){
						ss[w-2]|=ss[w-1];
						w--;w2--;
					}
					if(c[w2-1]=='&'){
						ss[w-2]&=ss[w-1];
						w--;w2--;
					}
				}
			}
		}
		else if(s[i]=='|'){
			c[w2++]='|';
			if(ss[w-1]==1){
				b++;
				w2--;
				int j,x=0;
				for(j=i+1;j<=l;j++){
					if(s[j]=='|'&&x<1) break;
					if(s[j]=='(') x++;
					if(s[j]==')') x--;
					if(x<0) break;
				}
				i=j-1;
			}
		}
		else if(s[i]=='&'){
			c[w2++]='&';
			if(ss[w-1]==0){
				a++;
				w2--;
				int j,x=0;
				for(j=i+1;j<=l;j++){
					if((s[j]=='&'||s[j]=='|')&&x<1) break;
					if(s[j]=='(') x++;
					if(s[j]==')') x--;
					if(x<0) break;
				}
				i=j-1;
			}
		}
		else if(s[i]=='('){
			c[w2++]='(';
		}
		else if(s[i]==')'){
			while(w>1&&(c[w2-1]=='|'||c[w2-1]=='&')){
				if(c[w2-1]=='|'){
					ss[w-2]|=ss[w-1];
					w--;w2--;
				}
				if(c[w2-1]=='&'){
					ss[w-2]&=ss[w-1];
					w--;w2--;
				}
			}
			w2--;
			if(c[w2-1]=='&'){
				while(w>1&&(c[w2-1]=='|'||c[w2-1]=='&')){
					if(c[w2-1]=='|'){
						ss[w-2]|=ss[w-1];
						w--;w2--;
					}
					if(c[w2-1]=='&'){
						ss[w-2]&=ss[w-1];
						w--;w2--;
					}
				}
			}
		}
	}
	while(w>1){
		if(c[w2-1]=='|'){
			ss[w-2]=ss[w-2]|ss[w-1];
			w--;w2--;
		}
		if(c[w2-1]=='&'){
			ss[w-2]=ss[w-2]&ss[w-1];
			w--;w2--;
		}
		if(c[w2-2]=='(') w2-=2;
	}
	cout<<ss[0]<<endl<<a<<" "<<b<<endl;
}
