#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std;
char niu[1000005];
int len,a=0,b=0;
int nxt[1000005];
char solve(int l,int r){
	if(l==r) return niu[l];
	if(niu[l]=='('){
		int i=nxt[l];
		niu[i]=solve(l+1,i-1);
		return solve(i,r);
	}
	if(niu[l]=='1'){
		if(niu[l+1]=='|'){
			b++;
			int i=l+2;
			while(i<=r){
				if(niu[i]=='(') i=nxt[i];
				if(i==r) return '1';
				if(niu[i]=='|'){
					niu[i-1]='1';
					return solve(i-1,r);
				}
				i++;
			}
//			For(i,l+2,r){
//				if(niu[i]=='(') now++;
//				if(niu[i]==')') now--;
//				if(i==r) return '1';
//				if(now==0&&niu[i]=='|'){
//					niu[i-1]='1';
//					return solve(i-1,r);
//				}
//			}
		}else{
			int i=l+2;
			while(i<=r){
				if(niu[i]=='(') i=nxt[i];
				if(i==r) return solve(l+2,r);
				if(niu[i]=='|'||niu[i]=='&'){
					niu[i-1]=solve(l+2,i-1);
					return solve(i-1,r);
				}
				i++;
			}
//			For(i,l+2,r){
//				if(niu[i]=='(') now++;
//				if(niu[i]==')') now--;
//				if(i==r) return solve(l+2,r);
//				if(now==0&&(niu[i]=='|'||niu[i]=='&')){
//					niu[i-1]=solve(l+2,i-1);
//					return solve(i-1,r);
//				}
//			}
		}
	}
	if(niu[l]=='0'){
		if(niu[l+1]=='&'){
			a++;
			int i=l+2;
			while(i<=r){
				if(niu[i]=='(') i=nxt[i];
				if(i==r) return '0';
				if(niu[i]=='|'||niu[i]=='&'){
					niu[i-1]='0';
					return solve(i-1,r);
				}
				i++;
			}
//			For(i,l+2,r){
//				if(niu[i]=='(') now++;
//				if(niu[i]==')') now--;
//				if(i==r) return '0';
//				if(now==0&&(niu[i]=='|'||niu[i]=='&')){
//					niu[i-1]='0';
//					return solve(i-1,r);
//				}
//			}
		}else{
			int i=l+2;
			while(i<=r){
				if(niu[i]=='(') i=nxt[i];
				if(i==r) return solve(l+2,r);
				if(niu[i]=='|'){
					niu[i-1]=solve(l+2,i-1);
					return solve(i-1,r);
				}
				i++;
			}
//			For(i,l+2,r){
//				if(niu[i]=='(') now++;
//				if(niu[i]==')') now--;
//				if(i==r) return solve(l+2,r);
//				if(now==0&&niu[i]=='|'){
//					niu[i-1]=solve(l+2,i-1);
//					return solve(i-1,r);
//				}
//			}
		}
	}
	return '1';				//none
}
stack<int> st;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>niu+1;
	len=strlen(niu+1);
	For(i,1,len){
		if(niu[i]=='(') st.push(i);
		if(niu[i]==')'){
			int be=st.top();
			st.pop();
			nxt[be]=i;
		}
	}
	char ans=solve(1,len);
	putchar(ans);
	cout<<endl;
	cout<<a<<" "<<b;
	return 0;
}