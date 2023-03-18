#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char s[1000009];
	int len=0;
	while(cin>>s[++len]);
	if(len==1)
	{
		if(s[1]=='1')
			printf("1\n0 0");
		if(s[1]=='0')
			printf("0\n0 0");
		return 0;
	}
	if(len==3)
	{
		if(s[1]=='('&&s[3]==')')
		{
			if(s[2]=='1')
				printf("1\n0 0");
			if(s[2]=='0')
				printf("0\n0 0");
		}
		if(s[2]=='&')
		{
			if(s[1]=='0')
				printf("0\n1 0");
			else if(s[3]=='0')
				printf("0\n0 0");
			else if(s[3]=='1')
				printf("1\n0 0");
		}
		if(s[2]=='|')
		{
			if(s[1]=='1')
				printf("1\n0 1");
			else if(s[3]=='1')
				printf("1\n0 0");
			else if(s[3]=='0')
				printf("0\n0 0");
		}
		return 0;
	}
	bool flag=0;
	for(int i=1;i<=len;i++)
	{
		if(s[i]=='(')
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		char t[1000009];
		int k=1;
		int cnt1=0,cnt2=0;
		for(int i=2;i<=len;i+=2)
		{
			t[1]=s[1];
			if(s[i]=='|')
				t[++k]=s[i+1];
			if(s[i]=='&')
			{
				if(t[k]=='0')
					cnt1++;
				if(t[k]=='1'&&s[i+1]=='1')
					t[k]='1';
				else
					t[k]='0';
			}
		}
		char pre=t[1];
		for(int i=2;i<=k;i++)
		{
			if(pre=='1')
				cnt2++;
			if(pre=='0'&&t[i]=='0')
				pre='0';
			else
				pre='1';
		}
		printf("%c\n%d %d",pre,cnt1,cnt2);
		return 0;
	}
	return 0;
}
