#include<bits/stdc++.h>
using namespace std;
string a;
int sum,ansand,ansor;
void f(void){
	
}
void g(string a){
	int c=a[0]-'0',d=a[2]-'0';
		if (a[1]== '|'){
			sum=c|d;
			if(c) ansor++;
		}
		else {
			sum=c&d;
			if(!c) ansand++;
		}
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin >> a;
	int la =a.length();
	if(la==3){
		g(a);
	}
	else if(la==5){
		if(a[1]=='|' and a[3]=='&') 1;
	}
	cout << sum << endl << ansand << ' ' << ansor ;
	return 0;
}

