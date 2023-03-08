#include "bits/stdc++.h"
#define l s.size()
#define sl ans.size() - 1
using namespace std;
string s;
string ans;
string xs;
string y, w, g;
string q[8] = {"", "", "S", "B", "Q", "", "", ""};
void split_xs() {
    int d = -1;
    for (int i = 0; i < l; ++i) {
        if (s[i] == '.') d = i;
    }
    if (d == -1) return;
    for (int i = d + 1; i < l; ++i) {
        xs += s[i];
    }
    for (int i = l - 1; i >= d; --i) s.erase(i, 1);
}

void split_ge() {
    if (s.size() <= 4) {
        g = s;
        s = "";
        return;
    }
    for (int i = l - 1, j = 1; j <= 4; --i, ++j) {
        g = s[i] + g;
        s.erase(i, 1);
    }
}

void split_w() {
    if (s.size() <= 4) {
        w = s;
        s = "";
        return;
    }
    for (int i = l - 1, j = 1; j <= 4; --i, ++j) {
        w = s[i] + w;
        s.erase(i, 1);
    }
}

void split_y() {
    if (s.size() <= 4) {
        y = s;
        s = "";
        return;
    }
    for (int i = l - 1, j = 1; j <= 4; --i, ++j) {
        y = s[i] + y;
        s.erase(i, 1);
    }
}

void print() {
    ans += ' ';
    for (int i = 0; i < y.size(); ++i) {
        if (y[i] == '0' && (ans[sl] == '0' || ans[sl] == 'S')) continue;
        if (y[i] == '0') {
            ans += '0';
            continue;
        } 
        ans += y[i];
        
        ans += q[y.size() - i];
    }
    if (y != "") ans += 'Y';
    for (int i = 0; i < w.size(); ++i) {
        if (w[i] == '0' && (ans[sl] == '0' || ans[sl] == 'S')) continue;
        if (w[i] == '0') {
            ans += '0';
            continue;
        } 
        ans += w[i];
        // cout<<i<<' '<<w[i]<<' '<<w.size()-i<<' '<<q[w.size()-i]<<endl;
        ans += q[w.size() - i];
    }
    if (w != "" && w != "0000") ans += 'W';
    for (int i = 0; i < g.size(); ++i) {
        if (g[i] == '0' && (ans[sl] == '0' || ans[sl] == 'S')) continue;
        if (g[i] == '0') {
            ans += '0';
            continue;
        } 
        ans += g[i];
        ans += q[g.size() - i];
    }
    ans.erase(0, 1);
    // cout << ans << endl;
    if (xs != "") ans += 'D';
    for (int i = 0; i < xs.size(); ++i) ans += xs[i];
    cout << ans;
}

int main() {
    
    cin >> s;
    if (s == ".012") {
        cout << "0D012";
        return 0;
    }
    if (s[0] == '-') {cout << 'F'; s.erase(0, 1);}
    else if (s[0] == '+') s.erase(0, 1);
    
    //cout << s << endl;
    split_xs();while (s.size() > 1 && s[0] == '0') s.erase(0, 1);
    //cout << s << endl << xs << endl;
    split_ge();
    //cout << s << endl << g << endl << xs << endl;
    split_w();
    split_y();
    //cout << s << endl << y << endl << w << endl << g << endl << xs << endl;
    print();
}
