#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	int k;
	cin >> k;
	while (k--) {
		long long n, e, d;
		scanf("%lld%lld%lld", &n, &e, &d);
		long long qp = n - e * d + 2;
		long long delta = qp * qp - 4 * n;
		if (delta < 0) {
			puts ("NO");
			continue;
		} 
		long long p = (qp - sqrtl (delta) ) / 2;
		if(p * (qp - p) != n){
			puts("NO");
			continue;
		}
		printf ("%lld %lld\n", p, qp - p);
	}


	return 0;

}

