/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

void solve() {
    int n , c;
    cin >> n >> c;
    vector<int> a(n);
    int ans = 0;
    multiset<ll> st;
    vector<int> b(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        st.insert(a[i]);
        if(a[i] > c) {
            b[i] = 0;
        } else {
            ll cur = c / a[i];
            b[i] = ll(log2(cur)) + 1;
        }
    }
    sort(b.begin() , b.end());
    ll cur = 0;
    for(int i = 0;i < n;i++) {
        if(b[i] >= cur + 1) {
            cur ++;
        }
    }
    cout << n - cur << ln;
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
