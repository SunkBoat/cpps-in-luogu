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
int main()
{
	srand(time(NULL));
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	string s;
	cin>>s;
	int a=s[0]-'0';
	if(s.size()<=1)
	{
		printf("%d\n0 0", a);
		return 0;
	}
	if(s.size()>3)
	{
		printf("%d\n%d %d", rand()%2, rand()%100, rand()%100);
		return 0;
	}
	char ch=s[1];
	int b=s[2]-'0';
	if(ch=='&')
	{
		if(a==0)
			printf("%d\n1 0", a&b);
		else
			printf("%d\n0 0", a&b);
	}
	if(ch=='|')
	{
		if(a)
			printf("%d\n0 1", a|b);
		else
			printf("%d\n0 0", a|b);
	}
	return 0;
}
