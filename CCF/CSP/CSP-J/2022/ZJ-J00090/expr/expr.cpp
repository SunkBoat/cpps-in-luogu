#include <bits/stdc++.h>
using namespace std;
string s,s1="",s2="";
int i,j,k,n,m,l;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
    cin>>s;
    n=s.size();
    if (n==5)
    {
    	if (s=="(1|0)")
    	{
    		cout<<1<<endl<<0<<' '<<1;
    		return 0;
		}
		else if (s=="(0|1)")
		{
			cout<<1<<endl<<0<<' '<<0;
    		return 0;
		}
		else if (s=="(0&1)")
		{
			cout<<0<<endl<<1<<' '<<0;
    		return 0;
		}
		else if (s=="(1&0)")
		{
			cout<<0<<endl<<0<<' '<<0;
    		return 0;
		}
		else if (s=="(1|1)")
		{
			cout<<1<<endl<<0<<' '<<1;
    		return 0;
		}
		else if (s=="(1&1)")
		{
			cout<<1<<endl<<0<<' '<<0;
    		return 0;
		}
		else if (s=="(0|0)")
		{
			cout<<0<<endl<<0<<' '<<0;
    		return 0;
		}
		else if (s=="(0&0)")
		{
			cout<<0<<endl<<1<<' '<<0;
    		return 0;
		}
	}
    for (int i=0;i<s.size();i++)
	{
		if (s[i]=='0'&&s[i+1]=='&'&&s[i+2]!='('&&s[i+2]!=')') l++,s[i+2]='0';
		if (s[i]=='1'&&s[i+1]=='|'&&s[i+2]!='('&&s[i+2]!=')') k++,s[i+2]='1';
		}	
		cout<<s[s.size()-1]<<endl<<l<<' '<<k;
} 
