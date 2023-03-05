#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxx=0;
struct node{
	int x,y;
}a[505];
bool cmp(node a,node b){
	if(a.x!=b.x){
		return a.x<b.x;
	}
	return a.y<b.y;
}
void dfs(int pos,int point){
	int lasty=1e9;
	for(int i=pos+1;i<n;i++){
		if(a[i].y>=a[pos].y&&a[i].y<=lasty){
			lasty=a[i].y;
			int oldm=m;
			m-=a[i].x-a[pos].x+(a[i].y-a[pos].y)-1;
			//cout<<"i:"<<i<<" pos:"<<pos+1<<" point:"<<point<<" m:"<<m<<" a[i].x-a[pos].x:"<<a[i].x-a[pos].x<<" a[pos].y:"<<a[pos].y<<endl;
			//cout<<a[i].y<<" "<<a[pos].y<<" "<<a[i].y-a[pos].y<<endl;
			if(m>=0){
			}
			else{
				maxx=max(point,maxx);
				return ;
			}
			dfs(i,point+a[i].x-a[pos].x+a[i].y-a[pos].y);
			m+=a[i].x-a[pos].x+(a[i].y-a[pos].y);
		}
	}
	return ;
}
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a,a+n,cmp);
	int dp[505];
	for(int i=0;i<n;i++){
		cout<<a[i].x<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i].y<<" ";
	}
	cout<<endl;
	int lasty=1e9;
	for(int i=0;i<n;i++){
		//cout<<i<<endl;
		if(a[i].y<lasty){
			lasty=a[i].y;
			dfs(i,1);
		}
	}
	cout<<maxx;
	return 0;
}