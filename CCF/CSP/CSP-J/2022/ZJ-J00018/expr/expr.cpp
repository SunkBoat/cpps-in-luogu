#include<iostream>
using namespace std;
int np=0;
string s;
int ans_1=0,ans_2=0;
int n;
char calculate(int pos){
	char a[100005],b[100005];
	int now=0;
	for(int i=pos;i<n&&s[i]!=')';i++){
		np=i;
		if(s[i]=='&'||s[i]=='|'){
			a[now]=s[i];
			now++;
		}
		if(s[i]=='1'||s[i]=='0'){
			a[now]=s[i];
			now++;
		}
		if(s[i]=='('){
			a[now]=calculate(i+1);
			i=np;
			now++;
		}
		//cout<<i<<" "<<s[i]<<" "<<now-1<<" "<<a[now-1]<<endl;
	}
	//cout<<"great!!"<<endl;
	int nowb=0;
	for(int i=0;i<now;i++){
		if(a[i]=='1'||a[i]=='0'){
			if(a[i+1]=='&'){
				if(a[i]=='0'){
					b[nowb]='0';
					ans_1++;
				}
				else{
					if(a[i+2]=='1'){
						b[nowb]='1';
					}
					else{
						b[nowb]='0';
					}
				}
				continue;
			}
		}
		b[nowb]=a[i];
		nowb++;
	}
	int ans=b[0]-'0';
	for(int i=2;i<nowb;i+=2){
		if(ans==1){
			ans_2++;
			break;
		}
		ans=ans|(b[i]-'0');
		//cout<<ans<<" ";
	}
	np++;
	return '0'+ans;
}
int main(){
	//freopen("expr2.in","r",stdin);
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	n=s.size();
	cout<<calculate(0)<<endl;
	cout<<ans_1<<" "<<ans_2;
	return 0;
}
/*
0&(1|0)|(1|1|1&0) 0 0
0&1|(1|1|1&0) 	  1 0
0&1|(1|1|0)       1 0
0&1|1             1 1
1|1 			  1 1
1 				  1 2
*/