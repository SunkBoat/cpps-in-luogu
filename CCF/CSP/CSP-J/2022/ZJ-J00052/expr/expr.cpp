#include<iostream>
using namespace std;
string s;
bool bol;
int zero,one;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	if(s[0]=='0') bol=0;
	if(s[0]=='1') bol=1;
	if(s[1]=='0') bol=0;
	if(s[1]=='1') bol=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'&&s[i+1]=='&'||s[i]=='&'&&s[i+1]=='0')
		{
			if(s[i+2]=='(')
			{
				for(int j=i+3;j<s.size();j++)
				{
					if(s[j]==')')
					{
						i=j;
						break;
					}
				}
			}
			else i+=1;
			bol=0;
			zero++;
		}
		if(s[i]=='1'&&s[i+1]=='|'||s[i]=='|'&&s[i+1]=='1')
		{
			if(s[i+2]=='(')
			{
				for(int j=i+3;j<s.size();j++)
				{
					if(s[j]==')')
					{
						i=j;
						break;
					}
				}
			}
			else
			{
				for(int j=i+2;j<s.size();j++)
				{
					if(s[j+1]=='|')
					{
						i=j;
						break;
					}
				}
			}
			bol=1;
			one++;
		}
		if(s[i]=='|') bol=0;
		if(s[i]=='&') bol=1;
	}
	cout<<bol<<endl<<zero<<' '<<one;
	return 0;
}
