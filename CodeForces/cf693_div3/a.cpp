/*
Telebe of adicto yani AzeTurk810
I see humans but no humanity
*/
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int w , h , n;
    cin >> w >> h >> n;
    ll cnt = 1;
    while(h % 2 == 0) {
        cnt *= 2;
        h /= 2;
    }
    while(w % 2 == 0) {
        cnt *= 2;
        w /= 2;
    }
    bool ok = cnt >= n;
    if(ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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
