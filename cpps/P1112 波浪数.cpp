#include "bits/stdc++.h"
using namespace std;

int L, R;
int l, r;
int Qt, cnt;

int a[10000050];

void init(int x) {
	for (int i = 1; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			if (i == j) continue;
			int s = 0;
			for (int k = 1; k <= 30; ++k) {
				s = s * x + i;
				if (s < 0 || s > 10000000) break;
				a[s] += 1;
				//if (s == 5592405) cout << x << endl;
				s = s * x + j;
				if (s < 0 || s > 10000000) break;
				a[s] += 1;
				//if (s == 5592405) cout << x << endl;
			}
		}
	}
}

int main() {
	scanf ("%d%d%d%d%d", &L, &R, &l, &r, &Qt);
	for (int i = L; i <= R; ++i) init(i);
	for (int i = l; i <= r; ++i) {
		if (a[i] == Qt) printf ("%d\n", i);
		//if (i == 5592405) cout << i << ' ' << a[i] << endl;
	}
}
