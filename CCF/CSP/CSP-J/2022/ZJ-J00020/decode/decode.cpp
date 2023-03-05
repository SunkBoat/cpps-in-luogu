#include<cstdio>
#include<cmath>

using namespace std;
typedef long long ll;

int main() {
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	
	int k;
	scanf("%d", &k);
	while(k--)
	{
		ll n, e, d;
		scanf("%lld%lld%lld", &n, &e, &d);
		ll tmp = n - e * d + 2;
		
		if(tmp * tmp - 4 * n < 0)
		{
			printf("NO\n");
			continue;
		}
		ll t = sqrt(tmp * tmp - 4 * n);
		if(t * t != tmp * tmp - 4 * n)
		{
			printf("NO\n");
			continue;
		}
		printf("%lld %lld\n", (tmp-t)/2, (tmp+t)/2);
	}
}
