#include <bits/stdc++.h>
using namespace std;
const long long E9=1000000000;
long long a,b;
int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin >> a >> b;
	if (a==1)
	{
		cout << 1 << endl;
		return 0;
	}
	if (a==E9)
	{
		if (b==1){
			cout << E9 << endl;
			return 0;
		}
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	long long c=1;
	for (long long rp=1;rp<=b;rp++)
	{
		c*=a;
		if (c>E9)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << c << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
