#include<bits/stdc++.h>
using namespace std;
const int N=1000009;

char s[N];
int q1[N],t1=0;
int q2[N],t2=0;
int ans1,ans2;
int len;

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",s);
	len=strlen(s);
	s[len]='|';
	for(int i=0;i<len;i++)
	{
		char c=s[i];
		if(c=='0'||c=='1')
		{
			q1[++t1]=(c-'0');
			while(1)
			{
				if((t1>=2)&&(q2[t2]==1||s[i+1]=='|'))
				{
					int x=q1[t1-1],y=q1[t1],tmp;
					if(q2[t2]==1)
					{
						if(x==0)ans1++;
						tmp=x&y;
					}
					else
					{
						if(x==1)ans2++;
						tmp=x|y;
					}
					q1[--t1]=tmp;
					t2--;
				}
				else break;
			}	
		}
		else
		{
			if(c=='&')q2[++t2]=1;
			else q2[++t2]=2;
		}
	}
	printf("%d\n%d %d\n",q1[1],ans1,ans2);
	return 0;
}