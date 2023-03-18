#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
string s;
int n,a[1000005];
stack <int> st1,st2,st3;
int calc1(int x,int y)
{
	if(x==1&&y==1)
		return 1;
	return 0;	
}
int calc2(int x,int y)
{
	if(x==0&&y==0)
		return 0;
	return 1;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	n=s.size();
	if(n==1)
	{
		cout<<(s[0]-'0')<<endl<<"0 0";
		return 0;
	}
	if(n==3)
	{
		int ans;
		if(s[1]=='&')
		{
			ans=calc1(s[0]-'0',s[2]-'0');
			printf("%d\n",ans);
			if(s[0]=='0')
				printf("1 0");
			else
				printf("0 0");		
		}
		if(s[1]=='|')
		{
			ans=calc2(s[0]-'0',s[2]-'0');
			printf("%d\n",ans);
			if(s[0]=='0')
				printf("0 1");
			else
				printf("0 0");	
		}
	}
	if(n==5)
	{
		if(s[0]=='('||s[1]=='('||s[2]=='('||s[3]=='(')
		{
			string ss="";
			for(int i=0;i<5;i++)
			{
				if(s[i]!='('&&s[i]!=')')
					ss+=s[i];
			}
			int ans;
			if(ss[1]=='&')
			{
				ans=calc1(ss[0]-'0',ss[2]-'0');
				printf("%d\n",ans);
				if(ss[0]=='0')
					printf("1 0");
				else
					printf("0 0");		
			}
			if(ss[1]=='|')
			{
				ans=calc2(ss[0]-'0',ss[2]-'0');
				printf("%d\n",ans);
				if(ss[0]=='0')
					printf("0 1");
				else
					printf("0 0");	
			}
		}
	}
	return 0;
}
