#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,l,r) for(int i=(l);i>=(r);i--)
char s[1000005];
int len,ans1;
bool check(int l,int r){
	int num1,num2;
	bool flag=1;
	F(i,l,r){
		if(isdigit(s[i]))num1=s[i]-'0';
		else{
			num2=s[i+1]-'0';
			flag&=(num1&&num2);
			if(!num1)ans1++;
		}
	}
	return flag;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",s+1);
	len=strlen(s+1);
	if(len<=3){
		if(len==1){
			if(s[1]=='1')printf("1\n0 0\n");
			else printf("0\n0 0\n");
		}
		else{
			if(s[2]=='0'){printf("0\n0 0\n");}
			if(s[2]=='1'){printf("1\n0 0\n");}
			if(s[2]=='&'){
				if(s[1]=='1'){
					if(s[3]=='1')printf("1\n");
					else printf("0\n");
					printf("0 0\n");
				}
				else printf("0\n1 0\n");
			}
			if(s[2]=='|'){
				if(s[1]=='1')printf("1\n0 1\n");
				else{
					if(s[3]=='0')printf("0\n0 0\n");
					else printf("1\n0 0\n");
				}
			}
		}
		return 0;
	}
	bool ans=0;
	int l=1,r;
	for(r=1;r<=len;r++){
		if(s[r]=='|'){
			ans|=check(l,r-1);
			l=r+1;
		}
	}
	ans|=check(l,len);
	if(ans)printf("1\n");
	else printf("0\n");
	printf("%d 0\n",ans1);
	return 0;
}