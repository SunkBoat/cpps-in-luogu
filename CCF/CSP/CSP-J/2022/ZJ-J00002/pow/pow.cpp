#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;

int x,y;

int _pow(int x,int y)
{
	if(y==0)return 1;
	int k=_pow(x,y/2);
	int ret=k*k;
	if(y%2==1)ret*=x;
	if(ret<0 || ret>INF)return 0;
	//printf("%d %d %d\n",x,y/2,k);
	return ret;
}

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d%d",&x,&y);
	int k=_pow(x,y);
	printf("%d\n",k==0? -1:k);
}
/*
CSP2022 RP++!
*/
