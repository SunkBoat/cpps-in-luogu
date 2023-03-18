#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	string s;
	int i,res1=0,res2=0;
	cin>>s;
	int n=s.size();
	for(i=0;i<n;i++){
		if(s[i+1]=='&') {
			if(s[i]=='0'){
				res1++;
			}
			s[i+2]=s[i]&s[i+2];
			s[i]=s[i+1]='2';
		}
	}
	for(i=0;i<n;i++){
		int c=i;
		while(s[c]=='2') c--;
		if(s[i+1]=='|'){
			int k=i+2;
			while(s[k]=='2') k++;
			if(s[i]=='1'){
				res2++;
			}
			s[k]=s[c]|s[k];
			s[c]=s[i+1]='2';
		}
	}
	printf("%c\n",s[n-1]);
	printf("%d %d",res1,res2);
	return 0;
}