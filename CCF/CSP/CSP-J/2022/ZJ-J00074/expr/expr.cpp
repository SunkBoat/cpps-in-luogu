#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

stack<int> s1,s2;
char c[N];
int len,l[N],r[N],num[N],p[N],ans1,ans2;

void add()
{
	int tp=s2.top();s2.pop();
	int R=s1.top();s1.pop();
	int L=s1.top();s1.pop();
	l[tp]=L;r[tp]=R;
	s1.push(tp);
}
int dfs(int u)
{
	if(p[u]) return num[u];
	int L=dfs(l[u]),R;
	if(c[u]=='&'&&L==0)
	{
		ans1++;return 0;
	}else if(c[u]=='&') R=dfs(r[u]);
	if(c[u]=='|'&&L==1)
	{
		ans2++;return 1;
	}else if(c[u]=='|') R=dfs(r[u]);
	if(c[u]=='&') return L&R;
	else return L|R;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>c+1;len=strlen(c+1);
	for(int i=1;i<=len-i+1;i++)
		swap(c[i],c[len-i+1]);
	for(int i=1;i<=len;i++)
		if(c[i]=='(') c[i]=')';
		else if(c[i]==')') c[i]='(';
	for(int i=1;i<=len;i++)
	{
		if(c[i]=='0'||c[i]=='1')
		{
			s1.push(i);
			num[i]=c[i]-'0';
			p[i]=1;
		}else if(c[i]=='&')
		{
			s2.push(i);
		}else if(c[i]=='|')
		{
			while(!s2.empty()&&c[s2.top()]=='&')
			{
				add();
			}
			s2.push(i);
		}else if(c[i]=='(')
		{
			s2.push(i);
		}else
		{
			while(c[s2.top()]!='(')
			{
				add();
			}
			s2.pop();
		}
	}
	while(!s2.empty())
	{	
		add();
	}
	for(int i=1;i<=len;i++)
		swap(l[i],r[i]);
	int root=s1.top();
	cout<<dfs(root)<<endl;
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
/*
0&(1|0)|(1|1|1&0)

*/