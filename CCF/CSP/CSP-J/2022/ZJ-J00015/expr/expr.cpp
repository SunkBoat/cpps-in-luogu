#include <stdio.h>
#define MAXL 1000010

char s[MAXL];
int qn[MAXL];
char qo[MAXL];
int dy,dh;

int quan(char op){
	if(op=='\0')return 4;
	if(op=='('||op==')')return 3;
	if(op=='&')return 2;
	if(op=='|')return 1;
	return -100;
}

int cal(int x1,int x2,char op){
	if(op=='&'){
		return x1&x2;
	}
	else if(op=='|'){
		return x1|x2;
	}
	else if(op=='\0'){
		return x1;
	}
}

int main(){
	FILE *fin,*fout;
	fin=fopen("expr.in","r");
	fout=fopen("expr.out","w");
	fscanf(fin,"%s",s);
	int len,x1,x2,qnt=0,qot=1;
	qo[1]='\0';
	dy=dh=0;
	for(len=0;s[len];len++);
	if(len==1){
		fprintf(fout,"%d\n0 0\n",s[0]-'0');
		return 0;
	}
	for(int i=0;i<=len;i++){
		if(s[i]=='0'||s[i]=='1'){
			qn[++qnt]=s[i]-'0';
			if(s[i]=='0'&&s[i+1]=='&'){
				while(s[i+1]=='&'&&i<=len){
					int j,kh=0;
					for(j=i+2;j<=len;j++){
						if(s[j]=='(')kh++;
						if(s[j]==')')kh--;
						if(kh==0)break;
					}
					i=j;
					dy++;
				}
			}
			else if(s[i]=='1'&&s[i+1]=='|'){
				while(s[i+1]=='|'&&i<=len){
					int j,kh=0;
					for(j=i+2;j<=len;j++){
						if(s[j]=='(')kh++;
						if(s[j]==')')kh--;
						if(kh==0)break;
					}
					i=j;
					dh++;
				}
			}
		}
		else{
			if(quan(s[i])==-100)continue;
			if(s[i]==')'){
				qot--;
			}
			else if(quan(s[i])>=quan(qo[qot])&&s[i]!='('){
				x1=qn[qnt-1];
				x2=qn[qnt];
				qnt-=1;
				qn[qnt]=cal(x1,x2,qo[qot]);
				qo[qot]=s[i];
			}
			else if(quan(s[i])<quan(qo[qot])){
				qo[++qot]=s[i];
			}
		}
	}
	fprintf(fout,"%d\n%d %d\n",qn[qnt],dy,dh);
	fclose(fin);
	fclose(fout);
	return 0;
}