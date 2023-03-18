#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, k, m = 1;
int sum = 1;
int ans[505];
struct node{
	int x;
	int y;
	int p;
};
node temp[505];
int main(){
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> temp[i].x >> temp[i].y;
	}
	for(int i = 0; i < n; i++){
		if(temp[i].p == 0){
			temp[i].p = m;
			m++;
		}
		for(int j = 0; j < n; j++){
			if(abs(temp[i].x - temp[j].x) + abs(temp[i].y - temp[j].y) == 1){
				temp[j].p = temp[i].p;
			}
		}
	}
	for(int i = 0; i < n; i++){
		ans[temp[i].p]++;
	}
	for(int i = 1; i <= m; i++){
		sum = max(sum, ans[i]);
	}
	cout << sum + k;;
	return 0;
}