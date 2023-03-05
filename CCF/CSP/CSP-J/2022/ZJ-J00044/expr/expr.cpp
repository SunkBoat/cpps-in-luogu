#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    // freopen("expr.in", "r", stdin);
    // freopen("expr.out", "w", stdout);
    string s;
    cin>>s;
    if(s[1]=='&'){
        cout<<(s[0]=='1'&&s[1]=='1')<<endl;
        if(s[0]=='0') cout<<"1 0";
        else cout<<"0 0";
    }else{
        cout<<(s[0]=='1'||s[1]=='1')<<endl;
        if(s[0]=='1') cout<<"0 1";
        else cout<<"0 0";
    }
    return 0;
}