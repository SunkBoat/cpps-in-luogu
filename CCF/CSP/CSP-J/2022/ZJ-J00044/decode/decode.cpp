#include <iostream>

using namespace std;

int main(){
    freopen("decode.in", "r", stdin);
    freopen("decode.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        int n, d, e;
        scanf("%d %d %d", &n, &d, &e);
        // cout<<n<<" "<<d<<" "<<e<<endl;
        bool bb=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(d*e==(i-1)*(n/i-1)+1){
                    printf("%d %d\n", i, n/i);
                    bb=1;
                    break;
                }
            }
        }
        if(!bb) printf("NO\n");
    }
    return 0;
}