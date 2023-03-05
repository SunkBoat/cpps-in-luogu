#include<bits/stdc++.h>
using namespace std;

long long k, n, d, e;
long long a, b, c;
long long p, q;
// a*, b+, c-;

int main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	
	cin >> k;
	while(k--)
	{
		cin >> n >> d >> e;
		a = n;
		b = n + 2 - e * d;
		c = sqrt(b * b - 4 * a);
		//cout << a << " " << b << " " << c;
		if(c < 0) cout << "NO" << endl;
		else if(c * c != b * b - 4 * a) cout << "NO" << endl;
		else if(c % 2 != b % 2) cout << "NO" << endl;
		else
		{
			p = (b + c) / 2;
			q = (b - c) / 2;
			if(p > q) swap(p, q);
			cout << p << " " << q << endl;
		}
	}
	
	return 0;
}