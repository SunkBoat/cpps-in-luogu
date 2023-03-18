#include <bits/stdc++.h>
using namespace std;
string a, b;
int tp[2000010];
//pair<int, int> k[1000010];
//int cnt = 0;
int yh[2];//0& 1|
stack <int> ss;
//bool f(int l, int r){
//	cout << l << " " << r << endl;
//	if(l == r) return (b[l] - '0');
//
//	for(int i = l; i <= r; i++){
//		if(a[i] == '(')	i = tp[i] + 1;
//		if(a[i] == '&'){
//			int f1 = 0, f2 = 0, t1 = 0, t2 = 0;
//			if(b[i - 1] == ')') f1 = 1, t1 = tp[i - 1];
//			if(b[i + 1] == '(') f2 = 1, t2 = tp[i + 1];
//			if((f1 ? f(t1 + 1, i - 2) : f(i - 1, i - 1)) == 0){
//				yh[0]++;
//				return 0;
//			}
//			return 1 & (f2 ? f(i + 2, t2 - 1) : f(i + 1, i + 1));
//		}
//	}
//	for(int i = l; i <= r; i++){
//		if(b[i] == '(')	i = tp[i] + 1;
//		//if(i > r) continue;
//		if(a[i] == '|'){
//			int f1 = 0, f2 = 0, t1 = 0, t2 = 0;
//			if(b[i - 1] == ')') f1 = 1, t1 = tp[i - 1];
//			if(b[i + 1] == '(') f2 = 1, t2 = tp[i + 1];
//			if((f1 ? f(t1 + 1, i - 2) : f(i - 1, i - 1)) == 1){
//				yh[1]++;
//				return 0;
//			}
//			return 1 | (f2 ? f(i + 2, t2 - 1) : f(i + 1, i + 1));
//		}
////		if(b[i] == '|'){
////			int f1 = 0, f2 = 0;
////			if(b[i - 1] == ')' && b[l] == '(') f1 = 1;
////			if(b[i + 1] == '(' && b[r] == ')') f2 = 1;
////			if(f(l + f1, i - 1 - f1) == 1){
////				yh[1]++;
////				return 0;
////			}
////			return 0 | f(i + 1 + f2, r - f2);
////		}
//	}
//	return 0;
//}

void succ(int l, int r){
	if(l == r) return;
//	cout << b << endl;
//	for(int i = l; i <= r; i++){
//		if(b[i] == '(') succ(i + 1, tp[i] - 1), i = tp[i] + 1;
//	}
	for(int i = l; i <= r; i++){
		if(b[i] == '&'){
			bool f1 = 0, f2 = 0, t1 = 0, t2 = 0;
			if(b[i - 1] == ')') f1 = 1, t1 = tp[i - 1];
			if(b[i + 1] == '(') f2 = 1, t2 = tp[i + 1];
			if(f1) succ(t1, i - 2);
			else succ(i - 1, i - 1);
			if(f2) succ(i + 1 + f2, r - f2);
			else succ(i + 1, i + 1);
			b.erase(i + b.begin());
			b.insert(r + b.begin(), '&');
			//return;
		}

	}
	for(int i = l; i <= r; i++){
		if(b[i] == '|'){
			bool f1 = 0, f2 = 0;
			if(b[l] == '(' && b[i - 1] == ')') f1 = 1;
			if(b[i + 1] == '(' && b[r] == ')') f2 = 1;
			succ(l + f1, i - 1 - f1); succ(i + 1 + f2, r - f2);
			b.erase(i + b.begin());
			b.insert(r + b.begin(), '|');
			return;
		}
//		if(b[i] == '|') succ(l, i - 1), succ(i + 1, r);
//		b.erase(i + b.begin());
//		b.insert(r + b.begin(), '|');
//		return;
	}
}
int main(){
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	cin >> a;
	int n = a.size();
	if (n == 1){
		if (a == "1") cout << 1 << endl << 0 << " " << 0 << endl;
		if (a == "0") cout << 0 << endl << 0 << " " << 0 << endl;
	}
	if (n == 3){
		if (a == "1|1") cout << 1 << endl << 0 << " " << 1 << endl;
		if (a == "0|1") cout << 1 << endl << 0 << " " << 0 << endl;
		if (a == "0|0") cout << 0 << endl << 0 << " " << 0 << endl;
		if (a == "1|0") cout << 1 << endl << 0 << " " << 1 << endl;
		if (a == "1&1") cout << 1 << endl << 0 << " " << 0 << endl;
		if (a == "1&0") cout << 0 << endl << 0 << " " << 0 << endl;
		if (a == "0&1") cout << 0 << endl << 1 << " " << 0 << endl;
		if (a == "0&0") cout << 0 << endl << 1 << " " << 0 << endl;
		if (a == "(1)") cout << 1 << endl << 0 << " " << 0 << endl;
		if (a == "(0)") cout << 0 << endl << 0 << " " << 0 << endl;
	}
	b = a;
	for(int i = 0; i < b.size(); i++){
		if(b[i] == '&'){
			if(b[i - 1] == ')'){
				int cnt = 1;
				for(int j = i - 2; j >= 0; j--){
					if(b[j] == ')') cnt++;
					if(b[j] == '(') cnt--;
					if(cnt == 0){
						b.insert(j + b.begin(), '(');
						break;
					}
				}
			}else b.insert(i - 1 + b.begin(), '(');
			i++;
			if(b[i + 1] == '('){
				int cnt = 1;
				for(int j = i + 2; j < b.size(); j++){
					if(b[j] == '(') cnt++;
					if(b[j] == ')') cnt--;
					if(cnt == 0){
						b.insert(j + 1 + b.begin(), ')');
						break;
					}
				}
			}else b.insert(i + 2 + b.begin(), ')');
			i++;
		}
	}
//	cout << b << endl;
	cout << b << endl;
	for(int i = 0; i < b.size(); i++){
		if(b[i] == '(') ss.push(i);
		if(b[i] == ')') {
			tp[ss.top()] = i;
			tp[i] = ss.top();
			ss.pop();
		}
	}
//	b = a;
//	cout << b << endl;
	succ(0, n - 1);
	cout << b << endl;
	//cout << f(0, b.size() - 1) << endl << yh[0] << " " << yh[1] << endl;
	


	return 0;

}

