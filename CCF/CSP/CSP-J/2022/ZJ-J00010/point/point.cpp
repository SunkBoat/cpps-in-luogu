#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
struct Caijingmeng{
	long long x,y;
}cjm[505];
bool cmp(Caijingmeng a,Caijingmeng b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>cjm[i].x>>cjm[i].y;
	sort(cjm+1,cjm+n+1,cmp);
	if(k == 0){
		for(int i = 1;i <= n;i++){
			if((cjm[i].x == cjm[i+1].x && cjm[i].y+1 == cjm[i+1].y) || (cjm[i].y == cjm[i+1].y && cjm[i].x+1 == cjm[i+1].x)) ans++;
		}
		cout<<ans;
	}
	else{
		for(int i = 1;i <= n;i++){
			if((cjm[i].x == cjm[i+1].x && cjm[i].y+1 == cjm[i+1].y) || (cjm[i].y == cjm[i+1].y && cjm[i].x+1 == cjm[i+1].x) || (cjm[i].x == cjm[i+1].x && cjm[i].y+k+1 == cjm[i+1].y) || (cjm[i].y == cjm[i+1].y && cjm[i].x+k+1 == cjm[i+1].x)) ans++;
		}
		cout<<ans;
	}
	return 0;
}
