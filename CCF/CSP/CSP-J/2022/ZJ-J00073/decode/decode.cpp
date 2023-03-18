#include <bits/stdc++.h>
using namespace std;

long long n , a , b;
long long x[1000100] , y[1000100] , k;
void ys ()
{
	int len = sqrt ( n );
	for ( register int i = 1 ; i <= len ; i ++ )
	{
		if ( ! ( n % i ) )
		{
			x[++ k] = i;
			y[k] = n / i;
		}
	}
}
int main ()
{
	freopen ( "decode.in" , "r" , stdin );
	freopen ( "decode.out" , "w" , stdout );
	int t;
	scanf ( "%d" , & t );
	while ( t -- )
	{
		k = 0;
		scanf ( "%d %d %d" , & n , & a , & b );
		int cnt = a * b;
		ys ();
		bool f = false;
		for ( register int i = 1 ; i <= k ; i ++ )
		{
			int ans = ( x[i] - 1 ) * ( y[i] - 1 ) + 1;
			if ( ans == cnt )
			{
				f = true;
				printf ( "%d %d\n" , x[i] , y[i] );
				break;
			}
		}
		if ( ! f )
		{
			printf ( "NO\n" );
		}
	}
	return 0;
}
