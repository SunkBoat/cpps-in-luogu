#include <bits/stdc++.h>
using namespace std;
char s[1001000];
#define eof 0
bool flag;
int cnt = 0;
enum {
	sf,
	st,
	sor,
	sand,
};

vector<int> num;
vector<int> sym;
void read() {
	int p = 0;
	while (s[p] != eof) {
		if (s[p] == '1') {
			num.push_back(st);
		} else if (s[p] == '0') {
			num.push_back(sf);
		} else if (s[p] == '&') {
			sym.push_back(sand);
			flag = true;
		} else if (s[p] == '|') {
			sym.push_back(sor);
			flag = false;
		}
		p++;
	}
}

int main() {
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	scanf("%s", &s);
	read();
	int resu = num[0];
	for (auto i : num) {
		if (flag && (i == sf || resu == sf)) cnt++;
		else if (!flag && (i == st || resu == st)) cnt++;
		if (flag) resu &= i;
		else resu |= i;
	}
	printf("%d\n%d %d", resu, (flag ? cnt - 1 : 0), (!flag ? cnt - 1 : 0));
	return 0;
}
