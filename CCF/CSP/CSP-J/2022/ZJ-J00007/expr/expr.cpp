#include<bits/stdc++.h>
using namespace std;
struct TREE{
	int a=-1,b=-1,f1=0,f2=0;
}tree[1000005];
char st[1000005],stk[1000005];
int l,sum;
bool mp(int x){
	if(x=='|')return 1;
	if(x=='&')return 2;
}
int dfs(int l,int r,int dep){
	//cout<<l<<" "<<r<<endl;
	if(l==r)return st[l]-48;
	//while(st[l]=='('&&st[r]==')')l++,r--;
	int kh=0,mn=10000000,p=0;
	//for(int i=l;i<=r;i++){
	//	if(st[i]==')'){
	//		if(stk[kh]='(')kh--;
	//		else{
	//			kh++;
	//			stk[kh]=')';
	//		}
	//	}
	//	if(st[i]=='('){
	//		kh++;
	//		stk[kh]='(';
	//	}
	//}
	//for(int i=1;i<=kh;i++)l--,r++;
	kh=0,mn=10000000,p=0;
	int mpp=10;
	for(int i=l;i<=r;i++){
		if(st[i]=='(')kh++;
		if(st[i]==')')kh--;
		if(kh<=mn&&(st[i]=='|'||st[i]=='&')){
			mn=kh;
			mpp=mp(st[i]);
			p=i;
		}
		if(kh==mn&&mp(st[i])<=mpp&&(st[i]=='|'||st[i]=='&')){
			mn=kh;
			mpp=mp(st[i]);
			p=i;
		}
	}
	//cout<<p<<endl;
	//if(l-r==w)for(int i=l;i<=r;i++)if(st[i]=='0'||st[i]=='1')return st[i]-48;
	sum++;
	tree[dep].a=sum;
	int ans1=dfs(l,p-1,sum);
	sum++;
	tree[dep].b=sum;
	int ans2=dfs(p+1,r,sum);
	if(st[p]=='|'){
		if(ans1==1){tree[dep].f1=1;
		//tree[dep].f2+=tree[tree[dep].b].f2;
		return 1;}
		else{
			tree[dep].f1+=tree[tree[dep].a].f1;
			tree[dep].f1+=tree[tree[dep].b].f1;
			tree[dep].f2+=tree[tree[dep].a].f2;
			tree[dep].f2+=tree[tree[dep].b].f2;
			if(ans2==1)return 1;
			else return 0;
		}
	}
	else{
		if(ans1==0){tree[dep].f2=1;
		//tree[dep].f1+=tree[tree[dep].b].f1;
		return 0;}
		else{
			tree[dep].f1+=tree[tree[dep].a].f1;
			tree[dep].f1+=tree[tree[dep].b].f1;
			tree[dep].f2+=tree[tree[dep].a].f2;
			tree[dep].f2+=tree[tree[dep].b].f2;
			if(ans2==1)return 1;
			else return 0;
		}
	}
}
int dfstreef1(int root){
	if(root==-1)return 0;
	if(tree[root].f1==0){
		return dfstreef1(tree[root].a)+dfstreef1(tree[root].b);
	}
	else return tree[root].f1;
}
int dfstreef2(int root){
	if(root==-1)return 0;
	if(tree[root].f2==0){
		return dfstreef2(tree[root].a)+dfstreef2(tree[root].b);
	}
	else return tree[root].f2;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>st;
	int l=strlen(st);
	sum++;
	cout<<dfs(0,l-1,sum)<<endl;
	printf("%d %d",dfstreef2(1),dfstreef1(1));
}
