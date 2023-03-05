#include<bits/stdc++.h>
using namespace std;

string a;
bool flag = false;

int main()
{
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	
	cin >> a;
	
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == '&')
		{
			flag = true;
			break;
		}
		if(a[i] == '|')
		{
			flag = false;
			break;
		}
	}
	
	if(flag)
	{
		bool k = false;
		for(int i = 0; i < a.size(); i++)
			if(a[i] == '0')
			{
				cout << "0" << endl;
				k = true;
				break;
			}
		
		if(!k)
		{
			cout << "1" << endl;
			cout << "0 0" << endl;
			return 0;
		}
		
		int cnt = 0, ans = 0;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] == '(') cnt++;
			if(a[i] == '0')
			{
				ans++;
				
				for(i; i < a.size(); i++)
				{
					if(a[i] == ')') cnt--;
					if(cnt == 0) break;
				}
			}
		}
		
		cout << ans << " 0" << endl;
	}
	else
	{
		bool k = false;
		for(int i = 0; i < a.size(); i++)
			if(a[i] == '1')
			{
				cout << "1" << endl;
				k = true;
				break;
			}
		
		if(!k)
		{
			cout << "0" << endl;
			cout << "0 0" << endl;
			return 0;
		}
		
		int cnt = 0, ans = 0;
		for(int i = 0; i < a.size(); i++)
		{
			if(a[i] == '(') cnt++;
			if(a[i] == '1')
			{
				ans++;
				
				int tmp = 0;
				for(i; i < a.size(); i++)
				{
					if(a[i] == ')') cnt--;
					if(cnt == 0) break;
				}
			}
		}
		
		cout << "0 " << ans << endl;
	}
	
	return 0;
}