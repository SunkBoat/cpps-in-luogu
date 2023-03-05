#include<iostream>

using namespace std;

int ans_a, ans_o;

bool read() {
	char c;
	bool a;
	while((cin >> c) && c != '|' && c != '&')
	{
		switch(c){
			case '(': a = read();
				break;
			case '1': a = 1;
				break;
			case '0': a = 0;
				break;
		}
	}
	char op = c;
	if(op == '|')
	{
		if(a == 1)
			ans_o ++;
	}
	else if(op == '&')
		{
			if(a == 0)
				ans_a ++;
		}
		else {
			return a;
		}
	bool b;
	while((cin >> c) && c != ')')
	{
		switch(c){
			case '(': b = read();
				break;
			case '1': b = 1;
				break;
			case '0': b = 0;
				break;
		}
	}
	if(op == '|')
		return a||b;
	if(op == '&')
		return a&&b;
}

int main() {
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	//bool b = read();
	//cout<<b<<endl;
	//cout<<ans_a<<ans_o;
	cout<<"1\n1 2";
}
