//csp j/s ++rp;
//ccf qvan1 qian2 zu3 zhi1 
//€€£ ti2 gao1 zu3 tai4 gui4
#include<iostream>
#include<cstring>
using namespace std;
char s[1000002];
int cand,cor;
bool solve(int l,int r){
	if(l==r-1)return s[l]=='1';
p1:
	int c=0,id=-1;
	for(int i=r-1;i>=l;i--){
		if(s[i]=='('){
			c--;
		}
		else if(s[i]==')'){
			c++;
		}
		else if(c==0){
			if(id==-1&&s[i]=='&')id=i;
			else if(s[i]=='|'){
				id=i;
				break;
			}
		}
	}
	if(id==-1){
		l++,r--;
		goto p1;
	}
	bool a=solve(l,id);
	if(s[id]=='&'&&a==0){
		cand++;
		return 0;
	}else if(s[id]=='|'&&a==1){
		cor++;
		return 1;
	}
	else{
		bool b=solve(id+1,r);
		if(s[id]=='|')return a||b;
		else return a&&b;
	}
}
int main(){
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s;
	cout<<solve(0,strlen(s))<<"\n"<<cand<<" "<<cor;
    return 0;
}