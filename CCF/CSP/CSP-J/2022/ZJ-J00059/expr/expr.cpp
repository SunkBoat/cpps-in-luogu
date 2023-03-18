#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m,x,y,z,len,sumor,sumand;
bool ans;
string s;
int go(int now)
{
	int i=now,left=0,right=0;
	if (s[i]=='(') left++;
	if (s[i]==')') right++;
	while (left!=right) 
	  {
	  	i--;
	  	if (s[i]=='(') left++;
	  	if (s[i]==')') right++;
	  }
	return i;
}
bool work(int l,int r)
{
    int tmp=go(r);
    bool flag;
    if (s[l]=='('&&s[r]==')'&&tmp==l) return work(l+1,r-1);
    if (l==tmp&&r==tmp) 
	  {
	  	if (s[l]=='0') return false; else return true;
	  }
    if (s[tmp-1]=='&') 
	  {
	  	int num=go(tmp-2);
	  	while ((s[num-1]=='&')&&num!=l) num=go(num-2);
	  	if (num==l) 
		  {
		  	flag=work(l,tmp-2);
		  	if (flag==false)
		  	  {
		  	  	sumand++;
		  	  	return false;
			  }
		  	else
			  return (flag&&work(tmp,r)); 
		  }
		else 
		  {
		  	flag=work(l,num-2);
		  	if (flag==true)
		  	  {
		  	  	sumor++;
		  	  	return true;
			  }
			else
			  return (flag||work(num,r));
		  }
	  } 
	else 
	  {
	  	flag=work(l,tmp-2);
	  	if (flag==true)
	  	  {
	  	  	sumor++;
	  	  	return true;
		  }
		else
		  return (flag||work(tmp,r));
	  }  
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    getline(cin,s);
    len=s.size();
    sumor=0;
    sumand=0;
    ans=work(0,len-1);
    if (ans==false) printf("0\n"); else printf("1\n");
    printf("%d %d",sumand,sumor);
	return 0;
} 
