#include<cstdio>
#include<iostream>
using namespace std;
long long a,b,ans;

int main(){
    freopen("pow.in","r",stdin);
    freopen("pow.out","w",stdout);
    cin>>a>>b;
    ans=1;
    for(int i=1; i<=b; i++){
        if(ans*a>1e9){
            cout<<-1;
            return 0;
        }
        ans*=a;
    }
    cout<<ans;

    return 0;
}
