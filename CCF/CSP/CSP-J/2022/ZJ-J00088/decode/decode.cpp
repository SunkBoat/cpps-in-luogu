#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k;
ll n, d, e, len = 0, yin[1000010], a[2020], b[2020], ansa[2020], ansb[2020], anslena, anslenb;
void quickcin(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void yinshu(ll pre){
	if(pre == 1) len = 1, yin[1] = 1;
	if(pre == 2) len = 2, yin[1] = 1, yin[2] = 2;
	for(int i = 1; i <= sqrt(pre); ++i){
		if(pre % i == 0 && i == sqrt(pre)){
			len++, yin[len] = i;
			break;
		}
		if(pre % i == 0){
			len++;
			yin[len] = i;
			len++;
			yin[len] = pre / i;
		}
	}
}
int gaojing1(ll stra, ll strb){
	memset(ansa, 0, sizeof(ansa));
	ll lena = 0, lenb = 0;
	while(stra){
		lena++;
		a[lena] = stra % 10;
		stra /= 10;
	}
	while(strb){
		lenb++;
		b[lenb] = strb % 10;
		strb /= 10;
	}
	ansa[1] = 1;
	for(ll i = 1; i <= lena; ++i){
		for(ll j = 1; j <= lenb; ++j)
			ansa[i + j - 1] += a[i] * b[j];
		for(ll j = 1; j <= lena + lenb; ++j){
			if(ansa[j] >= 10){
				ansa[j + 1] += ansa[j] / 10;
				ansa[j] = ansa[j] % 10;
			}
		}
	}
	for(int i = 1; i <= lena + lenb + 1; ++i)
		if(ansa[i])
			anslena = i;
	return 0;
}
int gaojing2(ll stra, ll strb){
	memset(ansb, 0, sizeof(ansb));
	ll lena = 0, lenb = 0;
	while(stra){
		lena++;
		a[lena] = stra % 10;
		stra /= 10;
	}
	while(strb){
		lenb++;
		b[lenb] = strb % 10;
		strb /= 10;
	}
	for(ll i = 1; i <= lena; ++i){
		for(ll j = 1; j <= lenb; ++j)
			ansb[i + j - 1] += a[i] * b[j];
		for(ll j = 1; j <= lena + lenb; ++j){
			if(ansb[j] >= 10){
				ansb[j + 1] += ansb[j] / 10;
				ansb[j] = ansb[j] % 10;
			}
		}
	}
	for(int i = 1; i <= lena + lenb + 1; ++i)
		if(ansb[i])
			anslenb = i;
	return 0;
}
int main(){
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);
	quickcin();
	cin >> k;
	while(k--){
		memset(yin, 0, sizeof(yin));
		cin >> n >> d >> e;
		yinshu(n);
		ll ansflag = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		gaojing2(d, e);
		for(int i = 1; i <= len; i += 2){
			int j;
			if(i == len) j = len;
			else j = i + 1;
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			gaojing1(yin[i] - 1, yin[j] - 1);
			if(anslena != anslenb) continue;
			else{
				ll flag = 1;
				for(int k = 1; k <= anslena; ++k){
					if(ansa[k] != ansb[k]){
						flag = 0;
						break;
					}
				}
				if(flag){
					cout << min(yin[i], yin[j]) << " " << max(yin[i], yin[j]) << endl;
					i = len + 1, j = len + 1;
					ansflag = 1;
					break;
				}
			}
		}
		if(!ansflag) cout << "NO" << endl;
	}
	return 0;
}