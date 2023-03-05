#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int s,s1,z[1000005],h[1000005],r,r1,l;
char c[1000005];
void ys(int x){
	if(h[x-1]==1&&z[x-1]==1){r=x,z[r]=0;return;}
	if(h[x-1]==0&&z[x-1]==0){r=x,z[r]=1;return;}
	int k=x,r2=r,p=0;
	for (int i=x;i<r;i++)
		if(!h[i]){
			if(!z[i])s++,z[i+1]=0,z[i]=-1,r2--;
			else z[i]=-1,z[i+1]&=1,r2--;
		}
	for (int i=x;i<=r2;i++){
		while(z[k]==-1)k++;
		if(p)s1++;
		p|=z[k],k++;
	}
	r=x;z[r]=p;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",c);l=strlen(c);
	for (int i=l;i>=1;i--)c[i]=c[i-1];
	c[0]='(',c[l+1]=')';l+=2;
	h[0]=1;
	for (int i=0;i<l;i++){
		if(c[i]=='0'||c[i]=='1')z[++r]=c[i]-48;
		if(c[i]=='&'||c[i]=='|')h[r]=c[i]=='|';
		if(c[i]=='(')a[++r1]=r+1;
		if(c[i]==')')ys(a[r1]),r1--;
	}
	printf("%d\n%d %d\n",z[1],s,s1);
}
