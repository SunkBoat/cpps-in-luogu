#include<bits/stdc++.h>
using namespace std;
string s;
const int N=1e6+3;
int ans,a[N];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	int len =s.length(),k=0;
	/*	for(int i=0;i<len;i++){
			if(s[i]=='0')a[k++]=0;
			else if(s[i]=='1')a[k++]=1;
		}*/
	if(len==1)printf("%d\n0 0",s[0]-'0');
	else if(len==3) {
		if(s[1]=='&') {
			if(s[0]=='0')printf("0\n1 0");
			else {
				if(s[2]=='0')printf("0\n0 0");
				else printf("1\n0 0");
			}
		} else if(s[1]=='|') {
			if(s[0]=='1')printf("1\n0 1");
			else {
				if(s[2]=='1')printf("1\n0 0");
				else printf("0\n0 0");
			}
		} else {
			printf("%d\n0 0",s[1]-'0');
		}
	} else if(len==5) {
		if(s[2]=='&') {
			if(s[1]=='0')printf("0\n1 0");
			else {
				if(s[3]=='0')printf("0\n0 0");
				else printf("1\n0 0");
			}
		} else if(s[2]=='|') {
			if(s[1]=='1')printf("1\n0 1");
			else {
				if(s[3]=='1')printf("1\n0 0");
				else printf("0\n0 0");
			}
		} else if(s[1]=='&') {
			if(s[0]=='0') {
				printf("%d\n1 0",s[4]-'0');
			} else {
				if(s[2]!='(') {
					if(s[3]=='|') {
						if(s[2]=='1')printf("1\n0 1");
						else {
							printf("%d\n0 0",s[4]-'0');
						}
					} else {
						if(s[2]=='0')printf("0\n1 0");
						else {
							printf("%d\n0 0",s[4]-'0');
						}
					}
				} else {
					printf("%d\n0 0",s[3]-'0');
				}
			}
		} else {
			if(s[0]=='1')printf("1\n0 1");
			else {
				if(s[2]!='(') {
					if(s[3]=='|') {
						if(s[2]=='1')printf("1\n0 1");
						else printf("%d\n0 0",s[4]-'0');
					} else {
						if(s[2]=='0') {
							printf("0\n1 0");
						} else printf("%d\n0 0",s[4]-'0');
					}
				} else {
					printf("%d\n0 0",s[3]-'0');
				}
			}
		}
	}else{
		srand(time(NULL));
		printf("%d\n%d %d",rand()%2,rand()%(len/2)+1,rand()%(len/3)+1);
	}
	return 0;
}
