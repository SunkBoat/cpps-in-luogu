#include<bits/stdc++.h>
using namespace std;
int l,ans,sum1,sum2;
char st[15];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",st);
	l=strlen(st);
	if(l==3){if(st[1]=='&'){if(st[0]=='0'){ans=0;sum1++;}else if(st[2]=='0')ans=0;else ans=1;}if(st[1]=='|'){if(st[0]=='1'){ans=1;sum2++;}else if(st[2]=='1')ans=1;else ans=0;}}
	else if(l==5){
		int ans1=-1;
		for(int i=0;i<l;i++){if(st[i]=='&'&&ans1==-1){if(st[i-1]=='0'){sum1++;ans1=0;}else if(st[i+1]=='0')ans1=0;else ans1=1;st[i]=st[i-1]=st[i+1]='.';}}
		if(ans1==-1){for(int i=0;i<l;i++){if(st[i]=='|'){if(st[i-1]=='1'){sum2++;ans1=1;}else if(st[i+1]=='1')ans1=1;else ans1=0;st[i]=st[i-1]=st[i+1]='.';break;}}}
		for(int i=0;i<l;i++){
			if(st[i]=='&'){if(st[i-1]=='.'){if(ans1==0){sum1++;ans=0;}else if(st[i+1]=='0')ans=0;else ans=1;}else{if(st[i-1]=='0'){sum1++;ans=0;}else if(ans1==0)ans=0;else ans=1;}break;}
			if(st[i]=='|'){if(st[i-1]=='.'){if(ans1==1){sum2++;ans=1;}else if(st[i+1]=='1')ans=1;else ans=0;}else{if(st[i-1]=='1'){sum2++;ans=1;}else if(ans1==1)ans=1;else ans=0;}break;}
		}
	}
	cout<<ans<<endl<<sum1<<" "<<sum2;
}
