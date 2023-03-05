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
LL a, b;
const LL lcy=1e9;
LL power(LL x, LL p)
{
	LL result=1;
	while(p)
	{
		if(p&1)
		{
			result*=x;
			if(result>lcy)
			{
				printf("-1");
				exit(0);
			}
		}
		x=x*x;
//		printf("%lld %lld\n", x, result);
		if(x>lcy && p>1)
		{
			printf("-1");
			exit(0);
		}
		p>>=1;
	}
	return result;
}
int main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	read(a), read(b);
	printf("%lld", power(a, b));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
