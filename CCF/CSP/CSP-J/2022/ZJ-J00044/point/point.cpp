#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int x[1000], y[1000], dp[1000][1000];
vector<pair<int, int> > a[1000];

int dis(int i, int j){
    return x[j]-x[i]+y[j]-y[i];
}

int main(){
    freopen("point.in", "r", stdin);
    freopen("point.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(x[j]>=x[i]&&y[j]>=y[i]&&dis(i, j)-1<=k){
                a[i].push_back(make_pair(j, dis(i, j)-1));
                // cout<<i<<" "<<j<<" "<<x[i]<<" "<<y[i]<<" "<<x[j]<<" "<<y[j]<<" "<<dis(i, j)-1<<endl;
            }
        }
    }
    for(int i=0;i<n;i++) for(int j=0;j<=k;j++) dp[i][j] = 1;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int l=0;l<=k;l++){
                for(int m=0;m<a[j].size();m++){
                    if(l>=a[j][m].second){
                        dp[j][l] = max(dp[j][l], dp[a[j][m].first][l-a[j][m].second]+1);
                        ans = max(ans, dp[j][l]);
                    }
                }
            }
        }
    }
    cout<<ans+k<<endl;
}