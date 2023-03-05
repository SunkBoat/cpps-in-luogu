#include <bits/stdc++.h>
using namespace std;
int SCand=0,SCor=0;
int br[2022930];//Í³¼ÆÀ¨ºÅ 

int solve(string s)
{
	stack<int> st;
	int len=s.length();
	int l=0;
	if (s[0]=='(')
	{
		int tmp=1;
		for (int i=1;i<len;i++)
		{
			if (s[i]=='(') tmp++;
			else if (s[i]==')') tmp--;
			if (tmp==0)
			{
				l=i+1;
				break;
			}
		}
		st.push(solve(s.substr(1,l-2)));
	}
	for (int i=l;i<len;i++)
	{
		if (s[i]=='&')
		{
			if (st.top()==0)
			{
				SCand++;
				if (s[i+1]=='0'||s[i+1]=='1')
				{
					i=i+2;
				}
				else if (s[i+1]=='(')
				{
					int tmp=1;
					for (int j=i+2;j<len;j++)
					{
						if (s[j]=='(') tmp++;
						else if (s[j]==')') tmp--;
						if (tmp==0)
						{
							l=j+1;
							break;
						}
					}
					int x=solve(s.substr(i+2,l-i-3));
					i=l;
				}
			}
			else
			{
				if (s[i+1]=='0')
				{
					st.pop();
					st.push(0);
					i=i+2;
				}
				else if (s[i+1]=='(')
				{
					int tmp=1;
					for (int j=i+2;j<len;j++)
					{
						if (s[j]=='(') tmp++;
						else if (s[j]==')') tmp--;
						if (tmp==0)
						{
							l=j+1;
							break;
						}
					}
					int x=solve(s.substr(i+2,l-i-3));
					if (x==0)
					{
						st.pop();
						st.push(0);
					}
					i=l;
				}
			}
		}
		else if (s[i]=='|')
		{
			int x;
			if (s[i+1]=='(')
			{
				int tmp=1;
				for (int j=i+2;j<len;j++)
				{
					if (s[j]=='(') tmp++;
					else if (s[j]==')') tmp--;
					if (tmp==0)
					{
						l=j+1;
						break;
					}
				}
				int x=solve(s.substr(i+2,l-i-3));
				if (x==0)
				{
					st.pop();
					st.push(0);
				}
				i=l;
			}
			else
			{
				x=s[i+1]-'0';
				i=i+2;
			}
			st.push(x);
		}
		else if (s[i]=='1'||s[i]=='0') st.push(s[i]-'0');
	}
	
	stack<int> st2;
	while(!st.empty())
	{
		int x=st.top();
		st2.push(x);
		st.pop();
	}
	//cout << SCor << endl << endl;
	while(!st2.empty())
	{
		//cout << st2.top() << endl;
		if (st2.top()==1)
		{
			SCor++;
			return 1;
		}
		st2.pop();
	}
	return 0;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	string s;
	cin >> s;
	int len=s.length();
	int tmp=0;
	if (s[0]=='(') br[0]=1,tmp=1;
	bool flag=false;

	if (flag==false)
	{
		cout << solve(s) << endl;
		cout << SCand << " " << SCor << endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
