#include<bits/stdc++.h>
using namespace std;
string s;
int len;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	int len=s.size();
	if(len<=3)	
	{
		int ans=0,ans1=0;
		int last=s[0]-'0';
		int now=s[2]-'0';
		if(s[1]=='&')
		{
			if(last==0) ans++;
			last=last&now;	
		}
		if(s[1]=='|')
		{
			if(last==1) ans1++;
			last=last|now;
		}
		cout<<last<<endl;
		cout<<ans<<" "<<ans1;
		return 0;
	}
	if(len<=5)
	{
		int ans=0,ans1=0;
		int last=s[0]-'0';
		int now=s[2]-'0';
		int now1=s[4]-'0';
		if(s[1]=='&')
		{
			if(last==0) ans++;
			else
			{
				last=last&now;
				if(s[3]=='|')
				{
					if(last==1) ans1++;
					last=last|now1;
				}
				if(s[3]=='&')
				{
					if(last==0) ans++;
					last=last&now;
				}
			}
		}
		if(s[1]=='|')
		{
			if(last==1) ans1++;
			else
			{
				if(s[3]=='|')
				{
					last=last|now;
					if(last==1) ans1++;
					last=last|now1;
				}
				if(s[3]=='&')
				{
					if(now==0) ans++;	
					now=now&now1;
					last=last|now;
				}
			}
		}
		cout<<last<<endl;
		cout<<ans<<" "<<ans1;
	}
	return 0;
}
