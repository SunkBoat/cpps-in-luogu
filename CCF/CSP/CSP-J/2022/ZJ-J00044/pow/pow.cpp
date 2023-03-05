#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("pow.in", "r", stdin);
    freopen("pow.out", "w", stdout);
    int a, b;
    cin>>a>>b;
    long long ans=1;
    for(int i=0;i<b;i++){
        ans = ans*a;
        if(ans>1000000000){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}