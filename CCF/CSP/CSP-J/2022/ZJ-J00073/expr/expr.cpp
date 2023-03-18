#include <bits/stdc++.h>
using namespace std;

string s;
pair <bool , char> st[1000100];
bool vis[1000100] , vi[1000100] , vs[1000100];
int len , top , t , ans1 , ans2;
struct node
{
	bool f;
	char ch;
	int next , prev;
};
node a[1000100] , c[1000100];
void m_toi ()
{
	for ( int i = 0 ; i < len ; i ++ )
	{
		if ( s[i] != '0' && s[i] != '1' )
		{
			a[i + 1].ch = s[i];
			vis[i + 1] = false;
			a[i + 1].next = i + 2;
		}
		else
		{
			a[i + 1].f = s[i] - 48;
			vis[i + 1] = true;
			a[i + 1].next = i + 2;
		}
	}
}
int m_cac ()
{
	for ( int i = 1 ; i <= t ; i = c[i].next )
	{
		if ( ! vs[i] && c[i].ch == '&' )
		{
			int pos = c[i].prev;
			if ( ! c[pos].f )
			{
				c[pos].f = false;
				ans1 ++;
			}
			else
			{
				c[pos].f = c[i + 1].f;
			}
			c[pos].next = i + 2;
			i = pos;
		}
	}
	for ( int i = 1 ; i <= t ; i = c[i].next )
	{
		if ( ! vs[i] && c[i].ch == '|' )
		{
			int pos = c[i].prev;
			if ( c[pos].f )
			{
				c[pos].f = true;
				ans2 ++;
			}
			else
			{
				c[pos].f = c[c[i].next].f;
			}
			c[pos].next = c[c[i].next].next;
			i = pos;
		}
	}
	return c[1].f;
}
int main ()
{
	freopen ( "expr.in" , "r" , stdin );
	freopen ( "expr.out" , "w" , stdout );
	cin.tie ( NULL );
	cout.tie ( NULL );
	cin >> s;
	len = s.size ();
	m_toi ();
	for ( int i = 1 ; i <= len ; i ++ )
	{
		a[i].next = i + 1;
		a[i].prev = i - 1;
	}
	bool f = false;
	for ( int i = 1 ; i <= len ; i = a[i].next )
	{
		if ( ! vis[i] )
		{
			if ( a[i].ch == '&' && ! a[a[i].prev].f && a[a[i].next].next != '(' )
			{
				ans1 ++;
				a[a[i].prev].f = false;
				if ( a[i + 1].ch == '(' )
				{
					int j = i + 2;
					while ( a[j].ch != ')' )
					{
						j ++;
					}
					a[a[i].prev].next = j + 1;
				}
				else
				{
					a[a[i].prev].next = i + 2;
				}
				i --;
				continue;
			}
			if ( a[i].ch == '|' && a[a[i].prev].f && a[a[i].next].next != '&' && a[a[i].next].next != '(' )
			{
				ans2 ++;
				a[a[i].prev].f = true;
				if ( a[i + 1].ch == '(' )
				{
					int j = i + 2;
					while ( a[j].ch != ')' )
					{
						j ++;
					}
					a[a[i].prev].next = j + 1;
				}
				else
				{
					a[a[i].prev].next = i + 2;
				}
				i --;
				continue;
			}
		}
		if ( ! vis[i] && a[i].ch == '(' )
		{
			f = true;
		}
		if ( f )
		{
			if ( a[i].ch != ')' )
			{
				if ( vis[i] )
				{
					st[++ top].first = a[i].f;
					vi[top] = true;
				}
				else
				{
					st[++ top].second = a[i].ch;
					vi[top] = false;
				}
			}
			else
			{
				f = false;
				t = 0;
				while ( top && ( vi[top] || ! vi[top] && st[top].second != '(' ) )
				{
					if ( ! vi[top] )
					{
						c[++ t].ch = st[top].second;
						vs[t] = false;
					}
					else
					{
						c[++ t].f = st[top].first;
						vs[t] = true;
					}
					top --;
				}
				reverse ( c + 1 , c + t + 1 );
				reverse ( vs + 1 , vs + t + 1 );
				for ( int j = 1 ; j <= t ; j ++ )
				{
					c[j].next = j + 1;
					c[j].prev = j - 1;
				}
				top --;
				a[i - t].f = m_cac ();
				a[i - t].next = i + 1;
				vis[i - t] = true;
				i -= t;
			}
		}
	}
	t = 0;
	for ( int i = 1 ; i <= len ; i = a[i].next )
	{
		vs[++ t] = vis[i];
		if ( vis[i] )
		{
			c[t].f = a[i].f;
		}
		else
		{
			c[t].ch = a[i].ch;
		}
		c[t].prev = t - 1;
		c[t].next = t + 1;
	}
	cout << m_cac () << '\n' << ans1 << ' ' << ans2;
	return 0;
}
