#include<bits/stdc++.h>
using namespace std;
struct c{
	int x,y;
}a[10005];
bool cmp(c u,c b){
	return u.x<b.x;
}
int main(){
	int n,k,maxy=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		maxy=max(maxy,a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		
	}
	return 0;
} 
