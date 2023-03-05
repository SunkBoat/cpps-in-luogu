#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("expr.in","r",stdin);
	//freopen("expr.out","w",stdout);
	int x1=0,x2=0;
	string a;
	cin>>a;
	cout<<1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0'&&a[i+1]=='&')
			x1++;
		if(a[i]=='1'&&a[i+1]=='|'&&a[i-1]!='(')
			x2++;
	}
	cout<<x1<<" "<<x2;
	return 0;
}