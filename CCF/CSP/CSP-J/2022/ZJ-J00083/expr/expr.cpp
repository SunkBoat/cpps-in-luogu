#include<bits/stdc++.h>
using namespace std;//30
const int maxn = 1e6+10;
char s[maxn],sta[maxn];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s+1;
	int ls = strlen(s+1);
//s<=5
	if(ls<=3){//10
		if(s[1]=='(' || s[1] ==')'){
			if(s[2]=='(' || s[2] ==')'){
				printf("%c\n0 0",s[3]);
			}
			else{
				printf("%c\n0 0",s[2]);
			}
		}
		else if(s[3]=='(' || s[3] ==')'){
				if(s[2]=='(' || s[2] ==')'){
					printf("%c\n0 0",s[1]);
				}
				else{
					printf("%c\n0 0",s[2]);
				}
		}
		else{
			if(s[2] == '&'){
				if(s[1] == '0')	printf("0\n1 0");
				if(s[1] == '1'&&s[3]=='0')	printf("0\n0 0");
				if(s[1] == '1'&&s[3]=='1')	printf("1\n0 0");
			}
			if(s[2] == '|'){
				if(s[1] == '1')	printf("1\n0 1");
				if(s[1] == '0'&&s[3]=='0')	printf("0\n0 0");
				if(s[1] == '0'&&s[3]=='1')	printf("1\n0 0");
			}		
		}
	}
	//3
	else{	
		int l3 = 1,ans31 = 0,ans32 = 0,ans33 = 0;
		while(l3<=ls){	
			int flag3 = 1,top = 0;
			while(s[l3] != '|' && l3<=ls){
				if(s[l3] == '0')	flag3 = 0;
				if(flag3 == 0 && s[l3] == '&')	ans32++;
				sta[++top] = s[l3];
				l3++;		
			}
			if(flag3){
				ans31 = 1;//只要有1个1最终结果为1
				for(int i = l3;i<=ls;i++){
					if(s[i] == '|')	ans33++;
				}
				break;
			} 
			l3++;
		} 
		printf("%d\n%d %d",ans31,ans32,ans33);
		return 0;
	}
	return 0;
}
/*
0|1&0|0&1&0&1&0|1
1
4 0

0|1&0|1|1|1|1&0&1&1|0|0|1|0&0
1
0 7
*/
