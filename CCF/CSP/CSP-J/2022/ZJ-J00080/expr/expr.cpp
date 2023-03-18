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
char s[ 1000005 ] ;
int l , ans1 , ans2 , k ;
int q1[ 1000005 ] , q2[ 1000005 ] , top1 , top2 ;
signed main() {
	freopen("expr.in" , "r" , stdin ) ;
	freopen("expr.out" , "w" , stdout ) ;
	scanf("%s" , s ) ;
	l = strlen( s ) - 1 ;
	For( i , 0 , l ) {
		if( s[ i ] == '0' || s[ i ] == '1' ){
			q1[ ++top1 ] = s[ i ] ;
		}
		if( s[ i ] == '&' || s[ i ] == '|' ){
			q2[ ++top2 ] = s[ i ] ;
		}
		if( s[ i ] == '(' ){
			q2[ ++top2 ] = '(';
		}
		if( s[ i ] == ')' ){
			while( top2 >= 1 && ( q2[ top2 ] == '|' || q2[ top2 ] == '&' ) && top1 >= 2 ){
				if( q2[ top2 ] == '|' ) {
					if( q1[ top1 - 1 ] == '1' ) ans1 ++ ;
					if( q1[ top1 ] == '1' || q1[ top1 - 1 ] == '1') k = 1 ;
					else k = 0 ;
					top1 -- ;
					q1[ top1 ] = k + '0' ;
					top2-- ;
				}
				if( q2[ top2 ] == '&' ){
					if( q1[ top1 - 1 ] == '0' ) ans2 ++ ;
					if( q1[ top1 ] == '0' || q1[ top1 - 1 ] == '0') k = 0 ;
					else k = 1 ;
					top1 -- ;
					q1[ top1 ] = k + '0' ;
					top2-- ;
				}
			}
			top2-- ;
		}
	} 
	while( top2 >= 1 && ( q2[ top2 ] == '|' || q2[ top2 ] == '&' ) && top1 >= 2 ){
		if( q2[ top2 ] == '|' ) {
			if( q1[ top1 - 1 ] == '1' ) ans1 ++ ;
			if( q1[ top1 ] == '1' || q1[ top1 - 1 ] == '1') k = 1 ;
			else k = 0 ;
			top1 -- ;
			q1[ top1 ] = k + '0' ;
			top2-- ;
		}
		if( q2[ top2 ] == '&' ){
			if( q1[ top1 - 1 ] == '0' ) ans2 ++ ;
			if( q1[ top1 ] == '0' || q1[ top1 - 1 ] == '0') k = 0 ;
			else k = 1 ;
			top1 -- ;
			q1[ top1 ] = k + '0' ;
			top2-- ;
		}
	}
	printf("%lld\n%lld %lld" , q1[ top1 ] - '0' , ans2 , ans1 ) ;
	return 0 ;
}