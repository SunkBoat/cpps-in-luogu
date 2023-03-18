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
int jdz( int num ) {
	if( num < 0 ) return -num ;
	else return num ;
}
struct node{ 
	int xi , yi ;
} t[ 505 ] ;
bool cmp( node x1 , node x2 ) {
	if( x1.xi != x2.xi ) return x1.xi < x2.xi ;
	else return x1.yi < x2.yi ;
}
int f[ 505 ][ 105 ] , n , k , ans = -1 ;
int dis( int a1 , int a2 ) {
	return jdz( jdz( t[ a1 ].xi - t[ a2 ].xi ) + jdz( t[ a1 ].yi - t[ a2 ].yi ) - 1 ) ;
}
signed main() { 
	freopen("point.in" , "r" , stdin ) ;
	freopen("point.out" , "w" , stdout ) ;
	n = read() ;
	k = read() ;
	memset( f , -0x3f , sizeof f ) ;
	For( i , 1 , n ){
		t[ i ].xi = read() ;
		t[ i ].yi = read() ;
		f[ i ][ 0 ] = 1 ;
	}
	sort( t + 1 , t + 1 + n , cmp ) ;
	For( i , 1 , n ) {
		For( j , i + 1 , n )
			if( t[ j ].xi >= t[ i ].xi && t[ j ].yi >= t[ i ].yi ){
				int r = dis( i , j ) ;
				For( p , 0 , k - r )
					if( f[ i ][ p ] >= 0 )
						f[ j ][ p + r ] = max( f[ j ][ p + r ] , f[ i ][ p ] + 1 ) ;
			}
	}
	For( i , 1 , n )
		For( j , 0 , k )
			ans = max( ans , f[ i ][ j ] ) ;
	printf("%lld" , ans + k ) ;
	return 0 ;
}