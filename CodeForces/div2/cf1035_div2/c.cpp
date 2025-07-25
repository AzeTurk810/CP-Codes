/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll
#define B 60



void solve() {
    int n , l , r , k;
    cin >> n >> l >> r >> k;
    if(n & 1) {
        cout << l << ln;
        return;
    }
    if(n == 2) {
        cout << -1 << ln;
        return;
    }
    if(n - 2 >= k) {
        cout << l << ln;
        return;
    } 
    int lb = -1;
    for(int i = 60; i >= 0;i--) {
        if((1LL) & (l >> i)) {
            lb = i + 1;
            break;
        }
    }
    if(r < (1LL << lb)) {
        cout << -1 << ln;
        return;
    }
    cout << (1LL << lb) << ln;
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
