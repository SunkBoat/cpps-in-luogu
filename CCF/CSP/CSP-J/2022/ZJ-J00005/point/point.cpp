#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int x,y;
} a[555];
int n,K;
int f[555][111];
int s[555];
bool cmp(node x,node y) { //x��һ�ؼ��� y�ڶ��ؼ���
	return x.x==y.x ? x.y<y.y : x.x<y.x;
}
signed main() {
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp); 
	int ans=0; 
	for(int k=0; k<=K; k++) {//2.5e7��ʱ�临�Ӷȿ��øոպ� 
		for(int i=1; i<=n; i++) {//�������ڿ��ĵ� 
			for(int j=1; j<i; j++) {//ת�Ƶĵ� 
				int p=a[i].x-a[j].x+a[i].y-a[j].y-1;//��Ҫ���ٸ��� 
				if(a[j].y<=a[i].y&&p<=k) { //x�϶����� ��y���� ��һ������
					f[i][k]=max(f[i][k],f[j][k-p]+p+1);
				}
				ans=max(ans,f[i][k]+1+K-k);
			}
		}
	}
    printf("%d",ans);
    return 0;
}

