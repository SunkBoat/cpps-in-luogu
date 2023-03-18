#include<bits/stdc++.h>
using namespace std;
long long n,k,Maxn=0,x,y;
struct point{
	long long value=0,a=0;
}p[110][110];
int main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		p[x][y].value=1;
		p[x][y].a=1;
	}
	for(int i=1;i<=105;i++)
	{
		for(int o=1;o<=105;o++)
		{
			//cout<<"p["<<i<<"]["<<o<<"].a="<<p[i][o].a<<endl;
			if(p[i][o].a==1)
			{
			p[i][o].value+=p[i-1][o].value+p[i][o-1].value;
			if(p[i-1][o-1].value!=0&&p[i-1][o].value!=0&&p[i][o-1].value!=0)
			p[i][o].value-=p[i-1][o-1].value;			
			//cout<<"p["<<i<<"]["<<o<<"].value="<<p[i][o].value<<
			//"="<<"p["<<i-1<<"]["<<o<<"].value="<<p[i-1][o].value
			//<<"+p["<<i<<"]["<<o-1<<"].value="<<p[i][o-1].value<<endl;
			Maxn=max(Maxn,p[i][o].value);
			//cout<<Maxn<<endl;
			}
		}
	}
	printf("%lld",Maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
