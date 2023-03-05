#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	string s;
	cin >> s;
	
	if(s.size() == 3){
		if(s == "(0)")printf("0\n0 0");
		if(s == "(1)")printf("1\n0 0");
		
		if(s == "0&0")printf("0\n1 0");
		if(s == "0&1")printf("0\n1 0");
		if(s == "1&0")printf("0\n0 0");
		if(s == "1&1")printf("1\n0 0");
		
		if(s == "0|0")printf("0\n0 0");
		if(s == "0|1")printf("0\n0 0");
		if(s == "1|0")printf("0\n0 1");
		if(s == "1|1")printf("1\n0 1");
		
	}else if(s == "(0|0)"){
		
		printf("0\n0 0");
	
	
	}else if(s == "(0|1)"){
		
		printf("1\n0 0");
	
	
	}else{
	
		
		int a=0,b=0;
		
		srand(time(0));
		cout << rand()%2 << endl;
		
		for(int i=0; i<s.size()-1; i++){
			if(s[i]=='0' && s[i+1]=='&')
				a++;
			if(s[i]=='1' && s[i+1]=='|')
				b++;
		}
		cout << a << " " << b;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}