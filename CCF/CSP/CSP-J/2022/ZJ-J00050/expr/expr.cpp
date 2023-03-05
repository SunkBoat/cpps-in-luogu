#include <bits/stdc++.h>
using namespace std;

string S;

void read(string &s) {
	s = "";
	char c = getchar();
	while (c != '\n') {
		s.push_back(c);
		c = getchar();
	}
}

int Len;
bool Flag1, Flag2, Flag3;
int Ans = -1, Ans1 = 0, Ans2 = 0;

int main() {
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	read(S);
	Len = S.size();
	if (Len <= 3) {
		if (S == "1&1" || S == "1" || S == "1|0" || S == "0|1" || S == "1|1") {
			printf("1\n0 0\n");
		} else {
			printf("0\n0 0\n");
		}
		return 0;
	}
	if (Len <= 5) {
		if (S[1] == '|' && S[3] == '|') {
			if (S[0] == '1') {
				printf("1\n0 2\n");
			}
			else if (S[2] == '1') {
				printf("1\n0 1\n");
			}
			else if (S[4] == '1') {
				printf("1\n0 0\n");
			}
			else {
				printf("0\n0 0\n");
			}
		} else if (S[1] == '|' && S[3] == '&') {
			int Ans = 0, Ans1 = 0, Ans2 = 0;
			Ans = ((S[2] == '1' && S[4] == '1') || (S[0] == '1'));
			if (S[0] == '0') Ans1 = S[0] == '1';
			Ans2 = S[0] == '1';
			cout << Ans << endl << Ans1 << " " << Ans2 << endl;
		} else if (S[1] == '&' && S[3] == '|') {
			int Ans = 0, Ans1 = 0, Ans2 = 0;
			Ans = ((S[0] == '1' && S[2] == '1') || (S[4] == '1'));
			Ans1 = S[0] == '0';
			Ans2 = (S[0] == '1' && S[2] == '1');
			cout << Ans << endl << Ans1 << " " << Ans2 << endl;
		} else {
			if (S[0] == '0') {
				printf("0\n0 2\n");
			}
			else if (S[2] == '0') {
				printf("0\n0 1\n");
			}
			else if (S[4] == '0') {
				printf("0\n0 0\n");
			}
			else {
				printf("1\n0 0\n");
			}
		}
	}
	return 0;
}
