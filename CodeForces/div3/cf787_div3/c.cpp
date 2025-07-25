/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    int zr = 0 , cnt = 0 , cnto = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == '?') {
            cnt ++;
        } else if(s[i] == '1') {
            cnto = 1;
        } else {
            if(zr == 1)
                break;
            zr = 1;
            cnt = 0;
        }
    }
    cout << cnt + zr << ln;
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
