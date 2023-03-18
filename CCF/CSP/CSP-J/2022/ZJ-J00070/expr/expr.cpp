#include<bits/stdc++.h>
using namespace std;
int aa=1;
int x,y;
char p[1000005];
bool f[1000005];
string s;
struct node{
	int st;
	int ed;
	int sp;
}b[1000005];
bool js(int start,int end){
	for(int i=start;i<end;i++){
		if(p[i]==')'){
			f[b[i].st]=f[b[i].ed]=js(b[i].st,b[i].ed-1);
			i=b[i].ed;
		}
		if(p[i]=='&'){
			if(f[i-1]==0){
				x++;
			}
			f[b[i-1].st]=f[b[i+1].ed]=js(b[i-1].st,b[i-1].ed)||js(b[i+1].st,b[i+1].ed);
			i=b[i+1].ed+1;
		}
		if(p[i]=='|'){
			if(f[i-1]==1){
				y++;
			}
			f[b[i-1].st]=f[b[i+1].ed]=js(b[i-1].st,b[i-1].ed)||js(b[i+1].st,b[i+1].ed);
			i=b[i+1].ed+1;
		}
	}
	return f[end];
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	int ss=s.length();
	for(int i=0;i<ss;i++){
		if(s[i]=='1'){
			f[i]=1;
			b[i].st=b[i].ed=i;
		}
		if(s[i]=='0'){
			f[i]=0;
			b[i].st=b[i].ed=i;
		}
		p[i]=s[i];
		if(s[i]=='('){
			b[i].st=i;
			b[i].sp=aa++;
		}
		if(s[i]==')'){
			int j=i-1;
			for(;j>=0;j--){
				if(b[j].sp==aa){
					break;
				}
			}
			b[j].ed=i;
			aa--;
		}
	}
	int m=js(0,ss-1);
	//for(int i=0;i<ss;i++){
	//	cout<<b[i].st<<" "<<b[i].ed<<endl<<f[i]<<endl;
	//}
	cout<<m<<endl;
	cout<<x<<" "<<y;
	return 0;
}
