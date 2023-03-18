#include <iostream>
#include <cstdio>
using namespace std;
int k;
long long n[100005], e[100005], d[100005];
long long p, q;
bool f = false;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin >> k;
	for(int i = 0; i < k; i++){
		cin >> n[i] >> e[i] >> d[i];
	}
	for(int i = 0; i < k; i++){
		f = false;
		for(long long j = 2; j * j <= n[i]; j++){
			if(n[i] % j == 0){
				p = j;
				q = n[i] / j;
			}
			if((p -1) * (q - 1) + 1 == e[i] * d[i]){
				cout << p << ' ' << q << endl;
				f = true;
				break;
			}
		}
		if(f == false){
			cout << "NO" << endl;
		}
	}
	return 0;
}