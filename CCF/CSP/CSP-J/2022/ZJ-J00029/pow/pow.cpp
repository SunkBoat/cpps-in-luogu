#include<bits/stdc++.h>
using namespace std;
string chengfa(string x,string y) {

	int ans[20001];

	for(int i=0; i<20001; i++) ans[i]=0;

	for(int i=x.size()-1; i>=0; i--) {
		for(int j=y.size()-1; j>=0; j--) {

			ans[(x.size()-1-i)+(y.size()-1-j)] += int(x[i]-'0') * int(y[j]-'0');

			int k = (x.size()-1-i)+(y.size()-1-j);

			while(ans[k]>9) {
				ans[k+1] += ans[k]/10;
				ans[k] %= 10;

				k++;
			}


		}
	}

	string re="";

	int i=20000;

	while(ans[i] == 0) {

		i--;

	}

	while(i >= 0) {

		re += char(ans[i]+'0');

		i--;
	}

	return re;


}
int main() {
	freopen("pow.in","r",stdin);
	freopen("pow.out","w",stdout);



	string s1;
	long long s2;

	cin >> s1 >> s2;

	string ans="1";

	for(int i=0; i<s2; i++) {
		ans = chengfa(ans,s1);

		if(ans.size() > 9 && ans!="1000000000") {
			cout << -1;
			fclose(stdin);
			fclose(stdout);
			return 0;

		}
	}

	cout << ans;






	fclose(stdin);
	fclose(stdout);
	return 0;
}