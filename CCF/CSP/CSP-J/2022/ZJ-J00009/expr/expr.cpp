#include<bits/stdc++.h>
using namespace std;
int dy,dh,len;
char s[1000001],ans;
void change(int a)
{
	for(int i=len+1;i>a;i--)
	s[i]=s[i-1];
}
void delete1(int x,int y)
{
	for(int i=x,j=1;y+j<=len;i++,j++)
	{
		s[i]=s[y+j];
	}
}
void dele(int a,char b)
{
	int x=1,ii=a;
	s[a]=b;
	while(x)
	{
		ii++;
		if(s[ii]=='(')x++;
		if(s[ii]==')')x--;
	}
	delete1(a+1,ii);
}
void find(int a)
{
	int x=0;
	for(int i=a-1;i>=0;i--)
	{
		if(s[i]==')')x++;
		if(s[i]=='(')x--;
		if(x==0)
		{
			change(i);
			len++;
			s[i]='(';
			break;
		}
	}
}
void find1(int a)
{
	int x=0;
	for(int i=a+1;i<=len;i++)
	{
		if(s[i]=='(')x++;
		if(s[i]==')')x--;
		if(x==0)
		{
			change(i+1);
			len++;
			s[i+1]=')';
			break;
		}
	}
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='&')
		{
			find(i);
			i++;
			find1(i);
		}
	}
	for(int i=0;i<len;i++)
	{
		if((s[i]=='0'||s[i]=='1')&&s[i+1]=='|')
		{
			if(s[i+2]=='0'||s[i+2]=='1')
			{
				if(s[i-1]!='('||s[i+3]!=')')
				{
					change(i);
					s[i]='(';
					i++;
					len++;
					change(i+3);
					s[i+3]=')';
					i++;
					len++;	
				}
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0'&&s[i+1]=='&')
		{
			dy++;
			if(s[i-1]=='(')dele(i-1,'0');
			i-=2;
		}
		if(s[i]=='1'&&s[i+1]=='|')
		{
			dh++;
			if(s[i-1]=='(')dele(i-1,'1');
			i-=2;
		}
	}
	if(s[0]=='(')
	{
		
	s[0]=s[1];
	s[1]=s[2];
	s[2]=s[3];
	s[3]=s[10086];
	s[4]=s[10086];
	}
	ans=s[0];
	for(int i=1;i<strlen(s);i+=2)
	{
		if(s[i]=='&')
		{
			if(ans=='0'||s[i+1]=='0')ans='0';
			else ans='1';
		}
		if(s[i]=='|')
		{
			if(ans=='1'||s[i+1]=='1')ans='1';
			else ans='0';
		}
	}
	cout<<ans<<endl;
	cout<<dy<<" "<<dh;
	return 0;
}