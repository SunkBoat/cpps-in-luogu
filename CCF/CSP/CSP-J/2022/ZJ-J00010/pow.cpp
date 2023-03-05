#include<bits/stdc++.h>
using namespace std;
long long a,b,ans = 1;
bool flag;
int main(){
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);
	cin>>a>>b;
	for(int i = 1;i <= b;i++){
		ans *= a;
		if(ans > 1000000000){
			flag = true;
			break;
		}
	}
	if(flag) cout<<-1;
	else cout<<ans;
	return 0;
}
