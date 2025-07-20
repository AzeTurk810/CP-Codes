/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll 

void solve() {
    int  a , b , x , y;
    cin >> a >> b >> x >> y;
    if(a - 1 > b) {
        cout << -1 << ln;
        return;
    }
    if(a - 1 == b && !(a & 1)) {
        cout << -1 << ln;
        return;
    }
    if(a - 1 == b) {
        cout << y << ln;
        return;
    }
    int ans = 0;
    while(a != b) {
        if(x < y) {
            ans += x;
            a++;
        } else if(bool(a & 1) == 0) {
            a++;
            ans += y;
        } else {
            ans += x;
            a++;
        }
    }
    cout << ans << ln;
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
