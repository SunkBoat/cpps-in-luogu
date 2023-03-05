#include<bits/stdc++.h>
using namespace std;

long long a, b;

long long kasumi(long long x, long long y)
{
	long long ans = 1;
	long long tmp = x;
	long long k = b;
	while(b != 0)
	{
		if(b != k)
		{
			if(tmp * tmp > 1e9) return -1;
			tmp = tmp * tmp;
		}
		
		if(b & 1)
		{
			if(ans * tmp > 1e9) return -1;
			ans *= tmp;
		}
		b = b >> 1;
	}
	
	if(ans > 1e9) return -1;
	else return ans;
}

int main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	
	cin >> a >> b;
	cout << kasumi(a, b) << endl;
	return 0;
}