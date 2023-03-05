#include <bits/stdc++.h>
using namespace std;

string s;
bool a[1000005]={0};
long long k=0,ans=0;
bool f(bool x,bool y)
{
	if(x==0)
	{
		ans++; 
	}
	return (x&&y);
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='('&&s[i+2]==')')
		{
			i++;
			a[++k]=(s[i]-'0');
			i++;
		}
		if(s[i]=='0'||s[i]=='1')
		{
			a[++k]=(s[i]-'0');
		}
		else if(s[i]=='&')
		{
			i++;
			a[k]=f(a[k],(s[i]-'0'));
		}
	}
	long long t=0;
	for(int i=1;i<=k;i++)
	{
		if(a[i]==1)
		{
			t=i;
			break;
		}
	}
	if(t==0)
	{
		printf("0\n");
		printf("%lld 0\n",ans);
	}
	else
	{
		printf("1\n");
		printf("%lld %lld\n",ans,k-t);
	}
	return 0;
}
