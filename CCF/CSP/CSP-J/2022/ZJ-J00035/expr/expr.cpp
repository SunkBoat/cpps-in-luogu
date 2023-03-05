#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int fh[N];
bool joc[N];
bool vis[N];
int cnt,ydl,hdl;
string a;
bool h(int xb,int len)
{	
	bool now;
	if(a[xb]!='(')
		now=(a[xb]=='1');
	else
	{
		int zkh=0;
		for(int i=xb+1;i<len;i++)
			if(a[i]=='(')
				zkh++;
			else
				if(a[i]==')')
					if(zkh==0)
					{
						now=h(xb+1,i);
						break;
					}
					else
						zkh--;
	}
	if(xb==len-1)
		return now;
	int z=0,r=0;
	for(int i=xb;i<len;i++)
	{
		if(a[i]=='(')
			z++;
		if(a[i]==')')
			r++;
		if(z!=r)
			continue;
		if(a[i]=='&')
		{
			if(!now)
			{
				ydl++;
				continue;
			}
			bool temp;
			if(a[i+1]!='(')
				temp=(a[i+1]=='1');
			else
			{
				int zkh=0;
				for(int j=i+2;j<len;j++)
					if(a[j]=='(')
						zkh++;
					else
						if(a[j]==')')
							if(zkh==0)
							{
								temp=h(i+2,j);
								break;
							}
							else
								zkh--;
			}
			now=temp;
		}
		if(a[i]=='|')
		{
			if(now)
			{
				hdl++;
				continue;
			}
			bool temp;
			if(a[i+1]!='(')
				temp=(a[i+1]=='1');
			else
			{
				int zkh=0;
				for(int j=i+2;j<len;j++)
					if(a[j]=='(')
						zkh++;
					else
						if(a[j]==')')
							if(zkh==0)
							{
								temp=h(i+2,j);
								break;
							}
							else
								zkh--;
			}
			now=temp;
		}
	}
	return now;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>a;
	if(a.size()<=5)
	{
		for(int i=0;i<a.size();i++)
			if(a[i]=='('||a[i]==')')
				a.erase(i,1);
	}
	if(a.find("(")==string::npos&&a.find(")")==string::npos)
	{
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='&')
				fh[cnt]=i,joc[cnt++]=true;
			if(a[i]=='|')
				fh[cnt++]=i;
		}
		bool now=(a[0]=='1');
		for(int i=0;i<cnt;i++)
		{
			if(vis[i])
				continue;
			vis[i]=true;
			if(joc[i])
			{
				if(now)
					now=(a[fh[i]+1]=='1');
				else
					ydl++;
			}
			else
			{
				bool temp=(a[fh[i]+1]=='1');
				i++;
				while(i<cnt&&joc[i])
				{
					vis[i]=true;
					if(temp)
						temp=(a[fh[i]+1]=='1');
					else
						ydl++;
					i++;	
				}
				i--;
				if(now)
					hdl++;
				else
					now=temp;
			}
		}
		cout<<now<<endl<<ydl<<' '<<hdl;
		return 0;
	}
	cout<<h(0,a.size())<<endl<<ydl<<' '<<hdl;
	return 0;
}