#include<bits/stdc++.h>
using namespace std;
int andand=0,oror=0;


bool is_number(char a)
{
	if (a<='9'&&a>='0') return 1;
	return 0;
}
bool is_symbol(char a)
{
	if (a=='|'||a=='&') return 1;
	return 0;
}

bool andd(char a,char b)
{
	if (a=='0')
	{
		andand++;
	}
	return (a-'0')*(b-'0');
}
bool andd(char a,int b)
{
	if (a=='0')
	{
		andand++;
	}
	return (a-'0')*(b);
}
bool andd(int a,char b)
{
	if (a==0)
	{
		andand++;
	}
	return (a)*(b-'0');
}
bool andd(int a,int b)
{
	if (a==0)
	{
		andand++;
	}
	return (a)*(b);
}
bool orr(char a,char b)
{
	if (a=='1')
	{
		oror++;
	}
	return (a-'0')+(b-'0');
}
bool orr(char a,int b)
{
	if (a=='1')
	{
		oror++;
	}
	return (a-'0')+(b);
}
bool orr(int a,int b)
{
	if (a==1)
	{
		oror++;
	}
	return (a)+(b);
}
bool orr(int a,char b)
{
	if (a==1)
	{
		oror++;
	}
	return (a)+(b-'0');
}

int main()
{
	freopen("expr.in","r",stdin);freopen("expr.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
//	cout<<n;
	if (n==1)
	{
		cout<<a<<"\n";
		cout<<"0 0\n";
		return 0;
	}
	if (n<=3)
	{
		if (is_number(a[1]))
		{
			cout<<a[1]<<"\n";
			cout<<andand<<' '<<oror<<"\n";
		}
		else
		{
			if (a[1]=='&')
			{
				cout<<andd(a[0],a[2])<<"\n";
				cout<<andand<<' '<<oror<<"\n";
			}
			else
			{
				cout<<orr(a[0],a[2])<<"\n";
				cout<<andand<<' '<<oror<<"\n";
			}
		}
	}
	if (n==5)
	{
		if (is_symbol(a[1])&&is_symbol(a[3]))
		{
			if (a[1]=='|'&&a[3]=='&')
			{
				cout<<orr(a[0],andd(a[2],a[4]))<<"\n";
				cout<<andand<<' '<<oror<<"\n";
			}
			else
			{
				int q;
				if (a[1]=='|') q=orr(a[0],a[2]);
				else q=andd(a[0],a[2]);
				if (a[3]=='|') q=orr(q,a[4]);
				else q=andd(q,a[4]);
				cout<<q<<"\n";
				cout<<andand<<' '<<oror<<"\n";
			}
		}
		if (a[2]=='('&&a[4]==')')
		{
			int q;
			if (a[1]=='|') q=orr(a[0],a[3]);
			else q=andd(a[0],a[3]);
			cout<<q<<"\n";
			cout<<andand<<' '<<oror<<"\n";
		}
		if (a[0]=='('&&a[2]==')')
		{
			int q;
			if (a[3]=='|') q=orr(a[1],a[4]);
			else q=andd(a[1],a[4]);
			cout<<q<<"\n";
			cout<<andand<<' '<<oror<<"\n";
		}
		if (a[0]=='('&&a[4]==')')
		{
			int q;
			if (a[2]=='|') q=orr(a[1],a[3]);
			else q=andd(a[1],a[3]);
			cout<<q<<"\n";
			cout<<andand<<' '<<oror<<"\n";
		}
		
	}
	return 0;
}

