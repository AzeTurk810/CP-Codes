/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

bool comp(const char &a , const char &b) {
    if(a == 'T')
        return true;
    return a < b;
}

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0 ; i < s.size();i++) {
        cnt += (s[i] == 'T');
    }
    for(int i = 0;i < cnt;i++) {
        cout << 'T';
    }
    for(int i = 0;i < s.size();i++) {
        if(s[i] != 'T')
        cout << s[i];
    }
    cout << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary
