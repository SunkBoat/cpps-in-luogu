#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastread()
{
	ll sym = 1, res = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') sym = -sym;
		ch = getchar();
	}
	
	while(ch >= '0' && ch <= '9')
	{
		res = (res << 1) + (res << 3) + ch - '0';
		ch = getchar();
	}
	
	return res * sym;
}

void fastwrite(ll x)
{
	ll cnt = 0;
	char str[10000];
	while(x)
	{
		str[cnt ++] = (x % 10) + '0';
		x /= 10;
	}
	
	for(ll i = cnt - 1; i >= 0; -- i)
		putchar(str[i]);
		
	puts("");
}

string str;
int orcnt, andcnt;

int pre(int l, int r)
{
//	cout << str.substr(l, r - l + 1) << endl;
	stack<int> st;
	if(l == r) return str[l] - '0';
	int lpos = 0, depth = 0;
	int val1, val2;
	val1 = val2 = -1;
	bool duanlu = false;
	int fuhao = 0;
	for(int i = l; i <= r; ++ i)
	{
		if(str[i] == '0' || str[i] == '1')
		{
			if(depth == 0) 
			{
				if(duanlu)
				{
					duanlu = false;
					continue;
				}
				
				int tmpval = pre(i, i);
				if(val1 == -1) val1 = tmpval;
				else
				{
					val2 = tmpval;
					if(fuhao == 1) val1 |= val2;
					if(fuhao == -1) val1 &= val2;
					if(fuhao == 0)
					{
						val1 = val2;
						val2 = -1;
					}
					
					fuhao = 0;
				}
			}
		}
		
		if(str[i] == '(')
			st.push(i), ++ depth;
			
		if(str[i] == ')')
		{
			int tmp = st.top();
			st.pop();
			-- depth;
			if(duanlu)
			{
				duanlu = false;
				continue;
			}

			if(depth == 0) 
			{
				int tmpval = pre(tmp + 1, i - 1);
				if(val1 == -1) val1 = tmpval;
				else
				{
					val2 = tmpval;
					if(fuhao == 1) val1 |= val2;
					if(fuhao == -1) val1 &= val2;
					if(fuhao == 0)
					{
						val1 = val2;
						val2 = -1;
					}
					
					fuhao = 0;
				}
			}
		}
		
		if(str[i] == '|' && depth == 0)
		{
			if(val1 == 1) 
				duanlu = true, ++ orcnt;
			else 
				fuhao = 1;
		}
		
		if(str[i] == '&' && depth == 0)
		{
			if(val1 == 0) 
				duanlu = true, ++ andcnt;
			else 
				fuhao = -1;
		}
	}
	
	return val1;
}

//void addbrac(int l, int r)
//{
//	stack<int> st;
//	if(l == r) return;
//	int lpos = 0, depth = 0;
//	for(int i = l; i <= r; ++ i)
//	{
//		
//		if(tmpstr[i] == '(')
//			st.push(i), ++ depth;
//			
//		if(tmpstr[i] == ')')
//		{
//			int tmp = st.top();
//			st.pop();
//			-- depth;
//			if(depth == 0) 
//			{
//				addbrac(tmp + 1, i - 1);
//				else
//				{
//					if(fuhao == -1)
//					
//				}
//			}
//		}
//		
//		if(tmpstr[i] == '|' && depth == 0)
//			fuhao = 1;
//		
//		if(tmpstr[i] == '&' && depth == 0)
//			fuhao = -1;
//	}
//	
//	return val1;
//}

signed main()
{
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	cin >> str;
//	addbrac(0, str.length() - 1);
	cout << pre(0, str.length() - 1) << endl;
	cout << andcnt << ' ' << orcnt << endl;
	return 0;
}
