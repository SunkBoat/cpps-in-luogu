#include<bits/stdc++.h>
using namespace std;
const int MAX=1e6+5;
char c[MAX],stackf[MAX];string s;int len,totf,tot,stackk[MAX],LG,ans1,ans2,TOTF;bool b[MAX],bb;
int main(){
freopen("expr.in","r",stdin);freopen("expr.out","w",stdout);
	scanf("%s",c);s=c;len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]=='(')stackf[++totf]='(';
		else if(s[i]==')'){
			LG=stackk[tot--];
			TOTF=totf;
			while(stackf[totf--]=='|'){
				LG|=stackk[tot--];
				if(b[totf+1])bb=0,b[totf+1]=0,ans2+=TOTF-totf;
			}
			if(tot==0||stackf[totf]=='(')stackk[++tot]=LG;
			else{
				if(stackf[totf]=='&'){
					if(b[totf])bb=0,b[totf]=0;
					stackk[tot]&=LG,totf--;
				}
				else stackk[++tot]=LG;
			}
		}
		else if(s[i]=='&'){
			if(stackk[tot]==0&&!bb)bb=1,ans1++,b[totf+1]=1;
			stackf[++totf]='&';
		}
		else if(s[i]=='|'){
			if(stackk[tot]==1&&!bb)bb=1,b[totf+1]=1;
			stackf[++totf]='|';
		}
		else{
			if(tot==0||stackf[totf]=='(')stackk[++tot]=s[i]-48;
			else{
				if(stackf[totf]=='&'){
					if(b[totf])bb=0,b[totf]=0;
					stackk[tot]&=(s[i]-48),totf--;
				}
				else stackk[++tot]=(s[i]-48);
			}
		}
	}
	LG=stackk[1];
	for(int i=2;i<=tot;i++)
		if(stackk[i]){LG=1;ans2+=tot-i;break;}
	printf("%d\n%d %d",LG,ans1,ans2);return 0;
}
