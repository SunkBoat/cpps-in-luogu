#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int a,o,l;
void del(int i,int n){
	i++;
	s[i]='d';
	for(int sum=0;i<l;){
		if(s[i]=='&') if(n==0&&sum==0){
			for(int j=0;j<l;j++) cout<<s[j];
			printf("\n");
			return;
		}
		if(s[i]=='|') if(sum==0){
			for(int j=0;j<l;j++) cout<<s[j];printf("\n");return; 
		}
		if(s[i]=='(') sum++;
		else if(s[i]==')') sum--;
		s[i]='\0';i++;
	}
}
bool find(int i){
	bool v,flag;
	if(s[i+1]=='('){
		for(int j=i+2;s[j]!=')'&&j<l;j++){
			if(s[j]=='0'||s[j]=='1') v=s[j]-'0';
			if(s[j]=='&') v&=find(j);
			if(s[j]=='|') v|=find(j);
	}}
	else v=s[i+1]-'0';
	return v;
}
signed main(void){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	l=strlen(s);
	bool q;
	for(int i=0;i<l-1;i++){
		if(s[i]=='0'||s[i]=='1') q=s[i]-'0';
		if(!q&&s[i+1]=='&'){a++;
			del(i,0);i=0;
		}
		if(q&&s[i+1]=='|'){o++;
			del(i,1);i=-1;
		}
	}
	bool flag,b;
	for(int i=0;i<l;i++){
		if(!flag&&s[i]>='0'&&s[i]<='1') b=s[i]-'0',flag=1;
		if(s[i]=='&') b&=find(i);
		if(s[i]=='|') b|=find(i);
	}
	cout<<b;
	printf("\n%d %d",a,o);
	return 0;
}