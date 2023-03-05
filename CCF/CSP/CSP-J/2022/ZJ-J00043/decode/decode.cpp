#include<bits/stdc++.h>
template<typename type>
void read(type &x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(!('0'<=ch && ch<='9'))
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while('0'<=ch && ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	x*=f;
	
}
typedef long long LL;
using namespace std;
LL K, a, b, c;
int main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	read(K);
	while(K--)
	{
		read(a), read(b), read(c);
		LL d=a-b*c+2;
		LL x_y=sqrt(d*d-4*a);
		if(x_y*x_y!=d*d-4*a)
			{printf("NO\n");continue;}
		LL xjy=d;
		printf("%lld %lld\n", (xjy-x_y)/2, (x_y+xjy)/2);
	}
	return 0;
}
