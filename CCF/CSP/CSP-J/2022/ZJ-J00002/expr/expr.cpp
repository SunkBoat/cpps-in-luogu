#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

char ng[N];

struct I_stack{
	int v[N];
	int _top;
	
	void init()
	{
		_top=0;
	}
	
	int top()
	{
		return v[_top];
	}
	
	void push(int x)
	{
		v[++_top]=x;
	}
	
	void pop()
	{
		_top--;
	}
}num;

struct C_stack{
	char v[N];
	int _top;
	
	void init()
	{
		_top=0;
	}
	
	char top()
	{
		return v[_top];
	}
	
	void push(int x)
	{
		v[++_top]=x;
	}
	
	void pop()
	{
		_top--;
	}
}op;

bool calc(char c)
{
	char x=op.top();
	if(c==')')return 1;
	if(c=='|' || c=='&')
	{
		if(x=='|' && x=='&')return 1;
		if(x=='(')return 0;
	}
	if(c=='(')return 2;
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",ng+1);
	int len=strlen(ng+1);
	ng[0]='(';
	ng[++len]=')';
	int ans1=0,ans2=0;
	for(int i=0;i<=len;i++)
	{
		if(ng[i]=='0' || ng[i]=='1')num.push(ng[i]-'0');
		else
		{
			bool xx=calc(ng[i]);
			if(xx==1)
			{
				int y=num.top();
				num.pop();
				int x=num.top();
				num.pop();
				char c=op.top();
				op.pop();
				cout<<x<<c<<y<<endl;
				if(c=='|')
				{
					if(x==1)ans2++;
					if(y==1 || x==1)num.push(1);
					else num.push(0);
				}
				if(c=='&')
				{
					if(x==0)ans1++;
					if(y==1 && x==1)num.push(1);
					else num.push(0);
				}
			}
			cout<<num.top()<<endl;
			if(ng[i]==')')op.pop();
			if(ng[i]!=')')op.push(ng[i]);
		}
		if(xx==2)
		{
			char c=op.top();
			int x=num.v[num._top-1];
			if(c=='&' && x==0)
			{
				int j=i;
				while(ng[j]!=')')
				{
					ng[j]=-1;
					j++;
				}
				op.pop();
				num.push(0);
			}
			if(c=='|' && x==1)
			{
				int j=i;
				while(ng[j]!=')')
				{
					ng[j]=-1;
					j++;
				}
				op.pop();
				num.push(1);
			}
		}
	}
	cout<<num.top()<<"\n"<<ans1<<" "<<ans2;
}

/*
(0|1&0|1|1|(1|1))&(0&1&(1|0)|0|1|0)&0
*/
