#include<iostream>
using namespace std;
char s[1000010];
int i=0,anddl=0,ordl=0,ndling=1;
bool opor();
bool opand();
bool getnum();
bool opor(){
	bool res=opand(),flag;
	while(s[i]=='|'){
		flag=0;
		if(res&&ndling) ordl++,ndling=0,flag=1;
		i++,res|=opand();
		if(flag) ndling=1;
	}
	return res;
}
bool opand(){
	bool res=getnum(),flag;
	while(s[i]=='&'){
		flag=0;
		if((!res)&&ndling) anddl++,ndling=0,flag=1;
		i++,res&=getnum();
		if(flag) ndling=1;
	}
	return res;
}
bool getnum(){
	bool res;
	if(s[i]=='(') i++,res=opor(),i++;
	else res=s[i]-'0',i++;
	return res;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",&s);
	printf("%d\n",opor());
	printf("%d %d",anddl,ordl);
	return 0;
}