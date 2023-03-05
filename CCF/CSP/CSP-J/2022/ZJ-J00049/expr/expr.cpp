#include<bits/stdc++.h>
using namespace std;
int andnum,ornum,flag[1000005],kuohao[1000005];
char s[1000005];
bool bo[1000005];
stack<int> st;
bool solve(int l,int r){
	for(int i=l;i<=r;i++)
		if(s[i]=='&'&&!bo[i]){
			bo[i]=true;
			if(s[i-1]==')'){
				flag[kuohao[i-1]]=solve(kuohao[i-1]+1,i-2);
				flag[i-1]=flag[kuohao[i-1]];
			}
			if(flag[i-1]==0){
				andnum++;
				flag[kuohao[i-1]]=0;
				flag[kuohao[i+1]]=0;
				flag[i-1]=0;
				flag[i+1]=0;
				int ti=kuohao[i-1];
				kuohao[kuohao[i+1]]=kuohao[i-1];
				kuohao[ti]=kuohao[i+1];
				continue;
			}
			if(s[i+1]=='('){
				flag[kuohao[i+1]]=solve(kuohao[i+1]-1,i+2);
				flag[i-1]=flag[kuohao[i-1]];
			}
			flag[kuohao[i-1]]=flag[i-1]&flag[i+1];
			flag[kuohao[i+1]]=flag[i-1]&flag[i+1];
			flag[i-1]=flag[i-1]&flag[i+1];
			flag[i+1]=flag[i-1]&flag[i+1];
			kuohao[kuohao[i+1]]=kuohao[i-1];
			kuohao[kuohao[i-1]]=kuohao[i+1];
		}
	for(int i=l;i<=r;i++)
		if(s[i]=='|'&&!bo[i]){
			bo[i]=true;
			if(s[i-1]==')'){
				flag[kuohao[i-1]]=solve(kuohao[i-1]+1,i-2);
				flag[i-1]=flag[kuohao[i-1]];
			}
			if(flag[i-1]==1){
				ornum++;
				flag[kuohao[i-1]]=1;
				flag[kuohao[i+1]]=1;
				flag[i-1]=1;
				flag[i+1]=1;
				kuohao[kuohao[i+1]]=kuohao[i-1];
				kuohao[kuohao[i-1]]=kuohao[i+1];
				continue;
			}
			if(s[i+1]=='('){
				flag[kuohao[i+1]]=solve(kuohao[i+1]-1,i+2);
				flag[i-1]=flag[kuohao[i-1]];
			}
			flag[kuohao[i-1]]=flag[i-1]|flag[i+1];
			flag[kuohao[i+1]]=flag[i-1]|flag[i+1];
			flag[i-1]=flag[i-1]|flag[i+1];
			flag[i+1]=flag[i-1]|flag[i+1];
			kuohao[kuohao[i+1]]=kuohao[i-1];
			kuohao[kuohao[i-1]]=kuohao[i+1];
		}
		
	return flag[l];
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	memset(flag,-1,sizeof(flag));
	memset(kuohao,-1,sizeof(kuohao));
	scanf("%s",s);
	int len;
	for(int i=0;true;i++)
		if(s[i]=='\0'){
			len=i-1;
			break;
		}else{
			kuohao[i]=i;
			if(s[i]=='1')flag[i]=1;
			if(s[i]=='0')flag[i]=0;
			if(s[i]=='(')st.push(i);
			if(s[i]==')'){
				int t=st.top();
				st.pop();
				kuohao[t]=i;
				kuohao[i]=t;
			}
		}
	if(solve(0,len))printf("1\n");else printf("0\n");
	printf("%d %d\n",andnum,ornum);
}
