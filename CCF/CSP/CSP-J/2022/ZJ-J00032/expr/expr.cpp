#include<bits/stdc++.h>
using namespace std;
int n=1,aa,bb,cc;
char a[1000001];
int gf[1000001];
stack<int>q;
bool check(int x,int y){
	stack<int>b,c;
	if(x==y){
		return a[x]-'0';
	}
	int flag=0;
	int mid,hh=0,kk;
	for(int i=x;i<=y;i++){
		if(a[i]=='(')flag++;
		if(a[i]==')')flag--;
		if(flag)continue;
		if(a[i]=='&'||a[i]=='|'){
			hh++;
			if(hh==2)b.pop(),c.pop(),hh=0;
			b.push(a[i]=='&');
			c.push(i);
		}
	}
	hh++;
	if(hh==2&&c.size()>1)b.pop(),c.pop(),hh=0;
	mid=c.top();
	if(b.top()){
		int xx=(a[mid-1]==')'&&gf[mid-1]==x)?x+1:x;
		int yy=(a[mid-1]==')'&&gf[mid-1]==x)?mid-2:mid-1;
		bool k=check(xx,yy);
		if(k==0){
			aa++;
			return 0;
		}
		xx=(a[y]==')'&&gf[y]==mid+1)?mid+2:mid+1;
		yy=(a[y]==')'&&gf[y]==mid+1)?y-1:y;
		bool k1=check(xx,yy);
		if(k1==0){
			aa++;
			return 0;
		}
		return k&&k1;
	}
	else {
		int xx=(a[mid-1]==')'&&gf[mid-1]==x)?x+1:x;
		int yy=(a[mid-1]==')'&&gf[mid-1]==x)?mid-2:mid-1;
		bool k=check(xx,yy);
		if(k==1){
			bb++;
			return 1;
		}
		xx=(a[y]==')'&&gf[y]==mid+1)?mid+2:mid+1;
		yy=(a[y]==')'&&gf[y]==mid+1)?y-1:y;
		bool k1=check(xx,yy);
		if(k1==1){
			bb++;
			return 1;
		}
		return k||k1;
	}
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	a[n]=getchar();
	if(a[n]=='(')q.push(n);
	while(a[n]!='\n'){
		n++;
		a[n]=getchar();
		if(a[n]=='(')q.push(n);
		if(a[n]==')')gf[n]=q.top(),q.pop();
	}
	n--;
	cout<<check(1,n)<<"\n"<<aa<<" "<<bb<<endl;
}
