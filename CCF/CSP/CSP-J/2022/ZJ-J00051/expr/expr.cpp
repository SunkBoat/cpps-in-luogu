#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],sa,sb,ta,tb,len;
string s;
int tg(int x)
{
	if (s[x]=='1'||s[x]=='0') return x;
	int a=1,b=0,k=x;
	while (a!=b)
	{
		k++;
		if (s[k]=='(') a++;
		if (s[k]==')') b++;
	}
	return k;
}
int tg1(int x)
{
	int a=0,b=0,k=x;
	while ((a!=b||s[k]=='0'||s[k]=='1'||s[k]=='&'||s[k]=='(')&&k<len)
	{
		if (s[k]=='(') a++;
		if (s[k]==')') b++;
		k++;
	}
	return k-1;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	len=s.size();
	for (int i=0;i<len;i++)
	{
		if (s[i]=='0') a[++ta]=0;
		else 	
		if (s[i]=='1') a[++ta]=1;
		else 	
		if (s[i]=='&')
		{
			if (a[ta]==0) sa++,i=tg(i+1);
			else 
			{
				while (b[tb]==1)
				{
					a[ta-1]=a[ta]&a[ta-1];
					ta--;
					tb--;
				}
				b[++tb]=1;
			}
		}
		else 
		if (s[i]=='|') 
		{
			if (a[ta]==1) sb++,i=tg1(i+1);
			else 
			{
				while (b[tb]==1||b[tb]==2)
				{
					if (b[tb]==1) a[ta-1]=a[ta]&a[ta-1];
					else a[ta-1]=a[ta]|a[ta-1];
					ta--;
					tb--;
				}
				b[++tb]=2;
			}
		}
		else 
		if (s[i]=='(') 
			b[++tb]=3;
		else
		if (s[i]==')') 
		{
			while (b[tb]==1||b[tb]==2)
			{
				if (b[tb]==1) a[ta-1]=a[ta]&a[ta-1];
				else a[ta-1]=a[ta]|a[ta-1];
				ta--;
				tb--;
			}
			tb--;
		}
	}
	printf("%d\n%d %d",a[ta],sa,sb);
	return 0;
}
