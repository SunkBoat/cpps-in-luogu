#include<bits/stdc++.h>
using namespace std;
string s,st;
long long a[1000010],topa,topb,s1,s2;
char b[1000010],ch;
bool p,f;
int main()
{
	freopen("expr.in","r",stdin);
	frropen("expr.out","w",stdout);
	cin>>s;
	st=s;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]=='|')
		{
			if(st[i+1]=='('||st[i+2]=='&')
			{
				s2++;
				st[i]='z';
			}
			else
			{
				if(i>=2&&st[i-2]=='&')
				{
					s2++;
				}
			}
		}
		if(st[i]=='&')
		{
			if(st[i+1]=='(')
			{
				s1++;
				st[i]='z';
			}
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'||s[i]=='1')
		{
			a[++topa]=s[i]-48;
		}
		else
		{
			if(s[i]==')')
			{
				p=false;
				while(b[topb]!='(')
				{
					f=false;
					
					if(b[topb]=='&')
					{
						ch='&';
						topa--;
						if(a[topa]==1&&a[topa+1]==1)
						{
							a[topa]=1;
						}
						else
						{
							a[topa]=0;
						}
					}
					else
					{
						ch='|';
						topa--;
						a[topa]=max(a[topa],a[topa+1]);
					}
					topb--;
				}
				p=false;
			}
			else if(s[i]=='|')
			{
				while(b[topb]!='('&&topb>0)
				{
					topa--;
					if(b[topb]=='&')
					{
						
							ch='&';
						
						if(a[topa]==1&&a[topa+1]==1)
						{
							a[topa]=1;
						}
						else
						{
							a[topa]=0;
						}
					}
					else
					{
					
						ch='|';
						a[topa]=max(a[topa],a[topa+1]);
					}
					topb--;
				}
				b[++topb]='|';
			}
			else if(s[i]=='&')
			{
				while(b[topb]=='&')
				{
					topa--;
					
						ch='&';
					
					if(a[topa]==1&&a[topa+1]==1)
					{
						a[topa]=1;
					}
					else
					{
						a[topa]=0;
					}
					topb--;
				}
				b[++topb]='&';
			}
			else
			{
				b[++topb]='(';
				f=true;
			}
		}
	}
	cout<<a[topa]<<endl;
	cout<<s1<<" "<<s2;
	return 0;
}
