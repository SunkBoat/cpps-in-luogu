#include<bits/stdc++.h> 
using namespace std;

int a,b,e[510][510],f[510][510],qjj,g;

struct node{
	int c,d;
}h[510];

bool cmp(node x, node y){
	if(x.c<y.c)return 1;
	else if(x.c==y.c&&x.d<=y.d)return 1;
	else return 0;
}

int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	for(int i=1; i<=a; i++){
		cin >> h[i].c >> h[i].d;
	}
	sort(h+1,h+1+a,cmp);
	memset(e,-1,sizeof(e));
	for(int i=1; i<=a; i++){
		for(int j=i+1; j<=a; j++){
			if(h[j].d<h[i].d)continue;
			e[i][j]=h[j].c-h[i].c+h[j].d-h[i].d-1;
		}
	}
	for(int i=1; i<=a; i++)f[0][i]=1;
	for(int i=1; i<=a; i++){
		for(int j=1; j<i; j++){
			if(e[j][i]==-1)continue;
			for(int k=b-e[j][i]; k>=0; k--){
				if(f[k][j]+1>f[k+e[j][i]][i])f[k+e[j][i]][i]=f[k][j]+1;
			}
		}
	}
	for(int i=0; i<=b; i++){
		for(int j=1; j<=a; j++){
			qjj=max(qjj,f[i][j]);
		}
	}
	cout<<qjj+b<<"\n";
	return 0;
}
