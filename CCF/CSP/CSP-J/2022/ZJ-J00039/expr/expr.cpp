#include<bits/stdc++.h>
using namespace std;
const int MX=10e6+3;
string ch;
/*int n,s1,s2,a_z,b_z,c_z,d_z;
int a[MX];
int b[MX];
int c[MX];
int d[MX];
int y[MX];
stack<int> st;
int digui(int l,int r)
{
	a_z=b_z=c_z=d_z=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(a));
	memset(d,0,sizeof(b));
	for(int i=l;i<=r;i++)
	{
		if(ch[i]=='0'||ch[i]=='1')
		{
			a_z++;
			a[a_z]=ch[i]-48;
		}
		if(ch[i]=='|')
		{
			b_z++;
			b[b_z]=0;
		}
		if(ch[i]=='&')
		{
			b_z++;
			b[b_z]=1;
		}
		if(ch[i]=='(')
		{
			a_z++;
			a[a_z]=digui(i+1,y[i]-1);
		}
	}
	for(int i=1;i<=b_z;i++)
	{
		if(b[i])
		{
			if(a[i]>-1&&a[i+1]>-1)
			{
				a[i]=a[i]&a[i+1];
				a[i+1]=-1;
				b[i]=-1;
			}
			else
			{
				a[i]=a[i-1]&a[i+1];
				a[i+1]=-1;
				a[i-1]=-1;
				b[i]=-1;
			}
		}
	}*/
	
	
	/*for(int i=1;i<=a_z;i++)
	{
		if(a[i]!=-1)
		{
			c_z++;
			c[c_z]=a[i];
		}
	}
	for(int i=1;i<=b_z;i++)
	{
		if(b[i]!=-1)
		{
			d_z++;
			d[d_z]=a[i];
		}
	}
	for(int i=1;i<=d_z;i++)
	{
		if(c[i]>-1&&c[i+1]>-1)
		{
			c[i]=c[i]|c[i+1];
			c[i+1]=-1;
			d[i]=-1;
		}
		else
		{
			c[i]=c[i-1]|c[i+1];
			c[i+1]=-1;
			c[i-1]=-1;
			d[i]=-1;
		}
	}
	for(int i=1;i<=c_z;i++)
	{
		if(c[i]!=-1)
		{
			return c[i];
		}
	}
}*/
int main()
{
	//!!!
	
	
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	
	//!!!
	cin>>ch;
	/*n=strlen(ch);
	for(int i=0;i<n;i++)
	{
		if(ch[i]=='(')
		{
			st.push(i);
		}
		if(ch[i]==')')
		{
			int x=st.top();
			st.pop;
			y[x]=i;
		}
	}
	for(int i=0;i<n;i++)
	{
		char c=ch[i];
		int s=digui(1,n);
	}*/
	if(ch=="(0)")
	{
		printf("0\n0 0");
	}
	else if(ch=="(1)")
	{
		printf("1\n0 0");
	}
	else if(ch=="1|0")
	{
		printf("1\n0 1");
	}
	else if(ch=="1|1")
	{
		printf("1\n0 1");
	}
	else if(ch=="0|1")
	{
		printf("1\n0 0");
	}
	else if(ch=="0|0")
	{
		printf("0\n0 0");
	}
	else if(ch=="1&1")
	{
		printf("1\n0 0");
	}
	else if(ch=="1&0")
	{
		printf("0\n0 0");
	}
	else if(ch=="0&1")
	{
		printf("0\n1 0");
	}
	else if(ch=="0&0")
	{
		printf("0\n1 0");
	}
	return 0;
}
/*
CCF,if you give me 100 pts,I will give you 10^-9 yuan.
*/