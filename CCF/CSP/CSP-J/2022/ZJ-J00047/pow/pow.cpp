#include <bits/stdc++.h>
using namespace std;
int main (void) {
	int n,m;
	FILE * fin = fopen ("pow.in","r");
	FILE * fout = fopen ("pow.out","w");
	fscanf (fin,"%d%d",&n,&m);
	if (n <= 1) fprintf (fout,"%d\n",n);
	long long b = 1;
	for (int j = 0;j < 31;j++) {
		b *= 2;
	}
	b--;
	long long a = 1;
	for (int j = 0;j < m;j++) {
		a *= n;
		if (a > b) {
			fprintf (fout,"%d\n",-1);
			return 0;
		}
	}
	fprintf (fout,"%lld\n",a);
	return 0;
}