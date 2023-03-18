#include<bits/stdc++.h> 
using namespace std;

long long a,b,c,d,l,r;

int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a;
	for(int i=1; i<=a; i++){
		cin >> b >> c >> d;
		c=b-c*d+2,l=1,r=c;
		while(l<r){
			long long mid=(l+r)/2;
			if(mid+b/mid>c||b%mid!=0&&mid+b/mid>=c)l=mid+1;
			else r=mid;
		}
		if(b%l!=0||l+b/l!=c)cout<<"NO\n";
		else cout<<l<<" "<<b/l<<"\n";
	}
	return 0;
}
