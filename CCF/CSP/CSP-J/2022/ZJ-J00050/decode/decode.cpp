#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int _;
ll N, E, D, M, P, Q;

int main() {
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	scanf("%d" ,&_);
	while (_--) {
		scanf("%lld %lld %lld" ,&N ,&E ,&D);
		M = N + 2 - E * D;
		Q = (M + (ll)sqrt((double)(M * M - 4 * N))) / 2ll;
		P = M - Q;
		if (P < 0) {
			Q = (M - (ll)sqrt((double)(M * M - 4 * N))) / 2ll;
			P = M - Q;
			if (Q < 0) {
				printf("NO\n");
				goto end;
			}
		}
		if (P * Q != N || (P - 1ll) * (Q - 1ll) + 1ll != E * D) {
			printf("NO\n");
			goto end;
		}
		if (P > Q) swap(P, Q);
		printf("%lld %lld\n" ,P ,Q);
		end:;
	}
	return 0;
}
