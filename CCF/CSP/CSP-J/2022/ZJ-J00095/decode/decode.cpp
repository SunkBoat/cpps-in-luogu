#include<cstdio>
#include<iostream>
using namespace std;

long long n[100005],m[100005],k;

int check(long long x,long long add,long long tim){
    long long y=add-x;
    if(x*y<tim) return 1;
    if(x*y==tim) return 2;
    return 3;
}

int main(){
    freopen("decode.in","r",stdin);
    freopen("decode.out","w",stdout);
    cin>>k;
    for(int i=1; i<=k; i++){
        long long a,b,c;
        cin>>n[i]>>a>>b;
        m[i]=n[i]-(a*b)+2;
        long long l=1,r=m[i]/2;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid,m[i],n[i])<=2) l=mid+1;
            else r=mid-1;
        }
        if(check(r,m[i],n[i])==2) cout<<r<<" "<<m[i]-r;
        else cout<<"NO";
        cout<<endl;
    }
    return 0;
}
