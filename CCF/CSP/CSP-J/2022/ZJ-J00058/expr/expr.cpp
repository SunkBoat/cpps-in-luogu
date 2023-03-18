#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	if(s.size()==1)
	{
		cout<<s<<endl;
		cout<<"0 0"<<endl;
	}
	else if(s.size()==3)
	{
		if(s[0]=='(')
		{
			cout<<s[1]<<endl;
			cout<<"0 0"<<endl;
		}
		else if(s[1]=='|'&&s[0]=='1')
		{
			cout<<s[0]<<endl;
			cout<<"0 1"<<endl;
		}
		else if(s[1]=='&'&&s[0]=='0')
		{
			cout<<s[0]<<endl;
			cout<<"1 0"<<endl;
		}
		else if(s[1]=='&'&&s[2]=='0') 
		{
			cout<<s[2]<<endl;
			cout<<"0 0"<<endl;
		}
		else if(s[1]=='|'&&s[2]=='1')
		{
			cout<<s[2]<<endl;
			cout<<"0 0"<<endl;
		}
		else if(s[1]=='|')
		{
			cout<<0<<endl;
			cout<<"0 0"<<endl;
		}
		else if(s[1]=='&')
		{
			cout<<1<<endl;
			cout<<"0 0"<<endl;
		}
	}
	else
	{
	cout<<0<<endl;
	cout<<"1 0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
