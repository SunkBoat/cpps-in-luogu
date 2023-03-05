#include<iostream>
#include<stdio.h>
#define int unsigned long long
using namespace std;
int k,n,e,d;
int my_sqrt(int x){
	int l=0,r=x,ans,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(mid*mid<=x){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
signed main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	scanf("%lld",&k);
	while(k--){
		scanf("%lld%lld%lld",&n,&e,&d);
		int m=n-e*d+2;
		int derta=m*m-4*n;
		if(derta<0){
			printf("NO\n");
		}else{
			int t=my_sqrt(derta);
			if(t*t!=derta||(m+t)%2==1||(m-t)/2<=0){
				printf("NO\n");
			}else{
				printf("%lld %lld\n",(m-t)/2,(m+t)/2);
			}
		}
	}
}
