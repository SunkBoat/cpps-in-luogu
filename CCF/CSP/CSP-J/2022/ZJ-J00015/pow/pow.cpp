#include <stdio.h>
#define LL long long

LL kasumi(LL a,LL n){
	LL res=1;
	while(n){
		if(a>(LL)(1e9)){
			return -1;
		}
		if(n&1){
			res*=a;
			if(res>(LL)(1e9)){
				return -1;
			}
		}
		n/=2;a*=a;
	}	
	return res;
}

int main(){
	LL a,b;
	FILE *fin,*fout;
	fin=fopen("pow.in","r");
	fout=fopen("pow.out","w");
	fscanf(fin,"%lld%lld",&a,&b);
	fprintf(fout,"%lld\n",kasumi(a,b));
	fclose(fin);
	fclose(fout);
	return 0;
}