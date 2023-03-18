#include<bits/stdc++.h>
using namespace std;
string s,t;
int to[3000010],n,fr[1000010],bk[1000010],cnt1,cnt2;
stack<int>st;
void work_expr(int l,int r);
int work_part(int l){
	if(s[l]!='(')return l+1;
	work_expr(l+1,to[l]-1);
	return to[l]+1;
}
void work_expr(int l,int r){
	int lst=l,nw,tmp=work_part(l);
	if(tmp>=r)return;
	while((nw=work_part(tmp+1))<=r+1){
		if(s[tmp]=='&')fr[lst]++,bk[nw-1]++,tmp=nw;
		else lst=tmp+1,tmp=nw;
		if(nw==r+1)break;
	}
}
bool work(int l,int r){
	while(to[l]==r&&t[l]=='(')l++,r--;
	if(l>r)return false;
	if(l==r)return t[l]=='1';
	if(t[to[l]+1]=='&'){
		if(work(l,to[l])==1){
			return work(to[r],r);
		}
		cnt1++;return false;
	}
	while(l<=r){
		if(work(l,to[l])){
			l=to[l]+2;
			while(l<=r)cnt2++,l=to[l]+2;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='(')st.push(i);
		else if(s[i]==')')to[i]=st.top(),to[to[i]]=i,st.pop();
	}
	work_expr(0,n-1);
	for(int i=0;i<n;i++){
		while(fr[i]--)t.push_back('(');
		t.push_back(s[i]);
		while(bk[i]--)t.push_back(')');
	}
	n=t.size();
	memset(to,0,sizeof(to));
	for(int i=0;i<n;i++){
		if(t[i]=='(')st.push(i);
		else if(t[i]==')')to[i]=st.top(),to[to[i]]=i,st.pop();
		else to[i]=i;
	}
	cout<<work(0,n-1)<<'\n'<<cnt1<<' '<<cnt2<<'\n';
    return 0;
}