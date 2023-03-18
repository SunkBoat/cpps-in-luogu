#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> mat;
int ans=0;
int sev=0,ku=0;
int w,u;
void val(int x)
{
	int f=-1;
	int suf=0;
	int uio=0;
	for(int i=x+1;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			uio=0;
			val(i);
			i=w;
			if(suf==1)
			{
				f&=u;
			}
			else if(suf==2)
			{
				f|=u;
			}
			suf=0;
		}
		if(s[i]==')')
		{
			w=i;
			u=f;
			return ;
		}
		if(s[i]>='0'&&s[i]<='1'&&f==-1) f=(s[i]-'0');
		if(s[i]>='0'&&s[i]<='1')
		{
			uio=0;
			if(suf==1)
			{
				f&=(s[i]-'0');
			}
			else if(suf==2)
			{
				f|=(s[i]-'0');
			}
			suf=0;
		}
		else if(s[i]=='&') suf=1;
		else if(s[i]=='|') suf=2;
		if(s[i]=='0'&&s[i+1]=='&'&&uio==0) sev++,uio=1;
		if(s[i]=='1'&&s[i+1]=='|'&&uio==0) ku++,uio=1;
	}
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	int len=s.size();
	int pre=0;
	int uio=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			uio=0;
			if(pre==1)
			{
				int t=mat.top();
				mat.pop();
				mat.push(t&(s[i]-'0'));
			}
			else if(pre==2)
			{
				int t=mat.top();
				mat.pop();
				mat.push(t|(s[i]-'0'));
			}
			else mat.push(s[i]-'0');
			pre=0;
		}
		else if(s[i]=='&') pre=1;
		else if(s[i]=='|') pre=2;
		if(s[i]=='0'&&s[i+1]=='&'&&uio==0) sev++,uio=1;
		if(s[i]=='1'&&s[i+1]=='|'&&uio==0) ku++,uio=1;
		if(s[i]=='(')
		{
			uio=0;
			val(i);
			i=w;
			if(pre==1)
			{
				int t=mat.top();
				mat.pop();
				mat.push(t&u);
			}
			else if(pre==2)
			{
				int t=mat.top();
				mat.pop();
				mat.push(t|u);
			}
			pre=0;
		}
	}
	cout<<mat.top()<<"\n";
//	if(len<=5){
		cout<<sev<<" "<<ku;
		return 0;
//	}
}
