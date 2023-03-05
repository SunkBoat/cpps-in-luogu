#include<bits/stdc++.h>
using namespace std;
string s,s1;
int n,m,r,k,num[1000005],ch[1000005],rr,x,y,now;
int main () {
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	s='('+s+')';
	ch[0]=-1;
	for (int i=0;i<s.length();i++) {
		if (s[i]=='0') num[++r]=0;     
		if (s[i]=='1') num[++r]=1;
		if (s[i]=='|') {
			if (ch[rr]==2) {
				x=rr,y=r-1;
				while (ch[x]==2) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==0) {
						n+=r-j;
						num[y]=0;
						break;
					}
					else num[y]&=num[j+1];
				}
				r=y,rr=x-1;
			}
			if (ch[rr]==1) {
				x=rr,y=r-1;
				while (ch[x]==1) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==1) {
						m+=r-j;
						num[y]=1;
						break;
					}
					else num[y]|=num[j+1];
				}
				r=y,rr=x-1;
			}
			ch[++rr]=1;
		}
		if (s[i]=='&') {
			if (ch[rr]==2) {
				x=rr,y=r-1;
				while (ch[x]==2) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==0) {
						n+=r-j;
						num[y]=0;
						break;
					}
					else num[y]&=num[j+1];
				}
				r=y,rr=x-1;
			}
			ch[++rr]=2;
		}
		if (s[i]=='(') {
			now=ch[rr],rr--;
			if (ch[rr]==2) {
				x=rr,y=r-1;
				while (ch[x]==2) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==0) {
						n+=r-j;
						num[y]=0;
						break;
					}
					else num[y]&=num[j+1];
				}
				r=y,rr=x-1;
			}
			if (ch[rr]==1) {
				x=rr,y=r-1;
				while (ch[x]==1) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==1) {
						m+=r-j;
						num[y]=1;
						break;
					}
					else num[y]|=num[j+1];
				}
				r=y,rr=x-1;
			}
			ch[++rr]=now;
			if (ch[rr]==2&&num[r]==0) {
				while (s[i]!=')') i++;
				n++,rr--;
				continue;
			}
			if (ch[rr]==1&&num[r]==1) {
				while (s[i]!=')') i++;
				m++,rr--;
				continue;
			}
			ch[++rr]=0;
		}
		if (s[i]==')') {
			if (ch[rr]==2) {
				x=rr,y=r-1;
				while (ch[x]==2) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==0) {
						n+=r-j;
						num[y]=0;
						break;
					}
					else num[y]&=num[j+1];
				}
				r=y,rr=x-1;
			}
			if (ch[rr]==1) {
				x=rr,y=r-1;
				while (ch[x]==1) x--,y--;
				x++;
				for (int j=y;j<r;j++) {
					if (num[j]==1) {
						m+=r-j;
						num[y]=1;
						break;
					}
					else num[y]|=num[j+1];
				}
				r=y,rr=x-1;
			}
			rr--;
		}
	}
	cout<<num[r]<<endl<<n<<" "<<m;
	return 0;
}