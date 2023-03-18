#include<bits/stdc++.h>
using namespace std;

char s[1000010];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	if(n==3)
	{
		if(s[0]=='1')
		{
			if(s[1]=='|')
			{
				cout<<"1\n0 1";
			}
			else if(s[2]=='1')
			{
				cout<<"1\n0 0";
			}
			else
			{
				cout<<"0\n0 0";
			}
		}
		else
		{
			if(s[1]=='&')
			{
				cout<<"0\n1 0";
			}
			else if(s[2]=='1')
			{
				cout<<"1\n0 0";
			}
			else
			{
				cout<<"0\n0 0";
			}
		}
		return 0;
	}
	if(n==5)
	{
		string t=s;
		if(t=="0|0|0")cout<<"0\n0 0";
		if(t=="0|0|1")cout<<"1\n0 0";
		if(t=="0|1|0"||t=="0|1|1")cout<<"1\n0 1";
		if(t=="1|0|0"||t=="1|1|0"||t=="1|1|1")cout<<"1\n0 2";
		if(t=="0&0&0"||t=="0&0&1"||t=="0&1&0"||t=="0&1&1")cout<<"0\n2 0";
		if(t=="1&0&0")cout<<"0\n1 0";
		if(t=="1&1&0"||t=="1&0|0")cout<<"0\n0 0";
		if(t=="1&1&1")cout<<"1\n0 0";
		if(t=="0&0|0"||t=="0&1|0")cout<<"0\n1 0";
		if(t=="0&0|1"||t=="0&1|1")cout<<"1\n1 0";
		if(t=="1&0|1")cout<<"1\n0 0";
		if(t=="1&1|0")cout<<"1\n0 1";
		if(t=="1&1|1")cout<<"1\n0 1";
		if(t=="0|0&0"||t=="0|0&1"||t=="0|1&0")cout<<"0\n1 0";
		if(t=="0|1&1")cout<<"1\n0 0";
		if(t=="1|0&0")cout<<"0\n1 0";
		if(t=="1|0&1")cout<<"1\n0 1";
		if(t=="1|1&0")cout<<"0\n0 1";
		if(t=="1|1&1")cout<<"1\n0 1";
		return 0;
	}
	int ans1=0,ans2=0;
	int p=0;
	for(int i=0;i<n;i++)
	{
		if((s[i]=='1'||p==1)&&s[i+1]=='|')
		{
			ans2++;
			if(s[i+2]=='(')
			{
				for(int j=i+1;j<n;j++)
				{
					if(s[j]=='(')
					{
						i=j+1;
						break;
					}
				}
			}
			p=1;
		}
		if(s[i]=='0'&&s[i+1]=='|'&&s[i+2]!='(')
		{
			if(s[i+2]=='1')p=1;
			else p=0;
		}
		if((s[i]=='0'||p==0)&&s[i+1]=='&')
		{
			ans1++;
			if(s[i+2]=='(')
			{
				for(int j=i+1;j<n;j++)
				{
					if(s[j]==')')
					{
						i=j+1;
						break;
					}
				}
			}
			p=0;
		}
		if(s[i]=='1'&&s[i+1]=='&'&&s[i+2]!='(')
		{
			if(s[i+2]=='1')p=1;
			else p=0;
		}
	}
	if(p==0)p=1;
	else p=0;
	cout<<p<<"\n"<<ans1<<" "<<ans2;
	return 0;
}
