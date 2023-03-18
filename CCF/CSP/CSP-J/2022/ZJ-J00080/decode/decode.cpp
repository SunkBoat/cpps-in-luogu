#include<bits/stdc++.h>
#define int long long 
#define For( i , a , b ) for( register int i = ( a ) ; i <= ( b ) ; ++ i )
#define Rep( i , a , b ) for( register int i = ( a ) ; i >= ( b ) ; -- i )
using namespace std ;
inline int read() {
	int s = 0 ; char ch = getchar() ; bool f = 0 ; 
	for( ; !isdigit( ch ) ; ch = getchar() ) f ^= !( 45 ^ ch ) ;
	for( ; isdigit( ch ) ; ch = getchar() ) s = ( s << 3 ) + ( s << 1 ) + ( ch ^ 48 ) ;
	if( f ) return -s ; return s ;
}
int q ;
int a , m , n , b , c , dt , x1 , x2 ;
signed main() {
	freopen("decode.in" , "r" , stdin ) ;
	freopen("decode.out" , "w" , stdout ) ;
	q = read() ;
	For( i , 1 , q ) {
		a = read() ;
		m = read() ;
		n = read() ;
		b = m * n - a - 2 ;
		c = a ;
		if( b * b - 4 * c < 0 ) {
			printf("NO\n") ;
			continue ;
		}
		dt = sqrt( b * b - 4 * c ) ;
		x1 = ( -b - dt ) / 2 ;
		x2 = ( -b + dt ) / 2 ;
		if( x1 > 0 && x2 > 0 && x1 * x2 == a && ( x1 - 1 ) * ( x2 - 1 ) + 1 == m * n ) 
			printf("%lld %lld\n" , x1 , x2 ) ;
		else printf("NO\n") ;
	}
	return 0 ;
}