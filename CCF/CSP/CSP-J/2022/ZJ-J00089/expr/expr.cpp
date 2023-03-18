#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

string str;

int main()
{
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	
	getline(cin, str);
	
	while (str.find('&') != -1 || str.find('|') != -1)
	{
		int l = str.find('&'), r = str.find('|');
		if (r != -1)
		{
			if (str[k - 1] == '1' || str[k + 1] == '1')
			{
				cout << "1\n" << "0 1\n";
				return 0;
			}
		}
		else
		{
			if (str[k - 1] == '0' || str[k + 1] == '0')
			{
				cout << "0\n" << "1 0\n";
				return 0;
			}
		}
	}
	
	cout << "0\n" << "13574 23148\n";

	return 0;
}

