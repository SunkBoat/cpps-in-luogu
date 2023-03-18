#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int a,b;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	scanf("%d%d",&a,&b);
	long long ans=1;
	if(a==1){
		cout<<1<<endl;
		return 0;
	}
	while(b>=1)
	{
		if(b%2==0)
		{
		    ans=ans*ans;
		    if(ans>INF)
			{
				printf("-1\n");
				return 0;
			}
			b/=2;   
		}
		else if(ans*a>INF)
		{
			printf("-1\n");
			return 0;
		}
		else {
			ans=ans*a;
			b--;
		}
	}
	cout<<ans;
	return 0;
}