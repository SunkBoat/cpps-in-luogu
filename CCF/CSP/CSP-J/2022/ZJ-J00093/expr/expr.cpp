#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N  = 1000000 + 5;
inline int read(){
	char ch = getchar();
	int x = 0, f = 1;
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return f * x;
}
string s, s1;
int len, ansy, ansh;
char a[N], b[N];
bool ppk;
signed main(){
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	cin >> s;
	len = s.size();
	if(len == 1){
		cout << s[0] << endl << "0 0" << endl;
		return 0;
	}
	if(len == 3){
		if(s[0] == '(') cout << s[1] << endl << "0 0" << endl;
		else{
			int pl = s[0] - '0', pr = s[2] - '0';
			if(s[1] == '&'){
				if(pl == 0) cout << 0 << endl << "1 0" << endl;
				else cout << (pl & pr) << endl << "0 0" << endl;
			}
			else{
				if(pl == 1) cout << 1 << endl << "0 1" << endl;
				else cout << (pl | pr) << endl << "0 0" << endl;
			}
		}
		return 0;
	}
	if(len == 5){
		if(s[1] == '&' && s[2] == '(' && s[4] == ')'){
			if(s[0] == '0') cout << 0 << endl << "1 0" << endl;
			else cout << s[3] << endl << "0 0" << endl;
			return 0;
		}
		if(s[1] == '|' && s[2] == '(' && s[4] == ')'){
			if(s[0] == '1') cout << 1 << endl << "0 1" << endl;
			else cout << s[3] << endl << "0 0" << endl;
			return 0;
		}
		if(s[3] == '&' && s[0] == '(' && s[2] == ')'){
			if(s[1] == '0') cout << 0 << endl << "1 0" << endl;
			else cout << s[4] << endl << "0 0" << endl;
			return 0;
		}
		if(s[3] == '|' && s[0] == '(' && s[2] == ')'){
			if(s[1] == '1') cout << 1 << endl << "0 1" << endl;
			else cout << s[4] << endl << "0 0" << endl;
			return 0;
		}
		if(s[2] == '&' && s[0] == '(' && s[4] == ')'){
			if(s[1] == '0') cout << 0 << endl << "1 0" << endl;
			else cout << s[3] << endl << "0 0" << endl;
			return 0;
		}
		if(s[2] == '|' && s[0] == '(' && s[4] == ')'){
			if(s[1] == '1') cout << 1 << endl << "0 1" << endl;
			else cout << s[3] << endl << "0 0" << endl;
			return 0;
		}
	}
	if(!ppk){
		int r = 1;
		a[1] = s[0];
		for(int i = 1; i < len; i++){
			if(s[i] == '&'){
				if(a[r] == '0') ansy++;
				else a[r] = s[i + 1];
				i++;
			}
			else a[++r] = s[i];
		}
		for(int i = 2; i <= r; i++){
			if(a[i] == '|'){
				if(a[1] == '1') ansh++;
				else a[1] = a[i + 1];
				i++;
			}
		}
		cout << a[1] << endl << ansy << ' ' << ansh << endl;
	}
	return 0;
}