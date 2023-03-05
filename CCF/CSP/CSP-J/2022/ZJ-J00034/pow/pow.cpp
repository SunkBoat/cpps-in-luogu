#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define R(i,l,r) for(int i=(l);i>=(r);i--)
int qp(int a,int b){
    ll res=1;
    F(i,1,b){
        res=res*(ll)a;
        if(res>(int)(1e9))return -1;
    }    
    return (int)res;
}
int main(){
    freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==1){
        printf("1\n");
        return 0;
    }
    printf("%d\n",qp(a,b));
	return 0;
}