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
int n , m , c = 1000000000;
int km( int a , int b ) {
	int res = b , sum = 1 ;
	while( a ) {
		if( a % 2 == 1 ) sum *= res ;
		res = res * res ;
		a /= 2 ;
		if( sum > c || ( a != 0 && res > c ) ) return -1 ;
	}
	return sum ;
}
signed main() {
	freopen("pow.in" , "r" , stdin ) ;
	freopen("pow.out" , "w" , stdout ) ;
	n = read() ; 
	m = read() ;
	printf("%lld" , km( m , n ) ) ;
	return 0 ;
}