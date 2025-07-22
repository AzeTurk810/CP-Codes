/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

ll cntDiv(ll l, ll r, ll d) {
    if (l > r) return 0;
    return r/d - (l-1)/d;
}

void solve() {
    ll l , r;
    cin >> l >> r;
    ll tot = r - l + 1;
    const int n = 4;
    ll p[n] = {2 , 3 , 5 , 7};
    ll res = 0;
    
    for(int mask = 1;mask < (1ll << n);mask++) {
        int cnt = __builtin_popcount(mask);
        ll pr = 1;
        for(int i = 0;i < n;i++) {
            if(mask & (1 << i)) {
                pr *= p[i];
            }
        }
        ll c= cntDiv(l , r , pr);
        if(cnt & 1) 
            res += c;
        else
            res -= c;
    }
    res = tot - res;
    cout << res << ln;
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
