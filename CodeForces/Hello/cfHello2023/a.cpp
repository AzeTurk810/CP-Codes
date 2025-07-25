/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <string>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1;i < n;i++) {
        if(s[i] == 'R' && s[i - 1] == 'L' ) {
            cout << i << ln;
            return;
        } else if(s[i] == 'L' && s[i - 1] == 'R') {
            cout << 0 << ln;
            return;
        }
    }
    cout << -1 << ln;
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
