#include<bits/stdc++.h>
using namespace std;
int a[1000100],n,num1,num2,f;
stack<char>st;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char k;
	while(1){
		st.push(getchar());
		if(st.top()=='\n'){
			st.pop();
			break;
		}
		int x=st.top()-48;
		st.pop();
		char c=st.top();
		st.pop();
		int y=st.top()-48;
		st.pop();
		if(!f&&(x==0||y==0)&&c=='&'){
//			f=1;
			num1++;
		}
		if(!f&&(y==1|x==1)&&c=='|'){
//			f=1;
			num2++;
		}
		int t=0;
		if((x==1||x==0)&&(y==1||y==0)&&(c=='|'||c=='&')){
			t=1;
			if(c=='|')st.push((y|x)+48);
			if(c=='&')st.push((y&x)+48);
		}
		if(t==0){
			st.push(char(y+48));
			st.push(c);
			st.push(char(x+48));
		}
		if(st.top()==')'){
			st.pop();
			char z=st.top();
			st.pop();
			st.pop();
			st.push(z);
		}
	}
	while(st.size()>=3){
		int x=st.top()-48;
		st.pop();
		char c=st.top();
		st.pop();
		int y=st.top()-48;
		st.pop();
		if((x==1||x==0)&&(y==1||y==0)&&(c=='|'||c=='&')){
			if(c=='|')st.push((y|x)+48);
			if(c=='&')st.push((y&x)+48);
		}
	}
	cout<<st.size()<<endl<<int(sqrt(num1))<<" "<<sqrt(num2)<<endl;
	return 0;
}
