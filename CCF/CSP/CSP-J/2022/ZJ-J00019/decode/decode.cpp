#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
ll n,e,d,m,s;
int k;
bool flg;
int main(){
	freopen("decode.in","r",stdin);
	freopen("decode.out","w",stdout);
	cin>>k;
	while(k--){
		scanf("%d%d%d",&n,&d,&e);
		m=n-d*e+2;
		s=m*m-2*n;
		if(s<=1)printf("NO\n");
		else {
			flg=0;
			ll x,y;
			for(int i=1;1ll*i*i<=s;i++){
				x=i;
				y=(ll)sqrt(s-i*i);
				if(y*y==s-i*i&&x+y==m&&x<=y){
					flg=1;
					printf("%d %d\n",x,y);
//					break;
				}
			}if(!flg)printf("NO\n");
		}
	}return 0;
}
