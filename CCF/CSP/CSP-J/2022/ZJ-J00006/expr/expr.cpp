#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005;
string s;
int stk[N],top;
int pp[N];
int ls[N],rs[N],id[N],ucnt;
int n;
int build(int l,int r)
{
	if(l>r)return 0;
	if(pp[l]==r&&s[l]=='(')
	{
		return build(l+1,r-1);
	}
	int u=++ucnt;
	if(l==r)
	{
		id[u]=l;
		return u;
	}
	int h=-1;
	for(int i=r;i>=l;i--)
	{
		if(pp[i])
		{
			i=pp[i];
			continue;
		}
		if(s[i]=='|')
		{
			id[u]=i;
			ls[u]=build(l,i-1);
			rs[u]=build(i+1,r);
			return u;
		}
		if(s[i]=='&'&&h==-1)
		{
			h=i;
		}
	}
	if(h!=-1)
	{
		id[u]=h;
		ls[u]=build(l,h-1);
		rs[u]=build(h+1,r);
		return u;
	}
}
int s1,s2;
bool dfs(int u)
{
	int k=id[u];
	if(s[k]=='0')return 0;
	if(s[k]=='1')return 1;
	if(s[k]=='&')
	{
		bool g=dfs(ls[u]);
		if(g==0)
		{
			s1++;
			return 0;
		}
		return g&&dfs(rs[u]);
	}
	if(s[k]=='|')
	{
		bool g=dfs(ls[u]);
		if(g==1)
		{
			s2++;
			return 1;
		}
		return g||dfs(rs[u]);
	}
}
bool p1=1,p2=1,p3=1;
int e0,e1;
int t0=-1,t1=-1,tn=-1,so=-1,sa=-1;
const int FF=1e6+5;
int oo[FF],aa[FF];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		oo[i]=oo[i-1];
		aa[i]=aa[i-1];
		if(s[i]=='0')
		{
			e0++;
			tn=t0=i;
		}
		else if(s[i]=='1')
		{
			e1++;
			tn=t1=i;
		}
		else if(s[i]=='&')
		{
			if(!sa&&s[i-1]=='0')sa=i;
			aa[i]++;
			p1=0;
		}
		else if(s[i]=='|')
		{
			if(!so&&s[i-1]=='1')so=i;
			oo[i]++;
			p2=0;
		}
		else if(s[i]=='(')
		{
			p3=0;
			stk[++top]=i;
		}
		else if(s[i]==')')
		{
			pp[i]=stk[top--];
			pp[pp[i]]=i;
		}
	}
	if(n>2000)
	{
		if(p1)
		{
			if(e1)
			{
				cout<<1<<'\n';
				cout<<0<<' ';
				if(e1>1||e1==1&&tn!=t1)
				{
					cout<<oo[n]-oo[so-1];
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<0<<'\n';
				cout<<0<<' '<<0;
			}
		}
		if(p2)
		{
			if(e0)
			{
				cout<<0<<'\n';
				if(e0>0||e0==1&&tn!=t0)
				{
					cout<<aa[n]-aa[sa-1];
				}
				else
				{
					cout<<0;
				}
				cout<<0<<' ';
			}
			else
			{
				cout<<1<<'\n';
				cout<<0<<' '<<0;
			}
		}
		return 0;
	}
	int ro=build(1,n);
	cout<<dfs(ro)<<'\n';
	cout<<s1<<' '<<s2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
