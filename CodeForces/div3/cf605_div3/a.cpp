/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cstdlib>
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18


void solve() {
    int a , b , c;
    cin >> a >> b >> c;
    ll ans = INFll;
    for(int i = -1;i <= 1;i++) {
        for(int j = -1;j <= 1;j++) {
            for(int x = -1;x <= 1;x++) {
                int ac = a + i , bc = b + j , cc = c + x;
                ll cur = abs(ac - bc) + abs(bc - cc) + abs(ac - cc);
                ans = min(ans , cur);
            }
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
