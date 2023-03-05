#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2;
string c;
int ans1,ans2;
int solve(string c) {
	deque<int> d;
	int cnt=0,cnt2=0;
	int len=c.size();
	for(int i=0; i<len; ++i) {
		if(c[i]=='(') {
			int j=i;
			while(c[j]!=')')j++;
			d.push_back(solve(c.substr(i+1,j-1-i)));
			i=j;
		}
		if(c[i]=='|') {
			for(int i=1; i<=cnt2; ++i) {
				int a=d.back();
				d.pop_back();
				int b=d.back();
				d.pop_back();
				if(!b)ans1++;
				d.push_back(a|b);
			}
			cnt2=0;
			cnt++;
		}
		if(isdigit(c[i])) {
			d.push_back(c[i]-'0');
		}
		if(c[i]=='&')cnt2++;
	}
	for(int i=1; i<=cnt; ++i) {
		int a=d.front();
		d.pop_front();
		int b=d.front();
		d.pop_front();
		if(a)ans2++;
		d.push_front(a|b);
	}
	return d.front();
}
signed main() {
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>c;
	deque<int> d;
	int cnt=0,cnt2=0;
	int len=c.size();
	for(int i=0; i<len; ++i) {
		if(c[i]=='(') {
			int j=i;
			while(c[j]!=')')j++;
			d.push_back(solve(c.substr(i+1,j-1-i)));
			i=j;
		}
		if(c[i]=='|') {
			for(int i=1; i<=cnt2; ++i) {
				int a=d.back();
				d.pop_back();
				int b=d.back();
				d.pop_back();
				if(!b)ans1++;
				d.push_back(a|b);
			}
			cnt2=0;
			cnt++;
		}
		if(isdigit(c[i])) {
			d.push_back(c[i]-'0');
		}
		if(c[i]=='&')cnt2++;
	}
	for(int i=1; i<=cnt; ++i) {
		int a=d.front();
		d.pop_front();
		int b=d.front();
		d.pop_front();
		if(a)ans2++;
		d.push_front(a|b);
	}
	printf("%d\n%d %d",d.front(),ans1,ans2);
}
