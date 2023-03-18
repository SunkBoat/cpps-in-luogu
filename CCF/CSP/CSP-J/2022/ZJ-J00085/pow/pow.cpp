#include <bits/stdc++.h>
using namespace std;
long long fast_power (long long a, long long b){
	long long ret = 1;
	while(b){
		if(a > 1000000000) return -1;
		if(b & 1){
			ret = ret * a;
			if(ret > 1000000000) return -1;
		}
		a = a * a;
		b >>= 1;
	}
	return ret;
}
int main(){
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	cout << fast_power (a, b) << endl;


	return 0;

}

