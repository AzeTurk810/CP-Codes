/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

map<char , int> rev;

void solve() {
    int cnt[4];
    rev['L'] = 0;
    rev['R'] = 1;
    rev['U'] = 2;
    rev['D'] = 3;
    for(int i = 0;i < 4;i++) {
        cnt[i] = 0;
    }
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0;i < n;i++) {
        cnt[rev[s[i]]]++;
    }
    int lr = min(cnt[0] , cnt[1]) , ud = min(cnt[2] , cnt[3]);
    if(lr == 0 && ud > 0) {
        cout << "2\nUD\n";
        return;
    }
    if(lr > 0 && ud == 0) {
        cout << "2\nLR\n";
        return;
    }
    cout << (lr << 1) + (ud << 1) << ln;
    for(int i = 0;i < lr;i++) {
        cout << "L";
    }
    for(int i = 0;i < ud;i++) {
        cout << "U";
    }
    for(int i = 0;i < lr;i++) {
        cout << "R";
    }
    for(int j = 0;j < ud;j++) {
        cout << "D";
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
