#include<bits/stdc++.h>
using namespace std;
string s;
int s1,s2;
int main()
{
	cin>>s;
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	for(int i=0;i<s.size();i++)	
	{
		int tmp=0;
		if(s[i]=='&'&&s[i-1]=='0')
			s1++;
		else if(s[i]=='|'&&s[i-1]=='1')
			s2++;
	}
	cout<<1<<endl<<s1<<" "<<s2<endl;
	return 0;
}