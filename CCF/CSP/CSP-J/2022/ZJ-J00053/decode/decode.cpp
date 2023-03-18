#include<bits/stdc++.h>
using namespace std;

int k;

int main()
{
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>k;
	while(k--){
		long long n,m,k;
		cin>>n>>m>>k;
		long long y=n;
		long long x=n-m*k+2;
		if(x<2){
			cout<<"NO\n";
			continue;
		}
		if(x*x-4*y<0){
			cout<<"NO\n";
			continue;
		}
		long long p=sqrt(x*x-4*y);
		if(p*p==x*x-4*y&&p<=x){
			if((x+p)%2==1||(x-p)%2==1){
				cout<<"NO\n";
				continue;
			}
			long long p1=(x+p)/2;
			long long p2=(x-p)/2;
			cout<<min(p1,p2)<<" "<<max(p1,p2)<<"\n";
		}
		else{
			cout<<"NO\n";
			continue;
		}
	}
	return 0;
}