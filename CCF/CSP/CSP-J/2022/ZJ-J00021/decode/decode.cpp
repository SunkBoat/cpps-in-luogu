#include <bits/stdc++.h>
using namespace std;
long long k;
int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin >> k;
	while(k--)
	{
		long long n,e,d;
		cin >> n >> e >> d;
		long long c=e*d;
		long long b=n-c+2;
		bool flag=true;
		long long l=1,r=b/2,mid;
		while(l<=r)
		{
			//cout <<mid << endl;
			mid=(l+r)>>1;
			if (mid*(b-mid)==n)
			{
				cout << mid << " " << b-mid << endl;
				flag=false;
				break;
			}
			if (mid*(b-mid)<n) l=mid+1;
			else r=mid-1;
		}
		if (l*(b-l)==n&&flag==true)
		{
			cout << l << " " << b-l << endl;
			flag=false;
		}
		if (flag) cout << "NO" << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
