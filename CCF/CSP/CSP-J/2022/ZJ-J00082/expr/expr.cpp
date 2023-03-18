#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int ControlId,Level,Vanilla;
}Cs[1000024];

int Number[1000024],g,O,A;
int Cursor[1000024];
bool Short[1000024];
bool vis[1000024];

bool cmp(Node a,Node b)
{
	if(a.Level==b.Level)
	{
		if(a.ControlId==b.ControlId)
		{
			return a.Vanilla<b.Vanilla;
		}
		return a.ControlId>b.ControlId;
	}
	return a.Level>b.Level;
}

int Top(int x)
{
	if(!vis[x]) return x;
	Cursor[x]=Top(Cursor[x]);
	return Cursor[x];
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char Raw[1000024];
	scanf("%s",Raw);
	int Stackdeep=0,cons=0;
	int lth=strlen(Raw);
	for(int i=0;i<lth;i++)
	{
		if(Raw[i]=='(')
		{
			Stackdeep++;
		}
		else if(Raw[i]==')')
		{
			Stackdeep--;
		}
		else if(Raw[i]=='|')
		{
			Cs[cons]={0,Stackdeep,g++};
			cons++;
//			printf("%d:|\n",g-1);
		}
		else if(Raw[i]=='&')
		{
			Cs[cons]={1,Stackdeep,g++};
			cons++;
//			printf("%d:&\n",g-1);
		}
		else if(Raw[i]=='0')
		{
			Number[g++]=0;
//			printf("%d:0\n",g-1);
		}
		else if(Raw[i]=='1')
		{
			Number[g++]=1;
//			printf("%d:1\n",g-1);
		}
	}
//	printf("[MAIN/DEBUG]Finish read.\n");
	sort(Cs,Cs+cons,cmp);
	int l,r;
	for(int i=0;i<cons;i++)
	{
		l=Cs[i].Vanilla-1;
		r=Cs[i].Vanilla+1;
		if(vis[l])
		{
			l=Top(l);
		}
		if(vis[r])
		{
			r=Top(r);
		}
//		printf("Do %d as %d %d\n",Cs[i].Vanilla,l,r);
		if(Cs[i].ControlId==1)
		{
			if(Number[l]==0)
			{
				Number[Cs[i].Vanilla]=0;
				Short[Cs[i].Vanilla]=1;
				A++;
				if(Short[r])
				{
					if(Short[r]==1)
					{
						O--;
					}
					else
					{
						A--;
					}
				}
			}
			else
			{
				Number[Cs[i].Vanilla]=Number[r];
			}
		}
		else
		{
			if(Number[l]==1)
			{
				Number[Cs[i].Vanilla]=1;
				Short[Cs[i].Vanilla]=2;
				O++;
				if(Short[r])
				{
					if(Short[r]==1)
					{
						O--;
					}
					else
					{
						A--;
					}
				}
			}
			else
			{
				Number[Cs[i].Vanilla]=Number[r];
			}
		}
		vis[l]=true;
		vis[r]=true;
		Cursor[l]=Cs[i].Vanilla;
		Cursor[r]=Cs[i].Vanilla;
		
	}
	printf("%d\n%d %d\n",Number[Cs[cons-1].Vanilla],A,O);
}