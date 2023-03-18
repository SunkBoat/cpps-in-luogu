#include <iostream>
#include <cstdio>
using namespace std;
long long maxn = 1000000000;
int a, b;
long long x = 1;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin >> a >> b;
	if(a == 1){
		cout << "1";
		return 0;
	}
	for(int i = 1; i <= b; i++){
		x *= a;
		if(x > maxn){
			cout << "-1";
			return 0;
		}
	}
	cout << x;
	return 0;
}