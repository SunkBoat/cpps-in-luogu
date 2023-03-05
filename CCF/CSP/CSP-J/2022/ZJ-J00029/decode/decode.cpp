#include<bits/stdc++.h>
using namespace std;
int ys[100000];
int main() {
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	long long k,n,e,d;

	cin >> k;

	for(int ii=0; ii<k; ii++) {

		cin >> n >> e >> d;


		int abc=0;
		int OK=0;

		for(int i=1; i*i <= n; i++) {

			if(n%i == 0) {

				ys[abc]=i;
				abc++;
				ys[abc]=n/i;
				abc++;

			}

		}


		for(int i=0; i<abc; i++) {
			for(int j=0; j<abc; j++) {

				if( e*d == ((ys[i]-1)*(ys[j]-1))+1 ) {

					cout << ys[i] << " " << ys[j] << endl;

					OK = 1;


				}
				if(OK)break;
			}
			if(OK)break;
		}
		if(!OK) cout << "NO" << endl;

	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}