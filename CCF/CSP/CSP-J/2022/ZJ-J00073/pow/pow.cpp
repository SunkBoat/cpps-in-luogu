#include <bits/stdc++.h>
using namespace std;

int n , p;
void qpow ()
{
	long long ans = 1 , q = n;
	while ( p )
	{
		if ( p & 1 )
		{
			ans *= q;
		}
		q *= q;
		p >>= 1;
		if ( ans > INT_MAX )
		{
			printf ( "-1" );
			return;
		}
	}
	printf ( "%lld" , ans );
}
int main ()
{
	freopen ( "pow.in" , "r" , stdin );
	freopen ( "pow.out" , "w" , stdout );
	scanf ( "%d %d" , & n , & p );
	qpow ();
	return 0;
}
