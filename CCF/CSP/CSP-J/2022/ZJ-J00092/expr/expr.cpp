#include<bits/stdc++.h>
using namespace std;
stack<int>q2;
stack<bool>q;
stack<char>q3;
stack<int>q4,q5;
string s;
int k;
void he()
{
	q2.pop();
	int a=q.top();
	q.pop();
	int b=q.top();
	q.pop();
	int sa=q4.top();
	q4.pop();
	int sb=q4.top();
	q4.pop();
	int ssa=q5.top();
	q5.pop();
	int ssb=q5.top();
	q5.pop();
	if (q3.top()=='&')
	{
		q.push(a&b);
		if (b==0) q4.push(sb+1),q5.push(ssb);
		else q4.push(sa+sb),q5.push(ssa+ssb);
	}
	else 
	{
		q.push(a|b); 
		if (b==1) q5.push(ssb+1),q4.push(sb);
		else q5.push(ssa+ssb),q4.push(sa+sb);
	}
	q3.pop();
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='(') k++;
		else if(s[i]==')') k--;
		else 
		{
			if (s[i]=='1'||s[i]=='0'){
				q.push(s[i]-'0'),q4.push(0),q5.push(0);
			}else 
			{
				while(!q2.empty()&&q2.top()>k) he();
				while (!q2.empty()&&q2.top()==k)
				{
					if ((q3.top()==s[i])||(q3.top()=='&'&&s[i]=='|')) he();
					else break;
				}
				q2.push(k);
				q3.push(s[i]);
			}
		}
	}
	while(!q2.empty()) he();
	cout<<q.top()<<endl;
	cout<<q4.top()<<" "<<q5.top()<<endl;
	return 0;
}
