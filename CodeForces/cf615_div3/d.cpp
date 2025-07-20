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

void solve() {
    int q , x;
    cin >> q >> x;
    int cnt[x];
    for(int i = 0;i < x;i++) {
        cnt[i] = 0;
    }
    int cur = 0 , ans = 0;
    while (q--) {
        int c;
        cin >> c;
        cnt[c % x] ++ ;
        while(cnt[cur]) {
            cnt[cur]--;
            cur++;
            ans++;
            cur %= x;
        }
        cout << ans << ln;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imagin ary
