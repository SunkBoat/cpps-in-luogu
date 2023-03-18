#include<bits/stdc++.h>
using namespace std;

long long n,m,r=1;
const long long p=1e9;

int main()
{
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>n>>m;
	while(m>0){
		if(m%2==1){
			r*=n;
			if(r>p){
				cout<<-1;
				return 0;
			}
		}
		if(m==1)break;
		n*=n;
		if(n>p){
			cout<<-1;
			return 0;
		}
		m/=2;
	}
	cout<<r;
	return 0;
}