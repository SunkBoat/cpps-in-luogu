#include<bits/stdc++.h>
using namespace std;
string s;
int ans1,ans2,ans=2;
int sum1,sum2,sum;
int l;
int b[1000005];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	bool p=1,p1=1,p2=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='&') p=0;
		if(s[i]=='|') p1=0;
		if(s[i]=='(') p2=0;
	}
	if(s.size()<=3)
	{
		if(s[0]=='0'&&s[1]=='&') sum1++;
		else if(s[0]=='0'&&s[1]=='|'&&s[2]==1) ans=1;
		else if(s[0]=='1'&&s[1]=='|')
		{
			ans=1;
			sum2++;
		} 
		else if(s[0]=='1'&&s[1]=='&'&&s[2]=='1') ans=1;	
	}
	else if(p2==1)
	{
		for(int i=0;i<s.size();i++)
		{
			if(b[i]==1) continue;
			b[i]=1;
			if(i==0)
			{
				ans=s[i]-'0';
				b[i]=1;
			}
			if(s[i]=='&')
			{
				b[i+1]=1;
				if(ans==0) sum1++;
				else if(s[i+1]=='0') ans=0;
				else ans=1;
			}
			if(s[i]=='|')
			{
				b[i+1]=1;
				if(s[i+2]=='|')
				{
					if(ans==1) sum2++;
					else if(s[i+1]==0) ans=0;
					else ans=1;
				}
				else
				{
					if(s[i+1]=='0')
					{
						sum1++;
						ans1=0;
					} 
					if(s[i+3]=='0') ans1=0;
					b[i+1]=1;
					b[i+2]=1;
					b[i+3]=1;
					if(ans1==0&&ans==0) ans=0;
					else if(ans1==1) ans=1;
					else if(ans1==0&&ans==1) ans=1; 
				}
			}
		}
	}
	else if(p1==1)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='('&&s[i]!='&'&&ans==2)
				ans=s[i]-'0';
			else
				sum=s[i]-'0';
			if(ans==0||sum==0)
			{
				ans=0;
				sum1++;
				break;
			}
		}
	}
	if(ans==2) ans=0;
	cout<<ans<<endl<<sum1<<" "<<sum2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
