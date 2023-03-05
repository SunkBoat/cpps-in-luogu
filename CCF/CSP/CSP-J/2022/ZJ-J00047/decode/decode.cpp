#include <bits/stdc++.h>
using namespace std;
int main (void) {
	FILE * fin = fopen("decode.in","r");
	FILE * fout = fopen("decode.out","w");
	int kase;
	long long e,d;
	long long sum,n;
	fscanf (fin,"%d",&kase);
	while (kase--) {
		fscanf (fin,"%lld%lld%lld",&n,&e,&d);
		sum = n - e * d + 2;
		if (sum < 0) {
			fprintf (fout,"NO\n");
			continue;
		}
		long long l = 0,r = sum/2+1;
		long long mid = 0,o = 0;
		while (l <= r) {
			mid = (l+r)/2;
			o = sum-mid;
			if (o * mid == n) {
				break;
			}
			else if (o * mid > n) r = mid-1;
			else l = mid + 1;
		}
		if (o * mid == n) fprintf (fout,"%lld %lld\n",min(o,mid),max(o,mid));
		else fprintf (fout,"NO\n");
	}
	return 0;
}