#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

string s;
int a,b,c;


int main(){
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin>>s;
    int n=s.length();
    if(n==3 && s[1]=='&'){
        if(s[0]=='0'||s[2]=='0') b=1;
        else a=1;
        return 0;
    }
    if(n==3&&s[1]=='|'){
        if(s[0]=='1'||s[2]=='1'){
            a=1;
            c=1;
        }
        return 0;
    }
    if(n==5&&s[1]=='&'&&s[3]=='|'){
        if(s[0]=='0'||s[2]=='0') b=1;
        if(s[4]=='1'||s[2]=='1') a=1,c=1;
        return 0;
    }
    if(n==5&&s[1]=='|'&&s[3]=='&'){
        if(s[0]=='1'||s[2]=='1') c=1;
        if(s[4]=='0'||s[2]=='0') a=0,b=1;
        return 0;
    }
    if(n==5&&s[1]=='|'&&s[3]=='|'){
        if(s[0]=='1'||s[2]=='1'||s[3]=1) c=1,a=1;
        return 0;
    }
    if(n==5&&s[1]=='&'&&s[3]=='&'){
        if(s[0]=='0'||s[2]=='0'||s[3]=0) b=1,a=0;
        return 0;
    }
    cout<<a<<' '<<b<<' '<<c;

    return 0;
}

