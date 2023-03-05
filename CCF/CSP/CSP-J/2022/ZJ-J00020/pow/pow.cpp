#include<cstdio>

using namespace std;

int main() {
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	
	int a, b;
	scanf("%d%d", &a, &b);
	if(a == 1)
	{
		printf("1");
		return 0;
	}
	
	int ans = 1;
	for(int i = 1; i <= b; i ++)
	{
		if(1000000000/ans < a)
		{
			printf("-1");
			return 0;
		}
		ans *= a;
	}
	
	printf("%d", ans);
}