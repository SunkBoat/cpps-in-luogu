// CSP-J 2022 T3 expr
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, cnt[5];
char s[N];
int av = 0;
stack <int> stk1, stk2;
void add (char ch) {
	if (ch == '(') {
		stk2.push (3);
	}
	if (ch == ')') {
		while (!stk2.empty ()) {
			int opt = stk2.top ();
			stk2.pop ();
			if (opt == 3) {
				break;
			}
			if (opt == 1) {
				int b = stk1.top ();
				stk1.pop ();
				int a = stk1.top ();
				stk1.pop ();
				if (a == 0) {
					av--;
				}
				stk1.push (a & b);
			}
			if (opt == 2) {
				int b = stk1.top ();
				stk1.pop ();
				int a = stk1.top ();
				stk1.pop ();
				if (a == 1) {
					av--;
				}
				stk1.push (a | b);
			}
		}
	}
	if (ch == '0' || ch == '1') {
		stk1.push (ch - '0');
	}
	if (ch == '&' || ch == '|') {
		int op = 0;
		if (ch == '&') {
			op = 1;
		} else {
			op = 2;
		}
		while (!stk2.empty ()) {
			if (stk2.top () > op) {
				break;
			}
			int opt = stk2.top ();
			stk2.pop ();
			if (opt == 1) {
				int b = stk1.top ();
				stk1.pop ();
				int a = stk1.top ();
				stk1.pop ();
				if (a == 0) {
					av--;
				}
				stk1.push (a & b);
			}
			if (opt == 2) {
				int b = stk1.top ();
				stk1.pop ();
				int a = stk1.top ();
				stk1.pop ();
				if (a == 1) {
					av--;
				}
				stk1.push (a | b);
			}
		}
		if ((op - 1) ^ stk1.top () == 0) {
			cnt[op] += (av == 0);
			av++;
		}
		stk2.push (op);
	}
}
int main () {
	freopen ("expr.in", "r", stdin);
	freopen ("expr.out", "w", stdout);
	scanf ("%s", s + 1);
	n = strlen (s + 1);
	add ('(');
	for (int i = 1; i <= n; i++) {
		add (s[i]);
	}
	add (')');
	printf ("%d\n%d %d\n", stk1.top (), cnt[1], cnt[2]);
	return 0;
}
