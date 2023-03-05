#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
#define xi first
#define yi second

int N, K, Ans;
pair<int, int> Point[510];
map<pair<int, int>, bool> Mp;
map<pair<int, int>, int> Ans1, Ans2;
vector<int> G[MAXN];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void f(int &a, int b) {
	a = max(a, b);
}

bool used[15];
int A[15];

int Calc() {
	int res = 1;
	for (int i = 2; i <= N; i++) {
		if (abs(Point[A[i]].xi - Point[A[i - 1]].xi) + abs(Point[A[i]].yi - Point[A[i - 1]].yi) == 1) res++;
		else break;
	}
	return res;
}

void DFS(int Now) {
	if (Now == N + 1) {
		Ans = max(Ans, Calc());
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (used[i] == false) {
			used[i] = true;
			A[Now] = i;
			DFS(Now + 1);
			used[i] = false;
		}
	}
}

int main() {
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);
	scanf("%d %d" ,&N ,&K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d" ,&Point[i].xi ,&Point[i].yi);
		Mp[Point[i]] = i;
		Ans1[Point[i]] = 1;
		Ans2[Point[i]] = 1;
		A[i] = i;
	}
	sort(Point + 1, Point + 1 + N);
	if (N <= 10) {
		DFS(1);
		cout << Ans << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) {
		int X, Y;
		tie(X, Y) = Point[i];
		if (Mp[{X - 1, Y}]) {
			f(Ans1[Point[i]], Ans1[make_pair(X - 1, Y)] + 1);
		}
		if (Mp[{X, Y - 1}]) {
			f(Ans1[Point[i]], Ans1[make_pair(X, Y - 1)] + 1);
		}
		Ans = max(Ans, Ans1[Point[i]]);
	}
	cout << Ans << endl;	
	return 0;
}
