#include <stdio.h>
#define LL long long

int main(){
	int k;
	LL n,e,d,p,q;
	FILE *fin,*fout;
	fin=fopen("decode.in","r");
	fout=fopen("decode.out","w");
	fscanf(fin,"%d",&k);
	for(int t=0;t<k;t++){
		fscanf(fin,"%lld%lld%lld",&n,&d,&e);
		if(e*d>n){
			fprintf(fout,"NO\n");
			continue;
		}
		p=q=-1;
		for(LL i=1;i*i<=n;i++){
			if(n%i==0){
				if(n-i-n/i+2==e*d){
					p=i;q=n/i;break;
				}
			}
		}
		if(p!=-1){
			fprintf(fout,"%lld %lld\n",p,q);
		}
		else{
			fprintf(fout,"NO\n");
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}