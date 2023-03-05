#include<bits/stdc++.h>
using namespace std;
string s;
bool ans;
int ans1,ans2;
bool f(char c)
{
	if(c=='0') return 0;
	if(c=='1') return 1;
}
bool read(int l,int r)
{
//	cout<<l+1<<' '<<r+1<<endl;
	if(l>=r) return f(s[l]);
	if(s[l]=='(')
	{
		int i,t=0;
		for(i=l;i<=r;i++)
		{
			if(s[i]=='(') t++;
			if(s[i]==')'&&t==1) break;
			if(s[i]==')') t--;
		}
		bool h=read(l+1,i-1);
		if(i==r||s[i+1]==')') return h;
		if(s[i+1]=='|')
		{
		if(h==true) 
		{
			ans2++;
		}
		bool h1=read(i+2,r);
		return h||h1;
		}
		if(s[i+1]=='&')
		{
		if(h==false) 
		{
			ans1++;
		}
		bool h1=read(i+2,r);
		return h&&h1;
		}
	}
	else
	{
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='|')
		{
			bool x=read(l,i-1);
			if(x==true) 
			{
				ans2++;
			}
			bool y=read(i+1,r);
			return x||y;
		}
	}
	for(int i=l;i<=r;i++)
	{
		if(s[i]=='&')
		{
			bool x=read(l,i-1);
			if(x==false) 
			{
				ans1++;
			}
			bool y=read(i+1,r);
			return x&&y;
		}
	}
	}
} 
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	cout<<read(0,s.size()-1)<<endl;
	cout<<ans1<<' '<<ans2;
	fclose(stdin);
	fclose(stdout);
	return 0;	
}

//( 0 | 1 & 0 | 1 | 1  |  (  1  |  1  )  )  &  (  0  &  1  &  (  1  |  0  )  |  0  |  1  |  0  )  &  0 
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37
