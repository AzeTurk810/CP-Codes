/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

ll lcm(ll a , ll b) {
    return a * b / __gcd(a , b);
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n) , b(n) , v(n , 1);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    for(int j = 0;j < n;j++) {
        cin >> b[j];
    }
    for(int i = 0;i < n;i++) {
        v[i] = lcm(v[i] , a[i]);
        int j = i;
        v[j] = lcm(b[j] , v[j]);
    }
    ll l = v[0] , r = v.back();
    for(int i = 1;i < n;i++) {
        l = __gcd(l , v[i]);
        if(l != a[i]) {
            cout << "NO\n";
            return;
        }
    }
    for(int i = n - 1;i >= 0;i--) {
        r = __gcd(r , v[i]);
        if(r != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
