#include<bits/stdc++.h>
using namespace std;
long long now,jsjx,jsjy;
bool aa[100005];
string s;
bool dg(int x)
{
	stack <int> q;
	stack <bool> a;
	for(int i=x;i<s.size();i++)
	{
		if(s[i]=='(')
		{
			bool fttt=dg(i+1);
			if(a.empty()) a.push(fttt);
			else 
			{
				int tt=q.top();
				bool ft=a.top();
				q.pop();
				a.pop();
				if(tt==1) 
					a.push(fttt&ft);
				else
				{
					a.push(fttt);
					q.push(tt);
				}
			}
			i=now;
			continue;
		}
		else if(s[i]!=')')
		{
			if(s[i]=='&') 
			{
				q.push(1);
				if(a.top()==0) jsjx++;
			}
			if(s[i]=='|')
			{
				q.push(2);
				if(a.top()==1) jsjy++;
			}
			if(s[i]=='0'||s[i]=='1')
			{
				bool ft=(s[i]-'0'),ftt;
				if(!q.empty()&&q.top()==1)
				{
					q.pop();
					ftt=a.top();
					a.pop();
					a.push(ftt&ft);
				}
				else 
					a.push(ft);
			}
		}
		else
		{ 
			now=i;
			break;
		} 
	}
	while(!a.empty())
	{
		if(a.top()==true) return true;
		a.pop();
	}
	return false;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	cout<<dg(0)<<endl;
	cout<<jsjx<<' '<<jsjy<<endl;
	return 0;
}
