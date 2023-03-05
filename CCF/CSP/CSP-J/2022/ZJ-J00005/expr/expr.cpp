#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int N=2002000;
char s[N];
int n;
int cnt_0,cnt_1;//&型短路 |型短路
int v[N];
void in() {
	string SSS;
	cin>>SSS;
	n=SSS.size();
	for(int i=1; i<=n; i++) s[i]=SSS[i-1];
	s[n+1]='?';
	s[n+2]='?';
	for(int i=1; i<=n+2; i++) v[i]=i;
}
void kill_(){
	for(int i=1; i<=n; i++) {
		int a1=v[i-1],a2=v[i],a3=v[i+1];
		if(s[a2]=='&') {
			if(s[a1]=='0'&&s[a3]=='0') {
				v[a1]=a1,v[a2]=a1,v[a3]=a1;
				s[a1]='0';
				cnt_0++;
			} else if(s[a1]=='0'&&s[a3]=='1') {
				v[a1]=a1,v[a2]=a1,v[a3]=a1;
				s[a1]='0';
				cnt_0++;
			} else if(s[a1]=='1'&&s[a3]=='0') {
				v[a1]=a1,v[a2]=a1,v[a3]=a1;
				s[a1]='0';
			} else if(s[a1]=='1'&&s[a3]=='1') {
				v[a1]=a1,v[a2]=a1,v[a3]=a1;
				s[a1]='1';
			}
		}
	}
	for(int i=1; i<=n; i++) {
		int a1=v[i-1],a2=v[i],a3=v[i+1];
		if(s[a2]=='0'||s[a2]=='1'){
			if(s[a1]=='('&&s[a3]==')'){
				v[a1]=v[a3]=a2;
			}
		}
	}
}
bool g(int l,int r){
	bool flag=false;
	for(int now=l;now<=r;now++){
		int i=v[now];
		if(flag==true&&(s[i]=='0'||s[i]=='1')) cnt_1++;
		else if(s[i]=='1') flag=true;
		v[i]=r-1;
	}
	s[r-1]=(char)((int)(flag=='1')+'0');
	return flag;
}
signed main() {
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	in();
	kill_();
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[v[i]]=='(') cnt++;
	}
	while(cnt>0){
		int now=0;
		for(int i=1;i<=n;i++){
			if(s[i]!='('&&s[i]!=')'){
				int j=i-1;
				for(;j>=1;j--){
					if(s[j]=='('||s[j]==')') break;
				}
				int k=i+1;
				for(;k<=n;k++){
					if(s[k]=='('||s[k]==')') break;
				}
				s[k-1]=(char)((int)(g(j+1,k-1)==true)+'0');
				v[j]=k-1,v[k]=k-1;
				cnt--;
				i=k+1;
			}
		}
		kill_();
	}
	printf("%d\n",g(1,n));
	printf("%d %d",cnt_0,cnt_1);
}
