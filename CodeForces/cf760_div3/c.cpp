/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin >> i;
    }
    ll g0 = 0 , g1 = 0;
    for(int i = 0;i < n;i += 2) {
        g0 = gcd(a[i] , g0);
    }
    for(int i = 1;i < n;i += 2) {
        g1 = gcd(g1 , a[i]);
    }
    bool ok0 = true , ok1 = true;
    g0 = max(g0 , 1LL);
    g1 = max(g1 , 1LL);
    for(int i = 0;i < n;i += 2) {
        ok1 &= (a[i] % g1) != 0;
    }
    for(int i = 1; i < n;i += 2) {
        ok0 &= (a[i] % g0) != 0;
    }
    if(ok1) {
        cout << g1 << ln;
    } else if(ok0) {
        cout << g0 << ln;
    } else {
        cout << 0 << ln;
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
